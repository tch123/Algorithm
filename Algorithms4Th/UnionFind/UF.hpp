#pragma once
/****************************** module header ******************************\
module name:    Union Find
project:        Algorithms 4th
author:         Feng Ruohang
email:          fengruohang@outlook.com

c++ implementation of unionfind algorithms:
|quick find | quick union | weighted quick union | WQU with path compression|
API Specification:
T           root(T a);          //find root of given element
bool        find(T a, T b);     //find whether it is connected
void        union(T a, T, b);   //union two element
int         count();            //return the count of component
\***************************************************************************/
#include<map>
#include<vector>
#include<cstdio>

#pragma region "QuickFind UF"

template<typename T>
class QuickFindUF
{
private:
    int              count;              //Number of Component
    std::vector<T>   id;                 //Identify it's Component
public:
    QuickFindUF(int N) :count(N), id(N)
    {
        for (T cnt = 0; cnt < N; ++cnt)
        {
            id[cnt] = cnt;
        }
    };

    inline T    Root(T p)           //Find root of given element
    {
        return id[p];
    }

    inline bool Find(T p, T q)      //Find whether it is Connected
    {
        return Root(p) == Root(q);
    }

    void        Union(T p, T q)    //Union two element
    {
        T pid = Root(p);
        T qid = Root(q);
        if (pid == qid)
        {
            return;
        }
        int size = id.size();
        for (int i = 0; i < size; i++)
        {
            if (id[i] == pid)
            {
                id[i] = qid;
            }
        }
        --count;          //Union Reduce a component
    }

    int         Count()             //Return the Count of Component
    {
        return count;
    }

    std::vector<T>&  Id()                //Get the ID Vector
    {
        return id;
    }
};
#pragma endregion


#pragma region "QuickUnion UF"

template<typename T>
class QuickUnionUF
{
private:
    int              count;              //Number of Component
    std::vector<T>   id;                 //Identify it's Parent
public:
    QuickUnionUF(int N) :count(N), id(N)
    {
        for (T cnt = 0; cnt < N; ++cnt)
        {
            id[cnt] = cnt;
        }
    };

    inline T    Root(T p)           //Find root of given element
    {
        while (p != id[p]) p = id[p];
        return p;
    }

    inline bool Find(T p, T q)      //Find whether it is Connected
    {
        return Root(p) == Root(q);
    }

    void        Union(T p, T q)    //Union two element
    {
        T proot = Root(p);
        T qroot = Root(q);
        if (proot == qroot)
        {
            return;
        }
        //Hang p to q
        id[proot] = qroot;
        --count;
    }

    int         Count()             //Return the Count of Component
    {
        return count;
    }

    std::vector<T>&  Id()                //Get the ID Vector
    {
        return id;
    }
};
#pragma endregion


#pragma region "WeightedQuickUnion UF"%

template<typename T>
class WeightedQuickUnionUF
{
private:
    int              count;              //Number of Component
    std::vector<T>   id;                 //Identify it's Parent
    std::vector<T>   sz;                 //Size of Tree rooted at current element
public:
    WeightedQuickUnionUF(int N) :count(N), id(N), sz(N, 1)
    {
        for (T cnt = 0; cnt < N; ++cnt)
        {
            id[cnt] = cnt;
        }
    };

    inline T    Root(T p)           //Find root of given element
    {
        while (p != id[p]) p = id[p];
        return p;
    }

    inline bool Find(T p, T q)      //Find whether it is Connected
    {
        return Root(p) == Root(q);
    }

    void        Union(T p, T q)    //Union two element
    {
        T proot = Root(p);
        T qroot = Root(q);
        if (proot == qroot)
        {
            return;
        }
        if (sz[proot] < sz[qroot])
        {
            //Hang the small tree p to q
            id[proot] = qroot;
            sz[qroot] += sz[proot];
        }
        else
        {
            id[qroot] = proot;
            sz[proot] += sz[qroot];
        }
        --count;
    }

    int         Count()             //Return the Count of Component
    {
        return count;
    }

    std::vector<T>&  Id()                //Get the ID Vector
    {
        return id;
    }

    std::vector<int>& Sz()
    {
        return sz;
    }
};
#pragma endregion


#pragma region "WeightedQuickUnion with Path Compression UF"

template<typename T>
class WeightedQuickUnionPCUF
{
private:
    int              count;              //Number of Component
    std::vector<T>   id;                 //Identify it's Parent
    std::vector<T>   sz;                 //Size of Tree rooted at current element
public:
    WeightedQuickUnionPCUF(int N) :count(N), id(N), sz(N, 1)
    {
        for (T cnt = 0; cnt < N; ++cnt)
        {
            id[cnt] = cnt;
        }
    };

    inline T    Root(T p)           //Find root of given element
    {
        while (p != id[p])
        {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }

    inline bool Find(T p, T q)      //Find whether it is Connected
    {
        return Root(p) == Root(q);
    }

    void        Union(T p, T q)    //Union two element
    {
        T proot = Root(p);
        T qroot = Root(q);
        if (proot == qroot)
        {
            return;
        }
        if (sz[proot] < sz[qroot])
        {
            //Hang the small tree p to q
            id[proot] = qroot;
            sz[qroot] += sz[proot];
        }
        else
        {
            id[qroot] = proot;
            sz[proot] += sz[qroot];
        }
        --count;
    }

    int         Count()             //Return the Count of Component
    {
        return count;
    }

    std::vector<T>&  Id()                //Get the ID Vector
    {
        return id;
    }

    std::vector<int>& Sz()
    {
        return sz;
    }


};
#pragma endregion


//Warning: 40 Times Cost than Weighted Quick Union UF Algorithm
//Easy To Use

#pragma region "UF"

//Union Allows New Node while New in Find is forbidden
template<typename T>
class UF
{
private:
    int                 count;              //Number of Component
    std::map<T, int>    f;                  //Mapping Function
    std::vector<int>    id;                 //Identify it's Parent
    std::vector<int>    sz;                 //Size of Node rooted at current element

private:
    inline int      New(T newNode)
    {
        int index = id.size();          // Assign a new index
        f[newNode] = index;             // Maintain the Value-index Mapping
        id.push_back(index);            // Assign a new ID
        sz.push_back(1);                // Size is 1 as default
        ++count;
        return index;
    }

    inline int      Root(int p)           //Find root of given element
    {
        while (p != id[p]) p = id[p];
        return p;
    }

public:
    UF() :count(0){};

    inline int      Count()             //Return the Count of Component
    {
        return count;

    }

    inline bool     Find(T p, T q)      //Find whether it is Connected
    {
        //Find Non-Exist Node  is Forbidden
        int pt = f.find(p)->second;
        int qt = f.find(q)->second;
        return Root(pt) == Root(qt);
    }

    void            Union(T p, T q)    //Union two element
    {
        //No Guarantees that p and q already exists in Union
        //New Node Could only be accepted in Union Operation
        typename std::map<T, int>::const_iterator pr = f.find(p);
        int pIndex = pr == f.end() ? New(p) : pr->second;

        typename std::map<T, int>::const_iterator qr = f.find(q);
        int qIndex = qr == f.end() ? New(q) : qr->second;

        int pRoot = Root(pIndex);
        int qRoot = Root(qIndex);
        if (pRoot == qRoot)
        {
            return;
        }
        if (sz[pRoot] < sz[qRoot])
        {
            //Hang the small tree p to q
            id[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        }
        else
        {
            id[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
        --count;
    }

    //Debug Only
    void Print()
    {
        int size = id.size();
        printf("==================Size:%5d|Count:%5d===================\n", size, count);
        printf("K :");
        for (std::map<T, int>::const_iterator i = f.cbegin(); i != f.cend(); ++i)
        {
            printf("%s-", i->first.c_str());
        }

        printf("||\nV :");
        for (std::map<T, int>::const_iterator i = f.cbegin(); i != f.cend(); ++i)
        {
            printf("%d-", i->second);
        }

        printf("||\nID:");
        for (int i = 0; i < size; ++i)
        {
            printf("%d-", id[i]);
        }

        printf("||\nSZ:");
        for (int i = 0; i < size; ++i)
        {
            printf("%d-", sz[i]);
        }
        printf("||\n");
    }
};
#pragma endregion


#pragma region "Dynamic UF"%

template<typename T>
class DynamicUF
{
private:
    int              count;              //Number of Component
    std::vector<T>   id;                 //Identify it's Parent
    std::vector<T>   sz;                 //Size of Tree rooted at current element
public:
    DynamicUF(int N) :count(N), id(N), sz(N, 1)
    {
        for (T cnt = 0; cnt < N; ++cnt)
        {
            id[cnt] = cnt;
        }
    };

    inline T    New()
    {
        int index = id.size();
        id.push_back(index);
        sz.push_back(1);
        ++count;
        return index;
    }

    inline T    Root(T p)           //Find root of given element
    {
        while (p != id[p]) p = id[p];
        return p;
    }

    inline bool Find(T p, T q)      //Find whether it is Connected
    {
        return Root(p) == Root(q);
    }

    void        Union(T p, T q)    //Union two element
    {
        T proot = Root(p);
        T qroot = Root(q);
        if (proot == qroot)
        {
            return;
        }
        if (sz[proot] < sz[qroot])
        {
            //Hang the small tree p to q
            id[proot] = qroot;
            sz[qroot] += sz[proot];
        }
        else
        {
            id[qroot] = proot;
            sz[proot] += sz[qroot];
        }
        --count;
    }

    int         Count()             //Return the Count of Component
    {
        return count;
    }

    std::vector<T>&  Id()                //Get the ID Vector
    {
        return id;
    }

    std::vector<int>& Sz()
    {
        return sz;
    }
};
#pragma endregion
