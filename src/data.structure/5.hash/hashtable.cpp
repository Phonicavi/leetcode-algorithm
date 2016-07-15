#include <iostream>
#include <cstring>
using namespace std;


/*
开放地址法：

1. 线性探测法，如果当前的冲突位置为 d，那么接下来几个探测地址为 d + 1，d + 2，d + 3 等，也就是从冲突地址往后面一个一个探测；

2. 线性补偿探测法，它形成的探测地址为 d + m，d + 2 * m，d + 3 * m 等，与线性探测法不同，这里的查找单位不是 1，而是 m，为了能遍历到哈希表里所有位置，我们设置 m 和表长 size 互质；

3. 随机探测法，这种方法和前两种方法类似，这里的查找单位不是一个固定值，而是一个随机序列。

4. 二次探测法，它形成的探测地址为 d + 1^2，d - 1^2，d + 2^2，d - 2^2 等，这种方法在冲突位置左右跳跃着寻找探测地址。


链地址法：

将所有哈希地址相同的结点构成一个单链表，单链表的头结点存在哈希数组里。链地址法常出现在经常插入和删除的情况下。

 */

class HashTable {
private:
	string *elem;
	int size;
public:
	HashTable(int _size=100000):size(_size) {
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
			code = (code*256 + index[i] + 128) % size;
		}
		return code;
	}

	bool search(string &index, int &position, int &times) {
		position = hash(index);
		times = 0;
		while (elem[position] != "" && elem[position] != index) {
			times++;
			if (times < size) {
				position = (position+1) % size;
			} else return false;
		}
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
		string *temp_elem;
		temp_elem = new string[size];
		for (int i = 0; i < size; ++i) {
			temp_elem[i] = elem[i];
		}
		int copy_size = size;
		size *= 2;
		delete [] elem;
		elem = new string[size];
		for (int i = 0; i < size; ++i) {
			elem[i] = "";
		}
		for (int i = 0; i < copy_size; ++i) {
			if (temp_elem[i] != "") {
				insert(temp_elem[i]);
			}
		}
		delete [] temp_elem;
	}
};

int main()
{
	HashTable hashtable(10000);

	// insert
    string buffer;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> buffer;
        int ans = hashtable.insert(buffer);
        if (ans == 0) {
            cout << "insert failed!" << endl;
        } else if (ans == 1) {
            cout << "insert success!" << endl;
        } else if (ans == 2) {
            cout << "It already exists!" << endl;
        }
    }

    // search
    int temp_pos, temp_times;
    cin >> buffer;
    if (hashtable.search(buffer, temp_pos, temp_times)) {
        cout << "search success!" << endl;
    } else {
        cout << "search failed!" << endl;
    }

	return 0;
}