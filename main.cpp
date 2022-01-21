#include <iostream>
#include "submodules/UnorderedRedis/include/unorderdRedis.h"
#include <cassert>
using namespace std;

int main()
{
    {
        UnorderedRedis<std::string,std::string> a;
        a.insert("abc", "b");
        a.insert("string with space", "space space");
        string as = a["string with space"];
        assert(std::string(a["string with space"]) == std::string("space space") );
        a.insert("", "empty string");
        as = static_cast<std::string>(a[""]);
        assert(std::string("empty string") == static_cast<std::string>(a[""]));
        a.insert("a", "b");
        assert(true==a.contains("a"));
    }

    {
        UnorderedRedis<int,int> b;
        b.insert(10, 20);
        b[10] = 20;
        int aaa = b[10];
        assert(20 == b[10]);
    }

    {
       UnorderedRedis<float,float> b;
       b.insert(10.0, 20);
       b[10] = 20;
       int aaa = b[10];
    }

    {
       UnorderedRedis<double,double> b;
       b.insert(10.0, 20);
       b[10.0] = 20;
       int aaa = b[10.0];
    }

}
