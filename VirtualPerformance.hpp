// Created by vonking on 2017/10/14. Copyright (c) 2017 Steven Fung. All rights reserved.

#pragma once

namespace VirtualPerformance {

    class TestVector4_Virtual
    {
    public:
        virtual float GetX() const;
        virtual float SetX( float in );
        virtual float GetY() const;
        virtual float SetY( float in );
        virtual float GetZ() const;
        virtual float SetZ( float in );
        virtual float GetW() const;
        virtual float SetW( float in );
    private:
        float x,y,z,w;
    };

    class TestVector4_Direct
    {
    public:
        float GetX() const;
        float SetX( float in );
        float GetY() const;
        float SetY( float in );
        float GetZ() const;
        float SetZ( float in );
        float GetW() const;
        float SetW( float in );
    private:
        float x,y,z,w;
    };

    class TestVector4_Inline
    {
    public:

        inline float GetX() const
        {
            return x;
        }
        inline float SetX( float in )
        {
            return x = in;
        }

        inline float GetY() const {
            return y;
        }

        inline float SetY(float in) {
            return y = in;
        }

        inline float GetZ() const {
            return z;
        }

        inline float SetZ(float in) {
            return z = in;
        }

        inline float GetW() const {
            return w;
        }

        inline float SetW(float in) {
            return w = in;
        }

    private:
        float x,y,z,w;
    };

};

