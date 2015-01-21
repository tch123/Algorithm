#pragma once
/****************************** Module Header ******************************\
Filename:		VCounter.h
Namespace:		Vonng::VCounter
Digest:		    Counter
Author:			Feng Ruohang
Create:			2015/01/19 12:27
LastModify:		2015/01/19 12:36
\****************************** Module Header ******************************/

#include"Basic.h"
#include<cstring>
#include<string>

namespace Vonng
{
    class VCounter
    {
    private:
        std::string name;
        vint count;
        VCounter(std::string _name, vint _count = 0) :name(_name), count(_count) {};
        inline void operator++() { count += 1; }
        inline void operator++(int) { count += 1; }
        inline vint operator()() { return count; }
    };
}