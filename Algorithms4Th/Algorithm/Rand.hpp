#pragma once
/****************************** Module Header ******************************\
Filename:		Rand.h
Namespace:	    Vonng::Math
Digest:			Provide Rand Wrapper
Author:			Feng Ruohang
\****************************** Module Header ******************************/

#include <random>

namespace Vonng
{
    namespace Math
    {
        //Rand int Class
        template<typename T>
        class Randi
        {
            std::random_device rd;
            std::default_random_engine eng;
            std::uniform_int_distribution<T> dist;

        public:
            Randi(T _lo, T _hi) :eng(rd()), dist(_lo, _hi){};
            T operator()()
            {
                return dist(eng);
            }

            void FillArray(T* data, vint size)
            {
                for (int i = 0; i < size; ++i)
                {
                    data[i] = dist(eng());
                }
            }
        };

        //Rand Real Class
        template<typename T = double>
        class Randf
        {
            std::random_device rd;
            std::default_random_engine eng;
            std::uniform_real_distribution<T> dist;

        public:
            Randf(T _lo, T _hi) :eng(rd()), dist(_lo, _hi){};
            T operator()()
            {
                return dist(eng);
            }

            void FillArray(T* data, vint size)
            {
                for (int i = 0; i < size; ++i)
                {
                    data[i] = dist(eng());
                }
            }
        };
    }
}
