#pragma once
/****************************** Module Header ******************************\
Filename:		Basic.h
Namespace:		Vonng
Digest:			Basic data type and useful content definition
Author:			Feng Ruohang
Create:			2014/11/18 23:23
LastModify:		2014/11/18 23:36
\****************************** Module Header ******************************/
#include"Basic.h"

namespace Vonng
{
    namespace Algorithm
    {
        namespace Search
        {
            //Return the rank of given key in head[0..size-1]. Using BSearch Approach
            //-1 Stand for Not Found
            template<typename T>
            vint binarySearch(T* first, T* last, const T key)
            {
                vint mid;
                vint lo = 0;
                vint hi = last - first + 1;
                while (lo <= hi)
                {
                    mid = (lo + hi) / 2;
                    if (key == first[mid])
                    {
                        return mid;
                    }
                    else
                    {
                        if (key < first[mid])
                        {
                            hi = mid - 1;
                        }
                        else
                        {
                            lo = mid + 1;
                        }
                    }
                }
                return -1;
            }

            template<typename T>
            vint linearSearch(T* first, T* last, const T key)
            {
                for (T* cur = first; cur != last; cur++)
                {
                    if (key == *cur)
                    {
                        return cur - first;
                    }
                }
                return -1;
            }
        }
    }
}