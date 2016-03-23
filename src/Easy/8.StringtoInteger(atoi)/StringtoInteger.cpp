#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class Solution {
public:
    int myAtoi2(string str) {
        if (str=="") return 0;
        istringstream ss(str);
        int ans;
        ss >> ans;
        return ans;
    }
    
    int myAtoi(string str) {
        if (str=="") return 0;
        bool sign = 1;
        int i=0;
        long long res = 0;
        while (isspace(str[i])) i++;
        if (str[i]=='+'||str[i]=='-') sign=(str[i++]=='-')?0:1; // 1:pos, 0:neg
        while (i<str.size()) {
            if (!isdigit(str[i])) break;
            res = res*10+int(str[i++]-'0');
            if (res>INT_MAX) return sign?INT_MAX:INT_MIN;
        }
        return sign?res:0-res;
    }
};

int main(int argc, char const *argv[])
{

    Solution AX = Solution();
    string a = "9223372036854775809";

    cout<<AX.myAtoi(a)<<endl;

    return 0;
}