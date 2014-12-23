/****************************** Module Header ******************************\
Filename:		vMath.cpp
Project:		Vonng::Math
Digest:		    Math Util
Author:			Feng Ruohang
Create:			2014/12/11
LastModify:		2014/12/11
\****************************** Module Header ******************************/

#include "vMath.h"

namespace Vonng
{
	namespace Math
	{
		vint abs(vint x)
		{
			return x < 0 ? -x : x;
		}

		double abs(double x)
		{
			return x < 0 ? -x : x;
		}

		template<typename T>
		T max(T a, T b)
		{
			return b < a ? a : b;
		}

		template<typename T>
		T min(T a, T b)
		{
			return b > a ? a : b;
		}

		//Ass
		bool isPrime(vuint N)
		{
			if (N < 2)
			{
				return false;
			}
			else
			{
				for (size_t i = 2; i * i <= N; ++i)
				{
					if (N % i == 0)
					{
						return false;
					}
				}
				return true;
			}
		}

		//Newton Iteration
		double sqrt(double x)
		{
			if (x < 0)
			{
				return NAN;
			}
			double eps = 1e-15;
			double temp = x;
			while (abs(temp - x / temp) > eps  * temp)
			{
				temp = (x / temp + temp) / 2.0;
			}
			return temp;
		}

		double hypotenuse(double a, double b)
		{
			return sqrt(a*a + b*b);
		}

		double harmonicSeries(vuint N)
		{
			double sum = 0.0;
			for (size_t i = 1; i <= N; ++i)
			{
				sum += 1.0 / i;
			}
			return sum;
		}

		vint gcd(vint dividend, vint divisor)
		{
			vint quotient = dividend / divisor;
			vint remainder = dividend % divisor;

			while (remainder)
			{
				dividend = divisor;
				divisor = remainder;
				quotient = dividend / divisor;
				remainder = dividend % divisor;
				
			}
			return divisor;
		}

	}
}



#ifdef _V_DISABLE_DEBUG
#include "UnitTest.h"
#include<cstdio>

TEST_CASE(vMathTest)
{
	printf("The const E is : %lf\n", Vonng::Math::E);
	printf("The const Pi is : %lf\n", Vonng::Math::Pi);

	TEST_ASSERT(Vonng::Math::gcd(100,60) == 20);
}



#endif