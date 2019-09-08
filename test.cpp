#include <iostream>
#include "PyString.cpp"
#include <list>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;


int main(int argc, char const **argv)
{

    PyString str = "hello worlld";
    std::string cppStr = "hello worlld";

    // cout << str.find("ll") << endl;
    // cout << str.rfind("ll", 0, 2) << endl;
    // cout << str.find("ll", 0, 4) << endl;

    // cout << count(str, "o") << endl;
    // cout << str.count("ol") << endl;


    cout << str.startswith("ll",2) << endl;
    cout << str.endswith("ll",0, -1) << endl;

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
