//Algorithm 4th P150: Random Connection
#include "UF.hpp"
#include <random>
#include <functional>

using namespace std;

//Given The Maximum of element
//Return the required Number of Connection 
int ConnectCount(int N)
{
    WeightedQuickUnionUF<int> uf(N);
    random_device rd;
    default_random_engine eng(rd());
    uniform_int<int> dist(0, N - 1);
    auto gen = std::bind(dist, eng);

    int cnt = 0;
    while (uf.Count() > 1)
    {
        int p = gen();
        int q = gen();
        if (!uf.Find(p, q))
        {
            uf.Union(p, q);
        }
        ++cnt;
    }
    return cnt;
}

double Count(int N, int round = 100)
{
    int sum = 0;
    for (int i = 0; i < round; i++)
    {
        int result = ConnectCount(N);
        sum += result;
        //printf("%d\n", result);
    }
    double avg = sum*1.0 / round;
    //printf("Average: %lf", avg);
    return avg;
}

void UsageCount()
{
    const int N = 1000000;
    const int Round = 1;
    double avg = Count(N, Round);
    printf("\nSize %d has Connection on Avg is %lf\n", N, avg);
}