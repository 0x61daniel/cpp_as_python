#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <memory>
#include <sstream>

#include "PyString.cpp"
#include "tools.cpp"

using namespace std;

template <class T>
T f(T i)
{
 
    std::cout << "is_integral int:" << std::is_integral<T>::value << std::endl;
    std::cout << "type float:" << std::is_floating_point<T>::value << std::endl;

    std::cout << "type point:" << std::is_pointer<T>::value << std::endl;

    std::cout << "type string: " << std::is_same<T, std::string>::value << std::endl;
    std::cout << "type string: " << std::is_same<T, char>::value << std::endl;

    // static_assert(std::is_integral<T>::value, "Integral required.");  //静态断言(编译时断言检查)
    return i;
}


int main(int argc, char const **argv)
{


    // for(auto elem: range(0, 10, 2)) {
    //         cout << elem << " ";
    // }
    // cout << '\n';


    // std::map<std::string, int> mData = {
    //     {"A", 1},
    //     {"B", 2},
    //     {"c", 3}
    // };
    // // mData.insert(make_pair(1.2,2));
    // print(mData);


    // print(std::vector<char> {'A', 'B', 'C', 'D'});
    // print(std::vector<std::string> {"AB", "CD", "EF"});
    // print(std::vector<int> {1,2,3,4,5});
    // print(std::vector<double> {1.1, 2.2, 3.3, 4.4, 5.5});
    // print(std::vector<float> {1.1, 2.2, 3.3, 4.4, 5.5});

    // PyString str = "hello world";
    // cout << "find:" << str.py_find('l', 4) << endl;
    // cout << "find:" << str.py_find("ll") << endl;
    // cout << "find:" << str.py_find("ll", 3) << endl;
    // cout << "rfind:" << str.py_rfind('l') << endl;


    // cout << "count:" << str.py_count('l') << endl;
    // cout << "count:" << str.py_count("ll") << endl;


    // cout << "startswith:" << str.py_startswith('l') << endl;
    // cout << "startswith:" << str.py_startswith("ll",2) << endl;
    // cout << "startswith:" << str.py_endswith('l') << endl;
    // cout << "endswith" << str.py_endswith("ll",0, -1) << endl;

    
    // cout << str.replace(str.begin(), str.begin() + 3, 4, 'a') << endl;
    // cout << str.replace(0, 5, "A") << endl;
    // cout << str.py_replace('o', 'l', 1) << endl;
    // cout << str.py_replace("world", "python") << endl;


    // PyString str1 = "llello worll";
    // cout << "strip:" << str1.py_strip('l') << endl;
    // cout << "strip:" << str1.py_lstrip('l') << endl;
    // cout << "strip:" << str1.py_rstrip('l') << endl;
    // cout << "strip:" << str1.py_strip("l") << endl;
    // cout << "strip:" << str1.py_lstrip("ll") << endl;
    // cout << "strip:" << str1.py_rstrip("ll") << endl;
    


    

    PyString str = "llhello worlldll";
    // print(str.py_split('l'));
    // print(str.py_split('l', 2));
    // print(str.py_split("ll"));
    // print(str.py_split("ll",2));


    // print(str.py_rsplit('l'));
    // print(str.py_rsplit('l', 2));
    // print(str.py_rsplit("ll"));
    // print(str.py_rsplit("ll",2));
    // print(str.py_rsplit("lll"));

    //不支持占位符标识{0} {1}
    // cout << FormatString(" world!", "hello", 3.14) << endl;
    // cout << FormatString("{} world!", "hello", 10) << endl;
    // cout << FormatString("{} world! {}", "hello", "true") << endl;
    // cout << FormatString("{} world! PI is {}", "hello", 3.14) << endl;
    // std::string st = "ll";
    // cout << PyString("hello {}").py_format(st) << endl;
    // cout << PyString("hello {} {}").py_format("world", 3.15) << endl;




    

    // cout << isalpha('c') << endl;
    // cout  << str.py_isalpha() << endl;
    // cout  << str.py_isdigit() << endl;
    // cout  << str.py_isalnum() << endl;
    // cout  << str.py_isspace() << endl;
    // cout << str << endl;



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
