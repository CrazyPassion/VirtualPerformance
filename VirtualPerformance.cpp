// Created by vonking on 2017/10/14. Copyright (c) 2017 Steven Fung. All rights reserved.

#include "VirtualPerformance.hpp"
using namespace VirtualPerformance;

float TestVector4_Virtual::GetX() const
{
    return x;
}
float TestVector4_Virtual::SetX( float in )
{
    return x = in;
}

float TestVector4_Virtual::GetY() const {
    return y;
}

float TestVector4_Virtual::SetY(float in) {
    return y = in;
}

float TestVector4_Virtual::GetZ() const {
    return z;
}

float TestVector4_Virtual::SetZ(float in) {
    return z = in;
}

float TestVector4_Virtual::GetW() const {
    return w;
}

float TestVector4_Virtual::SetW(float in) {
    return w = in;
}

float TestVector4_Direct::GetX() const
{
    return x;
}
float TestVector4_Direct::SetX( float in )
{
    return x = in;
}

float TestVector4_Direct::GetY() const
{
    return y;
}
float TestVector4_Direct::SetY( float in )
{
    return y = in;
}

float TestVector4_Direct::GetZ() const
{
    return z;
}
float TestVector4_Direct::SetZ( float in )
{
    return z = in;
}

float TestVector4_Direct::GetW() const
{
    return w;
}
float TestVector4_Direct::SetW( float in )
{
    return w = in;
}



