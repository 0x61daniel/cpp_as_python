#include <iostream>
#include <vector>
#include <cstring>


std::vector<std::string> __split(const std::string& str, const std::string& delim, int maxsplit, const bool rsplit)
{
    std::vector<std::string> res;
    if(0 == maxsplit){
        res.push_back(str);
        return res;
    }

    if(rsplit){
        std::string::size_type index = 0;
        std::string::size_type last = str.length();
        while(std::string::npos != index and maxsplit != 0){
            index = str.rfind(delim, last);
            res.push_back(str.substr(index+1, last-index));
            last = index - delim.size();
            maxsplit -= 1;
        }
        if(std::string::npos != index){
            res.push_back(str.substr(0, index));
        }
    }else{
        std::string::size_type last, index;
        index = str.find(delim);
        last = 0;
        while(std::string::npos != index and maxsplit != 0)
        {
            res.push_back(str.substr(last, index-last));
            last = index + delim.size();
            index = str.find(delim, last);
            maxsplit -= 1;
        }
        if(last != str.length())
            res.push_back(str.substr(last));
        }
    return res;
}


std::vector<std::string> split(const std::string& str, const std::string& delim, const int maxsplit=-1, const bool rsplit=false){
    return __split(str, delim, maxsplit, rsplit);
}

std::vector<std::string> split(const std::string& str, const std::string& delim, const bool rsplit, const int maxsplit=-1){
    return __split(str, delim, maxsplit, rsplit);
}


std::string strip(const std::string& str, char ch=' ')
{
    //除去str两端的ch字符
    int i = 0;
    while (str[i] == ch)// 头部ch字符个数是 i
        i++;
    int j = str.size() - 1;
    while (str[j] == ch ) //
        j--;
    return str.substr(i, j+1 -i );
}




int main() {

    std::string str = "hello worldl";
    std::vector<std::string> res = split(str, "l", 10);

    for(int i=0; i<res.size(); ++i){
        std::cout << "index:" << i << " val:" << res[i] << " " << res[i].empty() << std::endl;
    }


    // // test();
    // string str = "ds/aaa/2esad/sd2/";
    // int last = 1;    // last = index +1
    // int index = str.find_first_of("/", last);
    // cout << "index: " << index << endl;
    // string subStr = str.substr(last, index-last);

    // cout << subStr << endl;
    // cout << str.rfind("/") << endl;
    // cout << str.substr(0) << endl;

}