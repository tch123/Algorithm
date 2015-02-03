#include "stdafx.h"
#include "VTimer.h"
#include "Algorithm.h"
#include "Rand.hpp"
#include "Matlab.hpp"

using namespace std;
using namespace Vonng;
using namespace Vonng::Math;
using namespace Vonng::Algorithm::Search;

vint dataSize = 0;
vint indexSize = 0;

const vint dataLow = 0;
const vint dataHigh = 1000;
const vint indicesLow = 0;
const vint indicesHigh = 1000;

vint* data;
vint* indices;

const vint ROUND = 10;
vint benchSize[ROUND] = { 100,300,1000,3000,10000,30000 ,100000,300000,1000000 ,3000000 };

namespace Vonng
{
    namespace Test
    {
        void generateTestData(vint N, vint M)
        {
            VTimer vt;
            //Init parameters
            dataSize = N;
            indexSize = M;

            printf("DataSize:%d\n|TestCaseSize:%d\n", dataSize, indexSize);

            //Initializing Test Data
            Randi<vint> rand(dataLow, dataHigh);

            data = new int[dataSize];
            for (vint i = 0; i < dataSize; ++i)
            {
                data[i] = rand();
            }

            Randi<vint> indGen(indicesLow, indicesHigh);
            indices = new int[indexSize];
            for (vint i = 0; i < indexSize; ++i)
            {
                indices[i] = indGen();
            }
            printf("Data Range:[%d,%d],Indices Range[%d,%d]\n", dataLow, dataHigh, indicesLow, indicesHigh);

            //Sort
            printf("Sorting Data\n");
            vt.start();
            std::sort(data, data + dataSize);
            vt.stop();
            printf("Sort Time Elapse:%lf\n", vt.elapse());
        }
        double testBinarySearch()
        {
            //Testing Algorithm
            printf("Binary Search:\n");
            VTimer vt;
            vt.start();
            for (vint i = 0; i < indexSize; i += 1)
            {
                vint result = binarySearch<vint>(data, data + dataSize, indices[i]);
                if (result != -1)
                {
                    assert(indices[i] == data[result]);
                }
            }
            vt.stop();
            double time = vt.elapse();
            printf("Search Elapse DataSize[%d]*IndicesSize[%d]  = %lf\n", dataSize, indexSize, time);
            return  time / indexSize;
        }
        double testLinearSearch()
        {
            //Testing Algorithm
            printf("Linear Search:\n");
            VTimer vt;
            vt.start();
            for (vint i = 0; i < indexSize; i += 1)
            {
                vint result = linearSearch<vint>(data, data + dataSize, indices[i]);
                if (result != -1)
                {
                    assert(indices[i] == data[result]);
                }
            }
            vt.stop();
            double time = vt.elapse();
            printf("Search Elapse DataSize[%d]*IndicesSize[%d]  = %lf\n", dataSize, indexSize, time);
            return  time / indexSize;
        }
        void testSearch()
        {
            double binaryResult[ROUND];
            double linearResult[ROUND];

            for (vint cnt = 0; cnt < ROUND; cnt++)
            {
                generateTestData(benchSize[cnt], 100);
                binaryResult[cnt] = testBinarySearch();
                linearResult[cnt] = testLinearSearch();
            }
            printf("===========Benchmark=========(ms per query)\n");
            printf("DataSize\tLinear  \tBinary\n");
            for (vint i = 0; i < ROUND; i += 1)
            {
                printf("%8d\t%8lf\t%8lf\n", benchSize[i], linearResult[i], binaryResult[i]);
            }

            //Drawing Begin
            cout << "Initializing Matlab Engine" << endl;
            Matlab& m(Matlab::instance());
            m.put("x", benchSize, ROUND);
            m.put("y1", binaryResult, ROUND);
            m.put("y2", linearResult, ROUND);
            string option;
            m.eval("loglog(x,y1,'o-');hold on;loglog(x,y2,'s-');grid on;");
            //Drawing End
            getchar();
            m.clear();
            free(data);
            free(indices);
        }
    }
}