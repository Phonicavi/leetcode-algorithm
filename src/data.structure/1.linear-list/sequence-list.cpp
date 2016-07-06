#include <iostream>
using namespace std;

class Vector {
private:
	int size, length;
	int *data;
	void expand() {
		int *old_data = data;
		size *= 2;
		data = new int[size];
		for (int i = 0; i < length; ++i) {
			data[i] = old_data[i];
		}
		delete [] old_data;
	}
public:
	Vector(int input_size=8) {
		size = input_size;
		length = 0;
		data = new int[size];
	}
	~Vector() {
		delete [] data;
	}

	bool insert(int index, int value) {
		if (index < 0 || index > length) {
			return false;
		} else if (length >= size) {
			expand();
		}
		for (int i = length; i > index; --i) {
			data[i] = data[i-1];
		}
		data[index] = value;
		length++;
		return true;
	}
	int search(int value) const {
		for (int i = 0; i < length; ++i) {
			if (value == data[i]) {
				return i;
			}
		}
		return -1;
	}
	bool remove(int index) {
		if (index < 0 || index >= length) {
			return false;
		}
		for (int i = index+1; i < length; ++i) {
			data[index-1] = data[index];
		}
		length--;
		return true;
	}
	void print() const {
		for (int i = 0; i < length-1; ++i) {
			cout << data[i] << " ";
		}
		cout << data[length-1] << endl;
		return ;
	}
	void rotate(int k) {
		k = k%length;
		for (int i = 0; i < k/2; ++i) {
			swap(data[i], data[k-i-1]);
		}
		for (int i = k; i < k+(length-k)/2; ++i) {
			swap(data[i], data[k+length-i-1]);
		}

		// another possible loop
		/*for (int j = 0; j < (length-k)/2; ++j) {
            swap(data[k+j], data[length-j-1]);
        }*/

		for (int i = 0; i < length/2; ++i) {
			swap(data[i], data[length-i-1]);
		}
		return ;
	}

	int getSize() const {
		return size;
	}
	int getLength() const {
		return length;
	}
};


int main()
{
	Vector a(2);
	// cout<<a.getSize()<<endl;
    // cout << a.insert(1, 0) << endl;
    // cout << a.insert(0, 1) << endl;
    // cout << a.insert(2, 1) << endl;
    // cout << a.insert(1, 2) << endl;
    // cout << a.insert(0, 3) << endl;
    // cout << a.search(1) << endl;
    // cout << a.search(4) << endl;

    // cout << a.insert(0, 1) << endl;
    // cout << a.insert(0, 2) << endl;
    // cout << a.remove(1) << endl;
    // cout << a.search(0) << endl;
    // cout << a.search(1) << endl;
	
    // cout << a.insert(0, 1) << endl;
    // cout << a.insert(0, 2) << endl;
    // a.print();
    // cout << a.remove(1) << endl;
    // a.print();
    // cout << a.search(0) << endl;
    // cout << a.search(1) << endl;

    // first input: n k
    // second input: n * nums
    // rotate to left: k
    int n, k, x;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
    	cin >> x;
    	a.insert(a.getLength(), x);
    }

    a.rotate(k);
    a.print();

	return 0;
}