#ifndef __PYSTRING__
#define __PYSTRING__

#include <climits>
#include <vector>
#include <memory>


class PyString;

class PyString : public std::string
{
public:
    PyString(const char *s) : std::string(s) { };   //委派构造函数
    PyString(const std::string s) : std::string(s) { };
    bool py_isdigit();
    bool py_isalpha();
    bool py_isalnum();
    bool py_isspace();
    bool py_startswith(std::string substr, int start=0, int end=INT_MAX);
    bool py_endswith(std::string substr, int start=0, int end=INT_MAX);

    int py_find(const std::string& subStr, int start=0, int end=INT_MAX);
    int py_rfind(const std::string& subStr, int start=0, int end=INT_MAX);
    int py_count(const std::string& subStr, int start=0, int end=INT_MAX);

    template <typename... Types>
    PyString py_format(const Types&... args);
    PyString py_strip(const std::string str);
    PyString py_lstrip(const std::string str);
    PyString py_rstrip(const std::string str);
    PyString py_replace(const std::string sourceStr, const std::string targetStr, int iMaxReplace=-1);

    std::vector<std::string> py_split(const char delim, int maxsplit=-1, const int rep=false);
    std::vector<std::string> py_rsplit(const char delim, int maxsplit=-1, const int rep=false);


private:
    class Impl;

    std::shared_ptr<Impl> impl_;
    // void getString() {PyString::Impl::getString(this->data());}
};



#endif


