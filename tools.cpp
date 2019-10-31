#include <list>
#include <iostream>
#include <algorithm>


// enum type_code_t
// {
// 	INT = 1,
// 	FLOAT = 2,
// 	POINT = 3,
// 	CHAR = 4,
//     STRING = 5
// };

// static std::map<int, std::string> type_mapping = {
// 	{INT, "int"},
// 	{FLOAT, "float"},
// 	{POINT, "point"},
// 	{CHAR, "char"},
// 	{STRING, "string"},
// };


template <class T>
std::string get_data_type(const T& data)
{
    if(true == std::is_same<T, char>::value) {
        return "char";
    } else if(true == std::is_floating_point<T>::value) {
        return "float";
    } else if(true == std::is_pointer<T>::value) {
        return "point";
    } else if(true == std::is_same<T, std::string>::value) {
        return "string";
    } else if(true == std::is_integral<T>::value) {
        return "int";
    } else {
        return "unknow";
    }
}


template <class T>
char get_full_char(const T & data)
{
    std::string flag = get_data_type(data);
    char cFull;
    if("char" == flag) {
        cFull = '\'';
    } else if("string" == flag) {
        cFull = '"';
    } else {
        cFull = ' ';
    }
    return cFull;
}


template <class T>
void print_data(const T & data, const char & chr = ' ')
{
    if(' ' == chr) {
        std::cout << data;
        return;
    }
    std::cout << chr << data << chr;
}


template <class T>
void print(const std::vector<T>& vdata)
{

    std::cout << '[';
    if(!vdata.size()) {
        std::cout  << ']' << std::endl;
        return;
    };

    char cFull = get_full_char(vdata[0]);
    for(int i = 0; i < vdata.size(); ++i) {
        if(0 == i) {
            print_data(vdata.at(i), cFull);
        } else {
            std::cout << ", ";
            print_data(vdata.at(i), cFull);
        }
    }
    std::cout  << ']' << std::endl;
}


template <class T, class U>
void print(const std::map<T, U>& mData)
{   
    std::cout << '{';
    if(!mData.size()) {
        std::cout << '}' <<std::endl;
        return;
    };

    int idx = 0;
    auto pIndex = mData.begin();
    char cKeyFull = get_full_char(pIndex->first);
    char cValueFull = get_full_char(pIndex->second);
    for(auto elem: mData) {
        if(++idx == 1) {
            print_data(elem.first, cKeyFull);
            std::cout << ':';
            print_data(elem.second, cValueFull);
        } else {
            std::cout << ", ";
            print_data(elem.first, cKeyFull);
            std::cout << ':';
            print_data(elem.second, cValueFull);
        }
    }
    std::cout << '}' << std::endl;
}


// template <typename T, typename U, typename V>
// std::list<int> range(const T& start, const U& stop, const V& step)
// {
//     static_assert(std::is_same<T, int>::value, "TypeError: range() arg must be int");  //静态断言(编译时断言检查)
//     std::cout << "TypeError: range() arg must be int" << std::endl;
//     // exit(-1);

//     // cout << std::is_same<T, char[6]>::value << endl;
//     // cout <<  typeid(T).name()  << endl;
//     // cout << typeid(char*).name() << endl;
//     std::list<int> coll;
//     return coll;
// }


std::list<int> range(const int first, const int end, const int step=1)
{
    std::list<int> coll;
    coll.clear();
    if(0 == step) {
        std::cout << "range() argument 3 must be not zero" << std::endl;
        exit(-1);
    }else if ( first >= end || step < 0) {
        return coll;
    }

    int num = (end-first)/step + ( (end-first)%step!=0?1:0);

    // throw std::logic_error("end must greater than begin.");
    // std::generate_n( std::back_inserter(coll), end-first, [n=first-1]() mutable {return ++n;} );
    std::generate_n( std::back_inserter(coll), num, [&]() -> int {static int n = first-step; n += step; return n;});
    return coll;
}


std::list<int> range(int end)
{
    return range(0, end);
}