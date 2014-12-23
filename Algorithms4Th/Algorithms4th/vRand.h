/****************************** Module Header ******************************\
Filename:		vRand.h
Project:		Vonng::Math
Digest:		    Random function
Author:			Feng Ruohang
Create:			2014/12/11
LastModify:		2014/12/11
\****************************** Module Header ******************************/


#ifndef _V_RAND
#define _V_RAND

#ifdef NDEBUG
#define _V_DISABLE_DEBUG
#endif

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS


#include "vBasic.h"
#include <cmath>
#include <chrono>
#include <random>



namespace Vonng
{
	namespace Rand
	{
		//Return an Integer
		auto randi()->vint;									//Int from {0,1}
		auto randi(vint hi)->vint;							//Int from [0,hi-1]
		auto randi(vint lo, vint hi)->vint;					//Int from [lo, hi-1]
		auto randi(Interval<vint> range)->vint;
		//Fill an 1-D Integer Array
		auto randi(vint *data, vint sz)->vint*;
		auto randi(vint *data, vint sz, vint hi)->vint*;
		auto randi(vint *data, vint sz, vint lo, vint hi)->vint*;
		auto randi(vint *data, vint sz, Interval<vint> range)->vint*;
		//Fill a  2-D Integer Array
		auto randi(vint **data, vint rowSize, vint colSize)->vint**;
		auto randi(vint **data, vint rowSize, vint colSize, vint hi)->vint**;
		auto randi(vint **data, vint rowSize, vint colSize, vint lo, vint hi)->vint**;
		auto randi(vint **data, vint rowSize, vint colSize, Interval<vint> range)->vint**;
		auto randi(vint **data, Interval<vint> size)->vint**;
		auto randi(vint **data, Interval<vint> size, vint hi)->vint**;
		auto randi(vint **data, Interval<vint> size, vint lo, vint hi)->vint**;
		auto randi(vint **data, Interval<vint> size, Interval<vint> range)->vint**;//Recommend

		//Return an Real
		auto rand()->double;										//Real from [0,1]
		auto rand(double hi)->double;								//Real from [0,hi]
		auto rand(double lo, double hi)->double;					//Real from [lo, hi]
		auto rand(Interval<double> range)->double;
		//Fill an 1-D Real Array
		auto rand(double *data, double sz)->double*;
		auto rand(double *data, double sz, double hi)->double*;
		auto rand(double *data, double sz, double lo, double hi)->double*;
		auto rand(double *data, double sz, Interval<double> range)->double*;
		//Fill a  2-D Real Array
		auto rand(double **data, double rowSize, double colSize)->double**;
		auto rand(double **data, double rowSize, double colSize, double hi)->double**;
		auto rand(double **data, double rowSize, double colSize, double lo, double hi)->double**;		//Base
		auto rand(double **data, double rowSize, double colSize, Interval<double> range)->double**;

		auto rand(double **data, Interval<vint> size)->double**;
		auto rand(double **data, Interval<vint> size, double hi)->double**;
		auto rand(double **data, Interval<vint> size, double lo, double hi)->double**;
		auto rand(double **data, Interval<vint> size, Interval<double> range)->double**;				//Recommend


		//Normal distribution
		auto randn()->double;				//N(0,1)
		auto randn(double sigma)->double;	//N(0,sigma)
		auto randn(double miu, double sigma) ->double;
		auto randn(Interval<double> params)->double;
		//Fill an 1-D Real Array		
		auto randn(double* data, double sz) ->double*;
		auto randn(double* data, double sz, double sigma)->double*;
		auto randn(double* data, double sz, double miu, double sigma)-> double*;
		auto randn(double* data, double sz, Interval<double> params)-> double*;
		//Fill a  2-D Real Array
		auto rand(double **data, double rowSize, double colSize)->double**;
		auto rand(double **data, double rowSize, double colSize, double sigma)->double**;
		auto rand(double **data, double rowSize, double colSize, double miu, double sigma)->double**;
		auto rand(double **data, double rowSize, double colSize, Interval<double> params)->double**;
		auto rand(double **data, Interval<vint> size)->double**;
		auto rand(double **data, Interval<vint> size, double sigma)->double**;
		auto rand(double **data, Interval<vint> size, double miu, double sigma)->double**;
		auto rand(double **data, Interval<vint> size, Interval<double> params)->double**;


		auto flipCoin() -> bool;
		auto bernoulli(double p) -> bool; //P(true) = p
		auto gaussian() -> double; //Eq to randn()
		auto discrete(double p[],vint size) -> vint;

		auto setSeed(unsigned long seed) -> void;

	}
}






#endif