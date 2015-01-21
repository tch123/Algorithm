#pragma once
/****************************** Module Header ******************************\
Filename:		VTimer.h
Namespace:		Vonng
Digest:			High Resolution Timer using WIN32 API
Author:			Feng Ruohang
Create:			2015/01/18 12:23
LastModify:		2015/01/18 12:36
\****************************** Module Header ******************************/
#include<cstdio>
#include "Windows.h"

namespace Vonng
{
    class VTimer
    {
    private:
        LARGE_INTEGER   _freq;
        LARGE_INTEGER   _start;
        LARGE_INTEGER   _stop;
    public:
        explicit VTimer()
        {
            QueryPerformanceFrequency(&_freq);
        }

        inline void start()
        {
            QueryPerformanceCounter(&_start);
        }

        inline void stop()
        {
            QueryPerformanceCounter(&_stop);
        }

        inline double elapse()
        {
            return 1e3 * (_stop.QuadPart - _start.QuadPart) / _freq.QuadPart;
        }

        inline void Show()
        {
            QueryPerformanceCounter(&_stop);
            double temp = 1e3 * (_stop.QuadPart - _start.QuadPart) / _freq.QuadPart;
            printf("Time Elapse: %f \n", temp);
        }
    };
}