#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }

        return s;
    }

    string addBinary2(string a, string b) {
        int la = a.size(), lb = b.size();
        
        string at, bt, c = "";
        if (la >= lb) at = a, bt = b;
        else at = b, bt = a, swap(la, lb);

        cout<<"L = "<<la<<' '<<lb<<endl;
        
        int tmp=0;
        for (int i=0; i<lb; ++i) {
            int bitA = at[la-i-1]-'0', bitB = bt[lb-i-1]-'0';
            int bitC = tmp?(bitA+bitB+1):(bitA+bitB);
            cout<<" ------ "<<bitC<<endl;
            string cut = to_string(bitC%2);
            tmp = bitC/2;
            c = cut + c;
        }
        cout<<" = "<<c<<endl;
        for (int i=lb; i<la; ++i) {
            int bitC = tmp?(at[la-i-1]-'0'+1):(at[la-i-1]-'0');
            cout<<" ------ "<<bitC<<endl;
            string cut = to_string(bitC%2);
            tmp = bitC/2;
            c = cut + c;
        }
        cout<<" = "<<c<<endl;
        if (tmp) c = "1"+c;
        return c;
    }
};

int main(int argc, char const *argv[])
{
    Solution a = Solution();
    cout<<a.addBinary("0", "100");
    return 0;
}