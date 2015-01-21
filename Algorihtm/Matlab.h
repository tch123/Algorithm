#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include"Basic.h"
#include"engine.h"

namespace Vonng
{
    class Matlab
    {
    private:
        static const int BUFFER_SIZE = 1024;
        Engine* ep;
        char* buffer;
    private:
        //Matlab(Matlab const&);
        //void operator=(Matlab const&);

    public:
        Matlab()
        {
            ep = engOpen("");
            if (!ep)
            {
                fprintf(stderr, "Matlab Engine Initializing Failed!\n");
                abort();
            }
            engSetVisible(ep, false);
            buffer = (char*)malloc((BUFFER_SIZE + 1)*sizeof(char));
            buffer[BUFFER_SIZE] = '\0';
            engOutputBuffer(ep, buffer, BUFFER_SIZE);
            engEvalString(ep, "clear all;");
        }
    public:
        static Matlab& instance()
        {
            static Matlab _instance;
            return _instance;
        }

        Matlab::~Matlab()
        {
            engClose(ep);
            free(buffer);
        }

        inline int eval(const char* cmd)
        {
            return engEvalString(ep, cmd);
        }

        inline const char* result()
        {
            return buffer;
        }

        inline int put(const char* name, mxArray* data)
        {
            return engPutVariable(ep, name, data);
        }

        inline int put(const char* name, double* data, int M)
        {
            mxArray *pm = mxCreateDoubleMatrix(M, 1, mxREAL);
            memcpy((void*)mxGetPr(pm), data, sizeof(double)*M);
            int result = engPutVariable(ep, name, pm);
            mxDestroyArray(pm);
            return result;
        }

        inline int put(const char* name, vint* data, int M)
        {
            mxArray *pm = mxCreateDoubleMatrix(M, 1, mxREAL);
            double* dst = (double*)mxGetPr(pm);
            for (vint i = 0; i < M; i += 1)
            {
                dst[i] = (double)(data[i]);
            }
            int result = engPutVariable(ep, name, pm);
            mxDestroyArray(pm);
            return result;
        }

        inline mxArray* get(const char* name)
        {
            return engGetVariable(ep, name);
        }

        inline void show()
        {
            engSetVisible(ep, true);
        }

        inline void hide()
        {
            engSetVisible(ep, false);
        }

        inline void clear()
        {
            engEvalString(ep, "clear all");
            engEvalString(ep, "close all");
        }

    };
}
