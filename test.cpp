#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <sstream>

#include "tools.cpp"
#include "PyString.cpp"

using namespace std;



std::vector<std::string> splitWithStl(const std::string &str,const std::string &pattern, int maxsplit=-1)
{
    std::vector<std::string> resVec;
    if ("" == str) {
        return resVec;
    }

    std::string strs = str + pattern;

    int patSize = pattern.size();
    // int pos = strs.find(pattern);
    int pos = 0;

    do
    {
        pos = strs.find(pattern);
        std::string x = strs.substr(0,pos);
        resVec.push_back(x);
        if (pos+patSize >= strs.size()) break;
        strs = strs.substr(pos+patSize);
        maxsplit -= 1;
    } while (pos != std::string::npos && maxsplit != 0);
    

    // while (pos != std::string::npos && maxsplit != 0) {
    //     std::string x = strs.substr(0,pos);
    //     resVec.push_back(x);
    //     strs = strs.substr(pos+1);
    //     pos = strs.find(pattern);
    //     maxsplit -= 1;
    // }

 
    if (0 == maxsplit) {
        resVec.push_back(strs.substr(0, strs.size()-pattern.size()));
    }
    return resVec;
}



int main(int argc, char const **argv)
{   
    print(splitWithStl("hello", "el", 6));
    return 0;
}
