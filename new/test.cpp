#include "test.h"

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <sstream>
#include <algorithm>




class PyString::Impl
{
    public:
        std::vector<std::string> flds;
        int iii;

    // private:
    int ConvertInterval(const int& strSize, const int& subStrSize, int& start, int& end)
    {
        if (abs(start) > strSize) {               //开始索引大于字符串长度
            return -1;
        }
        if (end < 0 && abs(end) >= strSize) {    //结束负索引大于字符串长度
            return -1;
        }

        /*统一转化为正索引*/
        if (INT_MAX == end) {
            end = strSize;
        }
        if (start < 0) {
            start += strSize;
        }
        if (end <0) {
            end  += (strSize);
        }
        if (subStrSize > (end-start) ) {
            return -1;
        }
        return 0;
    }


    int __find(const std::string& str, const std::string& subStr, int start, int end, bool rfind)
    {
        // std::string str = this->data();
        int strSize = str.size();
        int subStrSize = subStr.size();
        if (this->ConvertInterval(strSize, subStrSize, start, end) == -1) {
            return -1;
        }

        std::string tempStr = str.substr(start, (end-start));
        if (rfind) {
            return tempStr.rfind(subStr);
        }
        return tempStr.find(subStr);
    }



    bool __isdigit(const char ch) { return (48 <= ch && ch <= 57)? true: false;}
    bool __isalpha(const char ch) { return ((97 <= ch && ch <= 122) || (65 <= ch && ch <= 90))? true: false;}
    PyString __strip(const std::string& str, const std::string pattern, const bool lstrip=false, const bool rstrip=false)
    {

        // std::string str = this->data();
        int i = 0, j = str.size()-1;
        if (lstrip) {
            while (std::string::npos != pattern.find(str[i]))   // while (in(str[i], ch))
                i++;
        }
        if (rstrip) {
            while (std::string::npos != pattern.find(str[j]))
                j--;
        }
        return PyString(str.substr(i, j+1 -i ));
    }




    void BuildFormatString(std::ostringstream& builder, const std::string& fmt_spec, std::string::size_type idx)
    {
        auto count = fmt_spec.size() - idx;
        if (count <= 0) {
            return;
        }

        builder.write(fmt_spec.data() + idx, count);
    }

    template <typename T, typename... Types>
    void BuildFormatString(std::ostringstream& builder, const std::string& fmt_spec,
                           std::string::size_type idx, const T& first, const Types&... args)
    {
        auto pos = fmt_spec.find_first_of("{}", idx);
        if (pos == std::string::npos) {
            return this->BuildFormatString(builder, fmt_spec, idx);
        }

        builder.write(fmt_spec.data() + idx, pos - idx);
        builder << first;
        //处理完一个参数之后，通过递归的方式处理下一个参数
        this->BuildFormatString(builder, fmt_spec, pos + 2, args...);
    }

    template<typename T>
    std::vector<std::string> __split(const std::string& str, T& pIndex,  T& pEnd, const char& delim, int maxsplit, const bool rsplit, const bool rep)
    {
        // if (!this->flds.empty()) {
        //     this->flds.clear();
        // }
        std::vector<std::string> resVec;
        int i = 0;
        // std::string str = this->data();
        std::string buf;
        // if (rsplit) {
        //     auto pIndex = str.rbegin();
        //     auto pEnd = str.rend();
        // } else {
        //     auto pIndex = str.begin();
        //     auto pEnd = str.end();
        // }

        while (pIndex != pEnd and maxsplit != 0){
            // cout  << *pIndex << " ";
            if (*pIndex != delim){
                buf += *pIndex;
            } else if (!rep) {
                if (rsplit){
                    reverse(buf.begin(),buf.end());
                }
                resVec.push_back(buf);
                buf = "";
                maxsplit -= 1;
            } else if (buf.length() > 0) {
                if (rsplit) {
                    reverse(buf.begin(),buf.end());
                }
                resVec.push_back(buf);
                buf = "";
                maxsplit -= 1;
            }
            ++pIndex;
            ++i;
        }


        if (i < str.length()) {
            if (rsplit) {
                resVec.push_back(str.substr(0, str.length()-i));
            } else {
                resVec.push_back(str.substr(i));
            }
        } else if (!buf.empty()) {
            if (rsplit) {
                reverse(buf.begin(),buf.end());
            }
            resVec.push_back(buf);
        } else {
            int index = 0;
            if (rsplit) {
                index = i-1; //this->data.length() -1
            }
            if (str[index] == delim) {
                this->flds.push_back("");
            }
        }
        return resVec;
    }
};

// PyString::PyString() : impl_(std::make_shared<Impl>()) {}

// PyString::~PyString() = default;

// std::vector<std::string> PyString::flds;



inline int PyString::py_find(const std::string& subStr, int start, int end)
{


    return start + this->impl_->__find(this->data(), subStr, start, end, false);
}


inline int PyString::py_rfind(const std::string& subStr, int start, int end)
{
    return start +  this->impl_->__find(this->data(), subStr, start, end, true);
}





inline bool PyString::py_startswith(std::string subStr, int start, int end)
{
    return this->py_find(subStr, start, end) == start? true:false;
}


bool PyString::py_endswith(std::string subStr, int start, int end)
{
    std::string str = this->data();
    int strSize = str.size();
    int subStrSize = subStr.size();
    if (this->impl_->ConvertInterval(strSize, subStrSize, start, end) == -1) {
        return false;
    }

    int idx = this->py_rfind(subStr, start, end);
    return ((idx+subStrSize) == end)? true: false;
}


int PyString::py_count(const std::string& subStr, int start, int end)
{
    std::string str = this->data();
    int strSize = str.size();
    int subStrSize = subStr.size();
    if (this->impl_->ConvertInterval(strSize, subStrSize, start, end) == -1) {
        return 0;
    }

    int pos=0, count=0;
    str = str.substr(start, (end-start));
    while ( (pos = str.find(subStr, pos)) != std::string::npos) {
        ++pos;
        ++count;
    }
    return count;
}





inline PyString PyString::py_strip(const std::string str)
{
    // std::string str = this->data();
    // int i = 0;
    // while (std::string::npos != ch.find(str[i]))   // while (in(str[i], ch))
    //     i++;
    // int j = str.size() - 1;
    // while (std::string::npos != ch.find(str[j]))   //
    //     j--;
    // return PyString(str.substr(i, j+1 -i ));
    // std::cout << "::::" << this->impl_->iii << std::endl;
    return this->impl_->__strip(this->data(), str, true, true);
}


inline PyString PyString::py_lstrip(const std::string str)
{
    // std::string str = this->data();
    // //除去str两端的ch字符
    // int i = 0;
    // while (std::string::npos != ch.find(str[i]))   // while (in(str[i], ch))
    //     i++;
    // return PyString(str.substr(i, str.size() ));
    return this->impl_->__strip(this->data(), str, true);
}


inline PyString PyString::py_rstrip(const std::string str)
{
    // std::string str = this->data();
    // //除去str两端的ch字符
    // int j = str.size() - 1;
    // while (std::string::npos != ch.find(str[j]))   // while (in(str[i], ch))
    //     j--;
    // return PyString(str.substr(0, j+1 ));
    return this->impl_->__strip(this->data(), str, false, true);
}




std::vector<std::string> PyString::py_split(const char delim, int maxsplit, const int rep)
{
    std::vector<std::string> resVec;

    std::string str = this->data();
    if (0 == maxsplit) {
        resVec.push_back(str);
        return resVec;
    }

    auto pIndex = str.begin();
    auto pEnd = str.end();
    resVec = this->impl_->__split(str, pIndex,  pEnd, delim, maxsplit, false, rep);
    // return this->impl_->flds;

    return resVec;
}


std::vector<std::string> PyString::py_rsplit(const char delim, int maxsplit, const int rep)
{
    std::vector<std::string> resVec;

    std::string str = this->data();
    if (0 == maxsplit) {
        resVec.push_back(str);
        return resVec;
    }

    auto pIndex = str.rbegin();
    auto pEnd = str.rend();
    resVec = this->impl_->__split(str, pIndex,  pEnd, delim, maxsplit, true, rep);

    reverse(resVec.begin(), resVec.end());
    return resVec;
}





PyString PyString::py_replace(const std::string sourceStr, const std::string targetStr, int iMaxReplace)
{
    PyString sResult = this->data();

    if (sResult.find(sourceStr) == std::string::npos) {
        return sResult;
    }

    int idx = 0;
    int iSourceLen = sourceStr.size();
    while (iMaxReplace != 0 && sResult.find(sourceStr) != std::string::npos) {
        idx = sResult.find(sourceStr);
        sResult.replace(idx, iSourceLen, targetStr);
        --iMaxReplace;
    }

    return sResult;
}


template <typename... Types>
PyString PyString::py_format(const Types&... args)
{
    std::string fmt_spec = this->data();
    std::ostringstream builder;
    std::string::size_type pos = 0;
    int cnt = 0;
    while((pos = fmt_spec.find_first_of("{}", pos)) != std::string::npos) {
        pos += 2;
        ++cnt;
    }

    if (sizeof...(args) != cnt) {
        std::cout << "{} size: " << cnt << "\targument size: " << sizeof...(args) << std::endl;
        exit(-1);
    }

    this->impl_->BuildFormatString(builder, fmt_spec, 0, args...);
    return PyString(builder.str());
}




bool PyString::py_isdigit()
{
    std::string str = this->data();
    if (0 == str.size()) {
        return false;
    }
    for (auto elem: str) {
        if (not this->impl_->__isdigit(elem)) {
            return false;
        }
    }
    return true;
}


bool PyString::py_isalpha()
{
    std::string str = this->data();
    if (0 == str.size()) {
        return false;
    }
    for (auto elem: str) {
        if (not this->impl_->__isalpha(elem)) {
            return false;
        }
    }
    return true;
}


bool PyString::py_isalnum()
{
    std::string str = this->data();
    if (0 == str.size()) {
        return false;
    }
    for (auto elem: str) {
        if (not( this->impl_->__isalpha(elem) || this->impl_->__isdigit(elem) )) {
            return false;
        }
    }
    return true;
}


bool PyString::py_isspace()
{
    std::string str = this->data();
    if (0 == str.size()) {
        return false;
    }
    for (auto elem: str) {
        if (elem != 32 && elem != 9) {
            return false;
        }
    }
    return true;
}



// PyString PyString::Impl::__strip(const std::string pattern, const bool lstrip, const bool rstrip)
// {
//     std::string str = "gello";
//     int i = 0, j = str.size()-1;
//     if (lstrip) {
//         while (std::string::npos != pattern.find(str[i]))   // while (in(str[i], ch))
//             i++;
//     }
//     if (rstrip) {
//         while (std::string::npos != pattern.find(str[j]))
//             j--;
//     }
//     return PyString(str.substr(i, j+1 -i ));
// }

template <class T>
void print(const std::vector<T>& v)
{
    std::cout << '[';
    for(auto val: v){
        std::cout << '\'' <<  val << "',";
    }
    std::cout  << ']' << std::endl;
}

using namespace std;

int main(int argc, char const *argv[])
{
    PyString str("hello world");
    print(str.py_split('A'));
    // cout << str.py_strip("h") << endl;
    // // cout << str.py_split('l') << endl;
    // cout << str << endl;
    return 0;
}


