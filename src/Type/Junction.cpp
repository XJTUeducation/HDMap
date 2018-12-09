//
// Created by vincent on 18-10-13.
//

#include "Type/Junction.h"
#include "Type/Map.h"

using namespace hdmap;

unsigned int Junction::JUNCTION_ID = 0;

Junction::Junction()
{
    mJunctionId = JUNCTION_ID++;
}

void Junction::AddConnection(unsigned int _from_road_id, int _from_lane_idx, Pose _from_lane_pose,
                             unsigned int _to_road_id, int _to_lane_idx, Pose _to_lane_pose,
                             double _ctrl_len1, double _ctrl_len2)
{
    std::pair<unsigned int, unsigned int> p(_from_road_id, _to_road_id);
    if(mRoadLinks.find(p) != mRoadLinks.end())
    {
        mRoadLinks[p].AddLaneLink(_from_lane_idx,
                                  _to_lane_idx,
                                  Bezier(_from_lane_pose, _to_lane_pose, _ctrl_len1, _ctrl_len2));
    }
    else
    {
        RoadLink road_link(_from_road_id, _to_road_id);
        road_link.AddLaneLink(_from_lane_idx,
                              _to_lane_idx,
                              Bezier(_from_lane_pose, _to_lane_pose, _ctrl_len1, _ctrl_len2));
        mRoadLinks[p] = road_link;
    }
}

std::vector<std::vector<Pose>> Junction::GetAllPose()
{
    if(mPoses.empty())
        _GenerateAllPose();

    return mPoses;
}

bool Junction::Check(std::pair<unsigned int, unsigned int> links)
{
    return mRoadLinks.find(links) != mRoadLinks.end();
}

std::pair<int, int> Junction::GetLink(std::pair<unsigned int, unsigned int> RoadPair)
{
    auto it = mRoadLinks.find(RoadPair);
    return  it->first;
}

std::vector<Pose> Junction::GetPose(unsigned int from_road_id,
                                    int from_lane_idx,
                                    unsigned int to_road_id,
                                    int to_lane_idx)
{
    return mRoadLinks[{from_road_id, to_road_id}].GetPose(from_lane_idx, to_lane_idx);
}

void Junction::Send(Sender &sender)
{
    if(mVertices.empty()) GenerateVertices();

    std::string text = "Junction[" + std::to_string(mJunctionId) + "]";
    Coor v;

    for(auto & x : mVertices)
    {
        v.x += x.x;
        v.y += x.y;
    }
    if(!mVertices.empty())
    {
        v.x /= mVertices.size();
        v.y /= mVertices.size();
    }
    sender.array.markers.emplace_back(sender.GetText(text, v));
    sender.Send();


    std::vector<Pose> roadlinkRegionPs;
    for(auto & x : mVertices) roadlinkRegionPs.emplace_back(x, Angle(0));
    roadlinkRegionPs.emplace_back(mVertices.front(), Angle(0));

    auto m = sender.GetLineStrip(roadlinkRegionPs, 180.0/255.0, 76.0/255.0, 231.0/255.0, 1.0, 0, 0.15);
    sender.array.markers.emplace_back(m);
    sender.Send();


    std::vector<Pose> junctionRegionPs(mRegionPoses.begin(), mRegionPoses.end());
    junctionRegionPs.emplace_back(mRegionPoses.front());

    m = sender.GetLineStrip(junctionRegionPs,76.0/255.0, 180.0/255.0, 231.0/255.0 , 1.0, 0, 0.15);
    sender.array.markers.emplace_back(m);
    sender.Send();


    for(auto & x : mRoadLinks)
    {
        x.second.Send(sender);
    }
}

void Junction::_GenerateAllPose()
{
    for(auto x : mRoadLinks)
    {
        for(auto y : x.second.mLaneLinks)
        {
            mPoses.emplace_back(y.mReferLine.GetPoses(0.5));
        }
    }
}

RoadLink Junction::GetRoadLink (int rid1, int rid2)
{
    auto it = mRoadLinks.find(std::pair<unsigned int, unsigned int>(rid1, rid2));
    return it->second;
}

boost::property_tree::ptree Junction::ToXML()
{
    pt::ptree p_junc;
    p_junc.add("<xmlattr>.id", mJunctionId);

    if (mVertices.empty()) GenerateVertices();

    /// 受到数据限制， Region数据由road和junction一起提供
    /// GenerateRegionPoses 将在外部进行调用

    pt::ptree p_vec;
    pt::ptree p_v;

    for(auto & v : mVertices)
    {
        p_v.add("<xmlattr>.x", v.x);
        p_v.add("<xmlattr>.y", v.y);
        p_vec.add_child("vertex", p_v);
        p_v.clear();
    }
    p_junc.add_child("vertices", p_vec);

    p_vec.clear();
    for (auto &v : mRegionPoses)
    {
        p_v.add("<xmlattr>.x", v.x);
        p_v.add("<xmlattr>.y", v.y);
        p_vec.add_child("vertex", p_v);
        p_v.clear();
    }
    p_junc.add_child("regionVertices", p_vec);


    for(auto & r : mRoadLinks)
    {
        p_junc.add_child("roadLink", r.second.ToXML());
    }

    return p_junc;
}

void Junction::FromXML(const pt::ptree &p)
{

    for(auto & n : p.get_child(""))
    {
        if(n.first == "<xmlattr>")
        {
            mJunctionId = n.second.get<int>("id");
        }

        if(n.first == "roadLink")
        {
            RoadLink r;
            r.FromXML(n.second);
            mRoadLinks[{r.mFromRoadId, r.mToRoadId}] = r;
        }

        if(n.first == "vertices")
        {
            pt::ptree p_vec = n.second;

            for(auto & t : p_vec.get_child(""))
            {
                if(t.first == "vertex")
                {
                    auto x = t.second.get<double>("<xmlattr>.x");
                    auto y = t.second.get<double>("<xmlattr>.y");
                    mVertices.emplace_back(x, y);
                }
            }
        }

        if (n.first == "regionVertices"){
            pt::ptree p_vec = n.second;

            for(auto & t : p_vec.get_child(""))
            {
                if(t.first == "vertex")
                {
                    auto x = t.second.get<double>("<xmlattr>.x");
                    auto y = t.second.get<double>("<xmlattr>.y");
                    mRegionPoses.emplace_back(x, y, 0);
                }
            }
        }
    }
}

double Junction::Distance(const Coor &v)
{
    double min_dist = 1000000;
    for(auto & ps : GetAllPose())
    {
        for(auto & p : ps)
        {
            double t = sqrt((p.x - v.x)*(p.x - v.x) + (p.y - v.y)*(p.y - v.y));
            if(t < min_dist)
                min_dist = t;
        }
    }
    return min_dist;
}

void Junction::GenerateVertices()
{
    std::map<unsigned int, int> road_lane;  /// 每一条道路最右侧的lane_idx
    std::map<unsigned int, Pose> road_pose; /// 每一条道路最右侧的Pose

    /// 获取每一条道路最右侧的Pose
    for(auto & x : mRoadLinks)
    {
        auto& from_rid = x.second.mFromRoadId;
        auto& to_rid = x.second.mToRoadId;

        for(auto & y : x.second.mLaneLinks)
        {
            if(road_lane.find(from_rid) == road_lane.end() or
                road_lane[from_rid] < y.mFromLaneIndex)
            {
                road_lane[from_rid] = y.mFromLaneIndex;
                road_pose[from_rid] = y.mReferLine.GetStartPose();
            }

            if(road_lane.find(to_rid) == road_lane.end() or
                road_lane[to_rid] < y.mToLaneIndex)
            {
                road_lane[to_rid] = y.mToLaneIndex;
                road_pose[to_rid] = y.mReferLine.GetEndPose();
            }
        }
    }

    std::vector<Coor> vec;
    for(auto & x : road_pose) ///将最右侧的Pose再向右移动3.0米
    {
        auto p = x.second;
        p.Rotate(-90.0);
        p.Translate(3.0, p.GetAngle());
        vec.emplace_back(p.GetPosition());
    }


    auto test = [&vec, this](const Coor &s, const Coor &e) -> bool
    {
        for(auto & t : mVertices)
            if(t == e) return false;

        for(auto & t : vec)
        {
            if(t != s && t != e)
            {
                ///使用叉乘
                double m = (s.x-t.x)*(e.y-t.y) - (e.x-t.x)*(s.y-t.y);

                ///若是在同一直线,则判断t是否在s和e中间
                if(fabs(m) < 0.01)
                {
                    double c1 = (t.x - s.x) * (t.x - e.x);
                    double c2 = (t.y - s.y) * (t.y - e.y);
                    if(c1 < 0 and c2 < 0)
                        return false;
                }
                else if(m < 0)
                    return false;
            }
        }
        return true;
    };

    mVertices.emplace_back(vec.front());

    for(int cnt = 1; cnt < vec.size(); ++cnt)
    {
        for(auto x : vec)
        {
            if(test(mVertices.back(), x))
            {
                mVertices.emplace_back(x);
                break;
            }
        }
    }
}

void Junction::GenerateRegionPoses(hdmap::Map *mapPtr) {

    if (!mRegionPoses.empty()) return;

    std::set<int> to_road_id,from_road_id;

    Coor center_point;

    for(auto & x : mRoadLinks){
        if (to_road_id.count(x.second.mToRoadId)==0)
        {
            to_road_id.insert(x.second.mToRoadId);
            RoadPtr to_road_ptr =  mapPtr->GetRoadPtrById(x.second.mToRoadId);
            auto _front_sec = to_road_ptr->mSecPtrs.front();
            Pose _lane_start_pose = _front_sec->GetLanePoseByIndex(_front_sec->mRightBoundary).front();
            mRegionPoses.emplace_back(_lane_start_pose);
            center_point += _lane_start_pose.GetPosition();
        }
        if (to_road_id.count(x.second.mFromRoadId)==0)
        {
            to_road_id.insert(x.second.mFromRoadId);
            RoadPtr from_road_ptr =  mapPtr->GetRoadPtrById(x.second.mFromRoadId);
            auto _end_sec = from_road_ptr->mSecPtrs.back();
            Pose _lane_end_pose = _end_sec->GetLanePoseByIndex(_end_sec->mRightBoundary).back();
            mRegionPoses.emplace_back(_lane_end_pose);
            center_point += _lane_end_pose.GetPosition();
        }
    }

    center_point /= mRegionPoses.size();
    auto cmp = [center_point, this](Pose &va, Pose &vb) -> bool {
        Angle aa(va.GetPosition() - center_point);
        Angle ab(vb.GetPosition() - center_point);
        return aa.Value() < ab.Value();
    };
    sort(mRegionPoses.begin(), mRegionPoses.end(), cmp);

}

bool Junction::Cover(const Coor &v)
{
    return IGeometry::Cover(mVertices, {v});
}