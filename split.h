#ifndef __ENHANCESTRING__
#define __ENHANCESTRING__

#include <climits>

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;


struct VideoInfo
{
    std::string Category;
    std::string Vid;
    std::string Time;
    std::string Name;
    std::vector<std::string> Tag;
    std::string Title;
};


class PyString : public std::string
{
public:
    PyString(const char *s) : std::string(s) { };   //委派构造函数
    PyString(const std::string s) : std::string(s) { };
    bool isdigit();
    bool isalpha();
    bool isalnum();
    bool isspace();
    bool startswith(std::string substr, int beg=0,int end=INT_MAX);
    int find(const std::string& subStr, int beg=0,int end=INT_MAX);
    int count(const std::string& subStr, int beg=0,int end=INT_MAX);
    std::vector<std::string>& split(const char delim, int maxsplit=-1, const int rep=false);
    std::vector<std::string>& rsplit(const char delim, int maxsplit=-1, const int rep=false);

    PyString strip(const std::string str);
    PyString lstrip(const std::string str);
    PyString rstrip(const std::string str);
    PyString replace_py(const std::string sourceStr, const std::string targetStr, int iMaxReplace=-1);

    template <typename... Types>
    PyString format(const Types&... args);
private:
    static std::vector<std::string> flds;
    PyString __strip(const std::string ch, const bool lstrip=false, const bool rstrip=false);
    void BuildFormatString(std::ostringstream& builder, const std::string& fmt_spec, std::string::size_type idx);
    template <typename T, typename... Types>
    void BuildFormatString(std::ostringstream& builder, const std::string& fmt_spec,
                           std::string::size_type idx, const T& first,
                           const Types&... args);
    int ConvertInterval(const int& strSize, const int& subStrSize, int& start, int& end);
    template<typename T>
    bool __split(T& pIndex,  T& pEnd, const char& delim, int maxsplit, const bool rsplit, const bool rep);
    bool __isdigit(const char ch);
    bool __isalpha(const char ch);
    
};



template <class T>
void print(const std::vector<T>& v)
{
    for(auto val: v){
        cout << val << " ";
    }
    cout << endl;
}



template <typename T, typename U, typename V>
std::list<int> range(const T& start, const U& stop, const V& step)
{

    std::cout << "TypeError: range() arg must be int" << endl;
    exit(-1);

    // cout << std::is_same<T, char[6]>::value << endl;
    // cout <<  typeid(T).name()  << endl;
    // cout << typeid(char*).name() << endl;
    std::list<int> coll;
    return coll;
}


std::list<int> range(int end);


std::list<int> range(const int first, const int end, const int step=1);





#endif


