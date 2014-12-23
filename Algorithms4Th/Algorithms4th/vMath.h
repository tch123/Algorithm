/****************************** Module Header ******************************\
Filename:		vMath.h
Project:		Vonng::Math
Digest:		    Math Util
Author:			Feng Ruohang
Create:			2014/12/11
LastModify:		2014/12/11
\****************************** Module Header ******************************/


#ifndef _V_MATH
#define _V_MATH

#ifdef NDEBUG
#define _V_DISABLE_DEBUG
#endif

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS


#include "vBasic.h"
#include "cmath"


namespace Vonng
{
	namespace Math
	{
		vint abs(vint x);

		double abs(double x);

		template<typename T> T max(T a, T b);

		template < typename T > T min(T a, T b);

		bool isPrime(vint N);

		double sqrt(double x);	//Newton Iteration

		double hypotenuse(double a, double b);

		double harmonicSeries(vint N);

		vint gcd(vint dividend, vint divisor);

		vint lcm(vint a, vint b);

		const double E = exp(1.0);

		const double Pi = acos(-1.0);

	}
}






#endif