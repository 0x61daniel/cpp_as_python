#include <iostream>
#include "PyString.cpp"
#include <list>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;



int main(int argc, char const **argv)
{


    // for(auto elem: range(0, 10, 4)) {
    //         cout << elem << " ";
    //     }




    PyString str = "hello worlld";
    // std::string cppStr = "hello worlld";
    print(str.py_split('l'));

    // std::cout << str << endl;
    // string newStr = str;

    // cout << str.py_find("ll") << endl;
    // cout << str.py_rfind("ll") << endl;
    // cout << str.py_rfind("ll", 0, 2) << endl;
    // cout << str.py_find("ll", 0, 4) << endl;

    // cout << str.py_count("l") << endl;


    // cout << str.py_startswith("ll",2) << endl;
    // cout << str.py_endswith("ll",0, -1) << endl;





    //不支持占位符标识{0} {1}
    // cout << FormatString(" world!", "hello", 3.14) << endl;
    // cout << FormatString("{} world!", "hello", 10) << endl;
    // cout << FormatString("{} world! {}", "hello", "true") << endl;
    // cout << FormatString("{} world! PI is {}", "hello", 3.14) << endl;
    // cout << PyString("hello {}").py_format("world") << endl;
    // cout << PyString("hello {} {}").py_format("world", 3.15) << endl;





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
    // cout << str.py_lstrip("h") << endl;
    // cout << str.py_rstrip("h") << endl;
    // cout << str.py_strip("h") << endl;
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





/*

std::vector<std::string> splitWithStl(const std::string &str,const std::string &pattern)
    	    {
		std::vector<std::string> resVec;
        	if ("" == str)
        	{
            		return resVec;
        	}

        	std::string strs = str + pattern;

        	int pos = strs.find(pattern);
        	int size = strs.size();

        	while (pos != std::string::npos)
        	{
	    		std::string x = strs.substr(0,pos);
            		resVec.push_back(x);
            		strs = strs.substr(pos+1,size);
            		pos = strs.find(pattern);
        	}
		return resVec;
	    }

*/