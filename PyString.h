#ifndef __PYSTRING__
#define __PYSTRING__

#include <climits>
#include <vector>
#include <memory>
#include <iostream>


class PyString : public std::string
{
public:
    void printt();
    PyString();
    ~PyString();
    PyString(const char *s);
    PyString(const std::string& s);
    bool py_isdigit() const;
    bool py_isalpha() const;
    bool py_isalnum() const;
    bool py_isspace() const;
    bool py_endswith(const char& chr, int start=0, int end=INT_MAX) const;
    bool py_startswith(const char& chr, int start=0, int end=INT_MAX) const;
    bool py_startswith(std::string substr, int start=0, int end=INT_MAX) const;
    bool py_endswith(std::string substr, int start=0, int end=INT_MAX) const;


    int py_find(const char& chr, int start=0, int end=INT_MAX) const;
    int py_rfind(const char& chr, int start=0, int end=INT_MAX) const;
    int py_count(const char& chr, int start=0, int end=INT_MAX) const;
    int py_count(const std::string& subStr, int start=0, int end=INT_MAX) const;
    int py_find(const std::string& subStr, int start=0, int end=INT_MAX) const;
    int py_rfind(const std::string& subStr, int start=0, int end=INT_MAX) const;

    template <typename... Types>
    PyString py_format(const Types&... args);

    PyString py_strip(const char& chr);
    PyString py_lstrip(const char& chr);
    PyString py_rstrip(const char& chr);

    PyString py_strip(const std::string& str);
    PyString py_lstrip(const std::string& str);
    PyString py_rstrip(const std::string& str);

    PyString py_replace(const char& sourceChr, const char& targetChr, int iMaxReplace=-1) const;
    PyString py_replace(const std::string& sourceStr, const std::string& targetStr, int iMaxReplace=-1) const;

    std::vector<std::string> py_split(const char& chr, int maxsplit=-1) const;
    std::vector<std::string> py_rsplit(const char& chr, int maxsplit=-1) const;
    std::vector<std::string> py_split(const std::string& pattern, int maxsplit=-1) const;
    std::vector<std::string> py_rsplit(const std::string& pattern, int maxsplit=-1) const;


private:
    class Impl;

    std::shared_ptr<Impl> impl_;
    // void getString() {PyString::Impl::getString(this->data());}
};



#endif


