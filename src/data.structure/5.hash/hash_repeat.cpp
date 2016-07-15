#include <iostream>
#include <cstring>
using namespace std;

class HashTable {
private:
    string *elem;
    int size;
public:
    HashTable(int _size=200000):size(_size) {
        elem = new string[size];
        for (int i = 0; i < size; ++i) {
            elem[i] = "";
        }
    }
    ~HashTable() {
        delete [] elem;
    }

    int hash(const string &index) {
        int code = 0;
        for (size_t i = 0; i < index.length(); ++i) {
            code = (code*256+index[i]+128) % size;
        }
        return code;
    }

    bool search(string &index, int &position, int &times) {
        position = hash(index);
        // cout << "hash-code = " << position << endl;
        times = 0;
        while (elem[position] != "" && elem[position] != index) {
            times++;
            if (times > size-1) {
                return false;
            }
            position = (position+1) % size;
        }
        // cout << "collision times = " << times << endl;
        if (elem[position] == index) {
            return true;
        }
        return false;
    }
    int insert(string &index) {
        int position, times;
        if (search(index, position, times)) {
            return 2;
        } else if (times < size/2) {
            elem[position] = index;
            return 1;
        } else {
            recreate();
            return 0;
        }
    }
    void recreate() {
        string *tmp = new string[size];
        for (int i = 0; i < size; ++i) {
            tmp[i] = elem[i];
        }
        int copy_size = size;
        size *= 2;
        delete [] elem;
        elem = new string[size];
        for (int i = 0; i < copy_size; ++i) {
            if (tmp[i] != "") {
                insert(tmp[i]);
            }
        }
        delete [] tmp;
    }
};

int n;
string buffer;

void low(string &str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = tolower(str[i]);
    }
    return ;
}

int main() {

    cin >> n;
    HashTable hashtable;
    
    for (int i = 0; i < n; ++i) {
        cin >> buffer;
        low(buffer);
        int ans = hashtable.insert(buffer);
        // cout << buffer << ": " << ans << endl;
        if (ans == 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}