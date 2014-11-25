/****************************** Module Header ******************************\
Filename:		Matlab.h
Project:		Vonng::Matlab
Digest:			Warpper For Matlab c++ API
Author:			Feng Ruohang
Create:			2014/11/25 22:36
LastModify:		2014/11/25 22:36
\****************************** Module Header ******************************/


#ifndef _V_MATLAB
#define _V_MATLAB

#ifdef NDEBUG
#define __V_DISABLE_ALL_DEBUG_MARCO__
#endif

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS


#include "Matlab.h"
#include "Basic.h"
#include "engine.h"
#include "matrix.h"

constexpr const int buffer_size = 1024;

namespace Vonng
{
    namespace Matlab
    {

        class MatlabHandle
        {
        private:
            Engine* ep;
            char buffer[buffer_size];

        public:
            MatlabHandle();
            ~MatlabHandle();
            
            Engine* GetInstance();
            cstr E(cstr cmd);
        };




    }
}

#endif