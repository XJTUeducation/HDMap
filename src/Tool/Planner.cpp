//
// Created by vincent on 18-10-24.
//

#include "Planner.h"

using namespace hdmap;

Planner::Planner(const Map & map, std::shared_ptr<Sender> _sender) :
    mHDMap(map),
    pSender(_sender)
{}


void Planner::GlobalPlanning()
{
    pStart = mHDMap.Locate(mStartPoint);
    pEnd = mHDMap.Locate(mEndPoint);

    ROS_INFO_STREAM("Start Point: " << pStart->iRoadId << " " << pStart->direction);
    ROS_INFO_STREAM("End   Point: " << pEnd->iRoadId << " " << pEnd->direction);

    std::vector<SubRoadPtr> v;
    v.emplace_back(pStart);
    DFS(pStart, v);
    Evaluate();

    mRecord.curr_idx = 0;
    mRecord.curr_rid = mRouting.front()->iRoadId;
    mRecord.curr_dir = mRouting.front()->direction;

    if(mRecord.curr_idx + 1 < mRouting.size())
    {
        mRecord.next_rid = mRouting[mRecord.curr_idx+1]->iRoadId;
        mRecord.next_dir = mRouting[mRecord.curr_idx+1]->direction;
        mRecord.curr_jid = mRouting[mRecord.curr_rid]->iNextJid;
    }
    else
    {
        mRecord.next_rid = -1;
        mRecord.curr_jid = -1;
    }

}


void Planner::DFS(Planner::SubRoadPtr p_curr, std::vector<Planner::SubRoadPtr> v)
{
    if(p_curr->iRoadId == pEnd->iRoadId and p_curr->direction == pEnd->direction)
    {
        mAllRouting.emplace_back(v);
    }
    else
    {
        for(auto & x : mHDMap.AdjacentRoadInfo(p_curr))
        {
            if(!is_visited[x->iRoadId])
            {
                is_visited[x->iRoadId] = true;
                v.emplace_back(x);
                DFS(x, v);
                v.pop_back();
                is_visited[x->iRoadId] = false;
            }
        }
    }
}


void Planner::Evaluate()
{
    mRouting = mAllRouting.front();
}


void Planner::Send()
{
    for(auto const & r : mRouting)
    {
        r->Send(*pSender);
    }
}
