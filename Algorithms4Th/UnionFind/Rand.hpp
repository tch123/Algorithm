#pragma once
/****************************** Module Header ******************************\
Filename:		Rand.h
Namespace:	    None	
Digest:			Provide Rand Wrapper
Author:			Feng Ruohang
\****************************** Module Header ******************************/

#include <random>
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

};

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
};
