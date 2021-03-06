//
// Created by vincent on 18-10-9.
//

#include "Math/Line.h"

using namespace hdmap;

Line::Line(double _start, Pose _start_pose, Pose _end_pose)
: start_pose(_start_pose),
  end_pose(_end_pose),
  direction({_end_pose.x - _start_pose.x, _end_pose.y - _start_pose.y})
{
    start = _start;
}

double Line::Length()
{
    return start_pose.DistanceFrom(end_pose);
}

Pose Line::GetPose(double ds)
{
    return start_pose.GetTranslation(ds, direction);
}

std::vector<Pose> Line::GeneratePose(double ds)
{
    std::vector<Pose> res;
    double s = 0;
    double len = Length();
    while (true)
    {
        res.emplace_back(GetPose(s));
        s += ds;

        if(s >= len)
        {
            res.emplace_back(GetPose(len));
            break;
        }
    }
    return res;
}
