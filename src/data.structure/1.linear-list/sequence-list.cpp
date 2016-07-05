#include <iostream>
using namespace std;

class Vector {
private:
	int size, length;
	int *data;
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
	void expand() {
		int *old_data = data;
		size *= 2;
		data = new int[size];
		for (int i = 0; i < length; ++i) {
			data[i] = old_data[i];
		}
		delete [] old_data;
	}

	int getSize() const {
		return size;
	}
};


int main()
{
	Vector a(2);
	cout<<a.getSize()<<endl;
    cout << a.insert(1, 0) << endl;
    cout << a.insert(0, 1) << endl;
    cout << a.insert(2, 1) << endl;
    cout << a.insert(1, 2) << endl;
    cout << a.insert(0, 3) << endl;

	return 0;
}