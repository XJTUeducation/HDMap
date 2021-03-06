//
// Created by vincent on 18-10-26.
//

#include "Type/Signal.h"
using namespace hdmap;

void Signal::Send(hdmap::Sender &sender)
{
    std::string text = mInfo;
    auto m = sender.GetText(text, {x, y}, 0, 1.0, 0, 1.0, 0.5, 1.0);

//    double w = 0.36;
//    double theta = mDirection.Value();
//    double x0 = x + w/2.0 * std::cos((theta+90.0) / 180.0 * M_PI);
//    double y0 = y + w/2.0 * std::sin((theta+90.0) / 180.0 * M_PI);
//    double x1 = x + w/2.0 * std::cos((theta-90.0) / 180.0 * M_PI);
//    double y1 = y + w/2.0 * std::sin((theta-90.0) / 180.0 * M_PI);
//    auto m1 = sender.GetText("0", {x0, y0}, 0, 0, 1.0, 0.5, 1.0);
//    auto m2 = sender.GetText("1", {x1, y1}, 0, 0, 1.0, 0.5, 1.0);
//    sender.array.markers.emplace_back(m1);
//    sender.array.markers.emplace_back(m2);

    sender.array.markers.emplace_back(m);
    sender.Send();
}

Signal::Signal(double _x, double _y, double _z, Angle dir, std::string _type, std::string _info)
{
    x = _x;
    y = _y;
    z = _z;
    mDirection = dir;
    mType = _type;
    mInfo = _info;
}

boost::property_tree::ptree Signal::ToXML()
{
    pt::ptree p_sig;
    p_sig.add("x", x);
    p_sig.add("y", y);
    p_sig.add("z", z);
    p_sig.add("direction", mDirection.Value());
    p_sig.add("type", mType);
    p_sig.add("info", mInfo);

    return p_sig;
}

void Signal::FromXML(const pt::ptree &p)
{
    x = p.get<double>("x");
    y = p.get<double>("y");
    z = p.get<double>("z");
    auto theta = p.get<double>("direction");
    mDirection = Angle(theta);
    mType = p.get<std::string>("type");
    mInfo = p.get<std::string>("info");
}
