#include "Matlab.h"
#include "Pointer.h"

#include<iostream>

#define and &&
#define or  ||
#define not !

using namespace Vonng;
using namespace Matlab;
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int ix = 0, int iy = 0) :x(ix), y(iy) {};
    int sum() { return x + y; }
};

struct Point3 :public Point
{
    int z;
    Point3(int ix = 0, int iy = 0, int iz = 0) :Point(ix, iy), z(iz) {};
};


int main()
{
    if (true and false)
    {

    }
    //Ptr<Point> pp(new Point(1, 2));
    //Ptr<Point3> pb(new Point3(1, 2, 3));

    //auto result = pp->sum();
    //auto resutl = pp->x;

    //auto pbb = pb.Obj();

    //pp = pb;
    //pp.~Ptr();
    //pb.~Ptr();

}