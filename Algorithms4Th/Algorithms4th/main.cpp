
#define NDEBUG

#include "vBasic.h"
#include "vMath.h"
#include<random>
#include<iostream>
#include<chrono>

using namespace Vonng::Math;
using namespace std;

//const unsigned initRandomSeed = 
//	static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
//static default_random_engine e(initRandomSeed);
//
//
//template<int SZ> 
//auto genRand(double lo, double hi) ->double(&)[SZ]
//{
//	double[SZ] result;
//	uniform_real_distribution u(lo, hi);
//	//result = new double(SZ);
//	for (size_t i = 0; i < SZ; ++i)
//	{
//		result[i] = u(e);
//	}
//	return result;
//}
//
#include<vector>

int main()
{
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(0,9);
	vector<int> inst{1,2,3,4};
	auto x = inst.begin();
	cout << true;
	cout << false;

}