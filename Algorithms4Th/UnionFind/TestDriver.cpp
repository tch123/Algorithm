#define _CRT_SECURE_NO_WARNINGS
#include "UF.hpp"
#include "VTimer.h"
#include <vector>

double RunUF1(int N, std::vector<int> &data)
{
    QuickFindUF<int> uf1(N);
    int dataSize = data.size() / 2;
    Vonng::VTimer vt;

    //Run and Timer
    vt.start();
    for (int i = 0; i < dataSize; i += 2)
    {
        uf1.Union(data[i], data[i + 1]);
    }
    vt.stop();
    return vt.elapse();
}

double RunUF2(int N, std::vector<int> &data)
{
    QuickUnionUF<int> uf2(N);
    int dataSize = data.size() / 2;
    Vonng::VTimer vt;

    //Run and Timer
    vt.start();
    for (int i = 0; i < dataSize; i += 2)
    {
        uf2.Union(data[i], data[i + 1]);
    }
    vt.stop();
    return vt.elapse();
}

double RunUF3(int N, std::vector<int> &data)
{
    WeightedQuickUnionUF<int> uf3(N);
    int dataSize = data.size() / 2;
    Vonng::VTimer vt;

    //Run and Timer
    vt.start();
    for (int i = 0; i < dataSize; i += 2)
    {
        uf3.Union(data[i], data[i + 1]);
    }
    vt.stop();
    return vt.elapse();
}

double RunUF4(int N, std::vector<int> &data)
{
    WeightedQuickUnionPCUF<int> uf4(N);
    int dataSize = data.size() / 2;
    Vonng::VTimer vt;

    //Run and Timer
    vt.start();
    for (int i = 0; i < dataSize; i += 2)
    {
        uf4.Union(data[i], data[i + 1]);
    }
    vt.stop();
    return vt.elapse();
}

double RunUF5(int N, std::vector<int> &data)
{
    UF<int> uf5;
    int dataSize = data.size() / 2;
    Vonng::VTimer vt;

    //Run and Timer
    vt.start();
    for (int i = 0; i < dataSize; i += 2)
    {
        uf5.Union(data[i], data[i + 1]);
    }
    vt.stop();
    return vt.elapse();
}

void  TestUF()
{
    int N = 0;
    scanf("%d", &N);

    QuickFindUF<int> uf1(N);
    QuickUnionUF<int> uf2(N);
    WeightedQuickUnionUF<int> uf3(N);
    WeightedQuickUnionPCUF<int> uf4(N);


    //Data Acquisition
    int p, q;
    std::vector<int> data;
    while (scanf("%d %d", &p, &q) == 2)
    {
        data.push_back(p);
        data.push_back(q);
    }
    printf("Load Complete\n");

    //Total BenchMark for UF1~4 (at tiny size)
    //printf("Total Bench Mark:\n");
    //printf("%8lf\t%8lf\t%8lf\t%8lf\n",
    // RunUF1(N, data),
    // RunUF2(N, data),
    // RunUF3(N, data),
    // RunUF4(N, data));


    //AVG Test of UF3 and UF4 (1,2 is too slow)
    //double avg = 0.0;
    //double sum = 0.0;
    //int round = 20;
    //for (int i = 0; i < round; i++)
    //{
    //    sum += RunUF3(N, data);
    //}
    //avg = sum / round;
    //printf("Run:\t %lf",avg);


    //Single Test

    printf("PC:%lf\n", RunUF3(N, data));
    printf("PC:%lf\n", RunUF4(N, data));
    getchar();
}

void printVector(std::vector<int> &data)
{
    std::vector<int>::iterator head = data.begin();
    std::vector<int>::iterator end = data.end();
    while (head != end)
    {
        printf("%d-", *head++);
    }
    printf("END");
}

void  TestUFStep()
{
    int N = 0;
    scanf("%d", &N);

    //QuickFindUF<int> uf(N);
    //QuickUnionUF<int> uf(N);
    WeightedQuickUnionUF<int> uf(N);
    //WeightedQuickUnionPCUF<int> uf(N);

    //Data Acquisition
    int p, q;
    while (scanf("%d %d", &p, &q) == 2)
    {
        uf.Union(p, q);
        printf("\n=================Component:%d\n", uf.Count());
        printf("ID:");
        printVector(uf.Id());
        printf("\nSZ:");
        printVector(uf.Sz());
    }
    printf("\n===============================\n");
    getchar();
}

