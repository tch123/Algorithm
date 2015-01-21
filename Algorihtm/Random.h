#pragma once
/****************************** Module Header ******************************\
Filename:		Basic.h
Namespace:		Vonng
Digest:			Basic data type and useful content definition
Author:			Feng Ruohang
Create:			2014/11/18 23:23
LastModify:		2014/11/18 23:36
\****************************** Module Header ******************************/

#include<random>
#include<functional>
#include "Basic.h"
//random_device rand_dev;

namespace Vonng
{
    namespace Math
    {
        template<typename T> T* randi(vint N, T min, T max)
        {
            random_device rd;
            default_random_engine eng(rd());
            uniform_int<T> gen(min, max);
            auto r = std::bind(gen, eng);
            T* head = (T*)malloc(sizeof(T)* N);
            for (vint i = 0; i < N; i += 1)
            {
                head[i] = r();
            }
            return head;
        }

        template<typename T> T* randf(vint N, T min, T max)
        {
            random_device rd;
            default_random_engine eng(rd());
            uniform_real<T> gen(min, max);
            auto r = std::bind(gen, eng);
            T* head = (T*)malloc(sizeof(T)* N);
            for (vint i = 0; i < N; i += 1)
            {
                head[i] = r();
            }
            return head;
        }
    }
}