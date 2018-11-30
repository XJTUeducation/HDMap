//
// Created by vincent on 18-10-8.
//

#ifndef HDMAP_ROAD_H
#define HDMAP_ROAD_H

#include "LaneSection.h"
#include "Signal.h"
#include "common.h"
#include <algorithm>

namespace hdmap
{
class Road : public IView, public IXML, IGeometry
{
public:
    static unsigned int ROAD_ID;
    unsigned int mRoadId;
    double mLength;
    int mDirection;

    std::vector<SecPtr> mSecPtrs;
    std::vector<SigPtr> mSigPtrs;

    int mPrevJid;
    int mNextJid;

    Pose mStartPose;
    Pose mEndPose;
    std::vector<Vector2d> mRegionVertices;

    explicit Road(Pose _start_pose = Pose());

    SecPtr AddSection(const Pose & _end_pose, double _ctrl_len1 = 1.0, double _ctrl_len2 = 1.0);

    void AddSignal(double _x, double _y, double _z, Angle dir, std::string _type, std::string _info);

    std::vector<SigPtr> GetSignals();

    int GetPrevJid() { return mPrevJid; }

    int GetNextJid() { return mNextJid; }

    int AdjacentJid(int direction)
    {
        if(direction > 0) return mNextJid;
        else return mPrevJid;
    }

    std::vector<Pose> Trajectory(int begin_lane_idx, int end_lane_idx);

    std::vector<Pose> GetReferenceLinePoses();

    std::vector<Pose> GetRightmostLinePoses();

    double Distance(const Vector2d &v);

    void GenerateRegionVertics();

    std::pair<unsigned int, int> Locate(const Vector2d & v);

    std::vector<std::vector<Pose>> GetLanePosesByDirection(int direction);

    void Send(Sender &sender) override;


public:
    boost::property_tree::ptree ToXML() override;
    void FromXML(const pt::ptree &p) override;
    bool Cover(const Vector2d &v) override;
};
}

#endif //HDMAP_ROAD_H