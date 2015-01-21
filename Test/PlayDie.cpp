#include<random>
#include<cstdio>
#include<functional>

using namespace std;



void simpleDieExp()
{
    const int TIME = 10000000;
    int status[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            status[i][j] = 0;
        }
    }

    random_device rd;
    default_random_engine eng(rd());
    uniform_int<int> dist(0, 5); //0 1 2 3 4 5
    auto gen = std::bind(dist, eng);
    int x = 0;
    int y = 0;
    for (int i = 0; i < TIME; i++)
    {
        status[gen()][gen()] += 1;
    }

    double result[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            result[i][j] = 1.0 * status[i][j] / TIME * 100;
        }
    }
    printf("\t1\t2\t3\t4\t5\t6\t\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t\n", i + 1, result[i][0], result[i][1], result[i][2], result[i][3], result[i][4], result[i][5]);
    }
}


int status[12] = { 0 };
double result[12] = { 0.0 };
void additionExp()
{
    const int TIME = 10000000;

    random_device rd;
    default_random_engine eng(rd());
    uniform_int<int> dist(1, 6); //0 1 2 3 4 5
    auto gen = std::bind(dist, eng);
    int x = 0;
    int y = 0;

    for (int i = 0; i < TIME; i++)
    {
        ++(status[gen() + gen() - 1]);
    }

    for (int i = 0; i < 12; i++)
    {
        result[i] = 1.0 * status[i] / TIME * 100;
    }
    printf("Addition  Frequency\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%d\t%.3f\n", i + 1, result[i]);
    }
}


int playDie()
{
    //simpleDieExp();
    additionExp();
    getchar();

    return 0;
}