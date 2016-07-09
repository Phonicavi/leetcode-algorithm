#include <iostream>
#include <cstring>
using namespace std;

class HashTable {
private:
	string *elem;
	int size;
public:
	HashTable(int _size=100000):size(_size) {
		elem = new string[size];
	}
	~HashTable() {
		delete [] elem;
	}
	int hash(const string &index) {
		int code = 0;
		for (size_t i = 0; i < index.length(); ++i) {
			code = (code*256 + index[i] + 128) % size;
		}
		return code;
	}
};

int main()
{
	HashTable hashtable(10000);
	return 0;
}