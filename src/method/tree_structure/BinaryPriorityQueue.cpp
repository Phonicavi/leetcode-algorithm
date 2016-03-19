class BinaryPriorityQueue
{
public:
	BinaryPriorityQueue(int capacity = 100) {
		array = new int[capacity];
		maxSize = capacity;
		currentSize = 0;
	}
	BinaryPriorityQueue(const int data[], int size);
	~BinaryPriorityQueue() {
		delete [] array;
	}
	
	bool isEmpty() const { return (currentSize == 0);}
	void enQueue(const int& x);
	int deQueue();
	int getHead() const { return array[1]; /* array[0] is not used */}

private:
	int* array;
	int currentSize;
	int maxSize;

	void doubleSpace();
	void buildHeap();
	void percolateDown(int hole);
};


void BinaryPriorityQueue::enQueue(const int& x) {
	if (currentSize == maxSize-1) doubleSpace();

	// percolateUp
	int hole;
	for (hole = ++currentSize; hole > 1&&x < array[hole/2]; hole /= 2) {
		array[hole] = array[hole/2];
	}
	array[hole] = x;
}

int BinaryPriorityQueue::deQueue() {
	int min_item = array[1];
	array[1] = array[currentSize--];
	percolateDown(1);
	return min_item;
}

void BinaryPriorityQueue::percolateDown(int hole) {
	int child;
	int tmp = array[hole];
	for (; hole*2 <= currentSize; hole = child) {
		child = hole*2;
		if (child != currentSize&&array[child+1] < array[child]) child++; // child is the smaller child of the hole
		if (array[child] < tmp) array[hole] = array[child]; // child jumo up to its father's position (since it's smaller)
		else break;
	}
	array[hole] = tmp;
}

void BinaryPriorityQueue::buildHeap() {
	for (int i = currentSize/2; i > 0; --i) {
		percolateDown(i);
	}
}

BinaryPriorityQueue::BinaryPriorityQueue(const int data[], int size):maxSize(size+10), currentSize(size) {
	array = new int[maxSize];
	for (int i = 0; i < size; ++i) 
		array[i+1] = data[i];
	buildHeap();
}

void BinaryPriorityQueue::doubleSpace() {
	int *tmp = array;
	maxSize *= 2;
	array = new int[maxSize];
	for (int i = 0; i <= currentSize; ++i) 
		array[i] = tmp[i];
	delete [] tmp;
}