#include <iostream>
#include "split.cpp"
#include <list>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;



// 终止递归函数
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
                       std::string::size_type idx, const T& first,
                       const Types&... args)
{
    auto pos = fmt_spec.find_first_of("{}", idx);
    if (pos == std::string::npos) {
        return BuildFormatString(builder, fmt_spec, idx);
    }

    builder.write(fmt_spec.data() + idx, pos - idx);
    builder << first;
    //处理完一个参数之后，通过递归的方式处理下一个参数
    BuildFormatString(builder, fmt_spec, pos + 2, args...);
}

template <typename... Types>
std::string FormatString(const std::string& fmt_spec, const Types&... args)
{
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

    BuildFormatString(builder, fmt_spec, 0, args...);
    return builder.str();
}



int count(const std::string str, const string targetStr){
    int pos=0, count=0;
    while ( (pos = str.find(targetStr, pos)) != std::string::npos) {
        ++pos;
        ++count;
    }
    
    return count;
}


int main(int argc, char const **argv)
{

    PyString str = "hello worlld";

    cout << str.find("he", 0, 2) << endl;

    cout << count(str, "o") << endl;
    cout << str.count("ol") << endl;

    // cout << str.find(" ", 6) << endl;


    // cout << str.startswith("ll", 2, -10) << endl;

    // for(auto elem: range(0, 10, 4)) {
    //     cout << elem << " ";
    // }



   



    // 不支持占位符标识{0} {1}
    // cout << FormatString(" world!", "hello", 3.14) << endl;
    // cout << FormatString("{} world!", "hello", 10) << endl;
    // cout << FormatString("{} world! {}", "hello", "true") << endl;
    // cout << FormatString("{} world! PI is {}", "hello", 3.14) << endl;
    // cout << PyString("hello {}").format("world") << endl;
    // cout << PyString("hello {} {}").format("world", 3.15) << endl;





    // cout << str.replace(str.begin(), str.begin() + 3, 4, 'a') << endl;
    // cout << str.replace(0, 5, "A") << endl;
    // cout << str.replace_py("l", "A") << endl;



    // cout << isalpha('c') << endl;
    // cout  << str.isalpha() << endl;
    // cout  << str.isdigit() << endl;
    // cout  << str.isalnum() << endl;
    // cout  << str.isspace() << endl;
    // cout << str << endl;

    // PyString str = "hahchhhhhhh";
    // cout << str.lstrip("h") << endl;
    // cout << str.rstrip("h") << endl;
    // cout << str.strip("h") << endl;
    // cout << str << endl;

    // std::string sr = str;
    // cout << sr << endl;

    // auto rev = str.split('h');
    // cout << rev.size() << endl;
    // // print(rev);
    // for(auto elem: rev) {

    //     cout << ":" << elem << endl;
    // }

    return 0;
}
