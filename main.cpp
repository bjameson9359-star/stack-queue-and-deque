/******************************************************************************
Author Benjamin Jameson
Version 1
date of completion 10/11/2026
*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;


class myqueue { // first in first out
private:
	myqueue* head;
	myqueue* next;
	myqueue* tail;
	double data;

public:

	myqueue() {
		data = 0;
		next = nullptr;
		tail = nullptr;
	}

	myqueue(double x, myqueue* n, myqueue* t) {
		data = x;
		next = n;
	}

	myqueue(double x) {
		data = x;
		next = nullptr;
	}


	void push(double x) {
		cout << "adding " << x << " to the queue \n";
		if(tail == nullptr) {
			head = new myqueue(x);
			tail = head;
		}
		else {
			tail -> next = new myqueue(x);
			tail = tail -> next;
		}
	}

	double pop() {
		if(head == nullptr) {
			cout << "myqueue empty" << endl;
			return -1;
		}
		double value =  head -> data;
		myqueue* popable = head;
		head = head -> next;
		cout << "removing value " << value << " from the queue " << endl;
		delete popable;
		return value;
	}

	double peak() {
		return data;
	}

	void print() {
		cout << "queue order is ";
		for(myqueue* i = head; i != nullptr; i = i -> next) {
			cout << i -> peak() << " " ;
		}
		cout << endl;
	}

	void empty() {
		myqueue* current = head;
		while (current != nullptr) {
			myqueue* nextNode = current->next;
			delete current;
			current = nextNode;
		}
		head = nullptr;
	}

};

class myStack { // first in last out

private:
	myStack* first;
	myStack* next;
	double data;

public:

	myStack() {
		data = 0;
		next = nullptr;
	}

	myStack(double x, myStack* n) {
		data = x;
		next = n;
	}
	myStack(double x ) {
		data = x;
		next = nullptr;
	}

	double pop() {
		if(first == nullptr) {
			cout << "myStack empty" << endl;
			return -1;
		}
		double value = first -> data;
		myStack* toRemove = first;
		first = first -> next;
		delete toRemove;
		cout << "removing value " << value << " from the STACK " << endl;
		return value;
	}
	void push(double x) {
		cout << "adding " << x << " to the stack \n";
		first = new myStack(x, first);
	}

	double peak() {
		return data;
	}

	void print() {
		cout << "stack order is ";
		for(myStack* i = first; i != nullptr; i = i -> next) {
			cout << i -> peak() << " " ;
		}
		cout << endl;
	}

	void empty() {
		myStack* current = first;
		while (current != nullptr) {
			myStack* nextNode = current->next;
			delete current;
			current = nextNode;
		}
		first = nullptr;
	}
};

class myDequeue { // either order
private:

	myDequeue* first;
	myDequeue* last;
	double data;
	myDequeue* next;
	myDequeue* previous;

public:

	myDequeue() {
		data = 0;
		next = nullptr;
		previous = nullptr;

	}

	myDequeue(double d,myDequeue* ne, myDequeue* pre ) {
		data = d;
		next = ne;
		previous = pre;

	}

	void addLast(double x) {
		cout << "adding element " << x << " to bottom of list\n";
		myDequeue* newElement = new myDequeue(x, nullptr, last);
		last -> setnext(newElement);
		last = newElement;
	}

	void addFirst(double x) {
		cout << "adding element " << x << " to top of list\n";
		myDequeue* newElement = new myDequeue(x, first, nullptr);
		first -> setpre(newElement);
		first = newElement;
	}

	double removeTop() {
		double temp = first -> getdata();
		cout << "removing top element " << temp << endl;
		first = first -> getnext();
		delete first -> getpre();
		first -> setpre(nullptr);
		return temp;
	}

	double removeBottom() {
		double temp = last -> getdata();
		cout << "removing bottom element " << temp << endl;
		last = last -> getpre();
		delete last -> getnext();
		last -> setnext (nullptr);
		return temp;
	}

	double peakTop() {
		return first -> getdata();
	}

	double peakBottom() {
		return last -> getdata();
	}

	void setfirst(myDequeue* x) {
		first = x;
	}

	void setlast(myDequeue* x) {
		last = x;
	}

	void setnext(myDequeue* x) {
		next = x;
	}

	void setpre(myDequeue* x) {
		previous = x;
	}

	void setdata(double x) {
		data = x;
	}

	myDequeue* getfirst() {
		return first;
	}

	myDequeue* getlast() {
		return last;
	}

	myDequeue* getnext() {
		return next;
	}

	myDequeue* getpre() {
		return previous;
	}

	double getdata() {
		return data;
	}
	void print() {
		cout << "dequeue order is ";
		for(myDequeue* i = first; i != nullptr; i = i -> next) {
			cout << i -> getdata() << " " ;
		}
		cout << endl;
	}

	void empty() {
		myDequeue* current = first;
		while (current != nullptr) {
			myDequeue* nextNode = current->getnext();


			if (current != this) {
				delete current;
			} else {

				current->setnext(nullptr);
				current->setpre(nullptr);
			}

			current = nextNode;
		}
		first = nullptr;
		last = nullptr;
	}

};

class arrayQueue { // fifo
private:
	int head;
	int tail;
	double* queueArray;
	int currentsize;
	int maxCapacity;
public:

	arrayQueue(double x, int size) {
		maxCapacity = size;
		queueArray = new double[maxCapacity];
		queueArray[0] = x;
		head = 0;
		tail = 1;
		currentsize = 1;
	}

	~arrayQueue() {
		delete[] queueArray;
	}

	void push(double x) {
		if( maxCapacity == currentsize) {
			cout << "array full can't add to queue" <<endl;
		}
		else {
			queueArray[tail] = x;
			tail = (tail + 1) % maxCapacity;
			currentsize++;
		}
	}

	double pop() {
		if(currentsize == 0) {
			cout<< "array empty" << endl;
			return -1;
		}
		else {
			double temp = queueArray[head];
			queueArray[head] = 0;
			head = (head + 1) % maxCapacity;
			currentsize--;
			return temp;
		}
	}

	double peak() {
		return queueArray[head];
	}

	void print() {
		if (currentsize == 0) {
			cout << "queue is empty" << endl;
			return;
		}
		cout << "queue order is ";
		int index = head;
		for (int i = 0; i < currentsize; i++) {
			cout << queueArray[index] << " ";
			index = (index + 1) % maxCapacity; // Step through circular buffer safely
		}
		cout << endl;
	}

	// EMPTY METHOD: Resets the state variables tracking the array pointer positions
	void empty() {
		head = 0;
		tail = 0;
		currentsize = 0;
		cout << "queue has been emptied." << endl;
	}

};

class arrayStack { // filo
private:
	int tail;
	double* stackArray;
	int maxsize;

public:

	arrayStack(double x, int size) {
		stackArray = new double[size]();
		stackArray[0] = x;
		tail=1;
		maxsize = size;
	}

	~arrayStack() {
		delete[] stackArray;
	}

	// Disable copying to block secondary pointer crashes
	arrayStack(const arrayStack& other) = delete;
	arrayStack& operator=(const arrayStack& other) = delete;

	void push(double x) {
		if(tail >= maxsize) {
			cout<< "stack full"<< endl;
		}
		else {
			cout << "adding " << x << " to the stack \n";
			stackArray[tail++] = x;
		}

	}

	double pop() {
		if (tail <= 0) {
			cout << "stack empty" << endl;
			return -1;
		}
		else {
			tail--;
			double temp = stackArray[tail];
			stackArray[tail] = 0;
			cout << "removing value " << temp << " from the STACK " << endl;
			return temp;
		}

	}

	double peak() {
		return stackArray[tail - 1];
	}


	void print() {
		cout << "the stack order is ";
		for(int i = 0; i < tail ; i++) {
			cout << stackArray[i] << " ";
		}
		cout << endl;
	}

	void empty() {
		for (int i = 0; i < tail; i++) {
			stackArray[i] = 0;
		}
		tail = 0;
		cout << "The stack has been emptied.\n";
	}

};

class arrayDequeue { //fmlm
private:

	int first;
	int last;
	double* dequeueArray;
	int maxsize;
	int currentsize;

public:

	arrayDequeue(double d, int size) {
		maxsize = size;
		dequeueArray = new double[maxsize]();
		dequeueArray[0] = d;
		first = 0;
		last = 1;

	}

	~arrayDequeue() {
		delete[] dequeueArray;
	}

	void addLast(double x) {
		cout << "adding element " << x << " to bottom of list\n";
		dequeueArray[((last) % maxsize)] = x;
		last++;
		currentsize++;
	}

	void addFirst(double x) {
		cout << "adding element " << x << " to top of list\n";
		if(first == 0) {
			dequeueArray[maxsize] = x;
			first = maxsize;
			currentsize++;
		}
		else {
			dequeueArray[((first - 1) % maxsize)] = x;
			first--;
			currentsize++;
		}
	}

	double removeTop() {
		double temp = dequeueArray[first];
		cout << "removing top element " << temp << endl;
		dequeueArray[((first + 1) % maxsize)] = 0;
		first++;
		currentsize--;
		return temp;
	}

	double removeBottom() {
		if(last == 0) {
			last = maxsize;
			double temp = dequeueArray[last];
			cout << "removing last element " << temp << endl;
			dequeueArray[last] = 0;
			currentsize--;
		}
		else {
			last = ((last - 1) % maxsize);
			double temp = dequeueArray[last];
			cout << "removing last element " << temp << endl;
			dequeueArray[last] = 0;
			currentsize--;
			return temp;
		}
	}

	double peakTop() {
		return dequeueArray[first] ;
	}

	double peakBottom() {
		return dequeueArray[last-1] ;
	}

	void print() {
		cout << "Deque elements (Top to Bottom): ";
		int current = first;
		for (int i = first; i != last; i = (i + 1) % maxsize ) {
			cout << dequeueArray[current] << " ";
			current = (current + 1) % maxsize;
		}
		cout << endl;
	}

	void empty() {
		for (int i = 0; i < maxsize; i++) {
			dequeueArray[i] = 0;
		}
		first = 0;
		last = 0;
		currentsize = 0;
	}


};

int main() {

	//test queue linked list
	cout << "testing linked queue \n\n";
	myqueue* queTesting = new myqueue(20);
	queTesting -> push(22);
	queTesting -> push(42);
	queTesting -> push(77);
	queTesting -> print();
	queTesting -> pop();
	queTesting -> print();
	queTesting -> push(100);
	queTesting -> push(42.43);
	queTesting -> push(-77);
	queTesting -> print();
	queTesting -> empty();
	queTesting -> print();
	delete queTesting;

	//test stack linked list
	cout << "testing linked stack \n\n";
	myStack* stackTesting = new myStack(20);
	stackTesting -> push(22);
	stackTesting -> push(42);
	stackTesting -> push(77);
	stackTesting -> print();
	stackTesting -> pop();
	stackTesting -> print();
	stackTesting -> push(100);
	stackTesting -> push(42.43);
	stackTesting -> push(-77);
	stackTesting -> print();
	stackTesting -> empty();
	stackTesting -> print();
	delete stackTesting;

	//test dequeue linked list
	cout << "testing linked dequeue \n\n";
	myDequeue* dequeueTesting = new myDequeue(20,nullptr,nullptr);
	dequeueTesting -> setfirst(dequeueTesting);
	dequeueTesting -> setlast(dequeueTesting);
	dequeueTesting -> print();
	dequeueTesting -> addFirst(22);
	dequeueTesting -> print();
	dequeueTesting -> addFirst(42);
	dequeueTesting -> print();
	dequeueTesting -> addLast(77);
	dequeueTesting -> print();
	dequeueTesting -> removeTop();
	dequeueTesting -> print();
	dequeueTesting -> addLast(23);
	dequeueTesting -> print();
	dequeueTesting -> removeBottom();
	dequeueTesting -> print();
	dequeueTesting -> empty();
	dequeueTesting -> print();
	delete dequeueTesting;

	//test queue array
	cout << "testing array queue \n\n";
	arrayQueue* testingArrayQueue = new arrayQueue(20,50);
	testingArrayQueue -> push(22);
	testingArrayQueue -> push(42);
	testingArrayQueue -> push(77);
	testingArrayQueue -> print();
	testingArrayQueue -> pop();
	testingArrayQueue -> print();
	testingArrayQueue -> push(100);
	testingArrayQueue -> push(42.43);
	testingArrayQueue -> push(-77);
	testingArrayQueue -> print();
	testingArrayQueue -> empty();
	testingArrayQueue -> print();
	delete testingArrayQueue;

	//test stack array
	cout << "testing array stack \n\n";
	arrayStack* testingArrayStack = new arrayStack(20.2, 40);
	testingArrayStack -> push(22);
	testingArrayStack -> push(42);
	testingArrayStack -> push(77);
	testingArrayStack -> print();
	testingArrayStack -> pop();
	testingArrayStack -> print();
	testingArrayStack -> push(100);
	testingArrayStack -> push(42.43);
	testingArrayStack -> push(-77);
	testingArrayStack -> print();
	testingArrayStack -> empty();
	testingArrayStack -> print();
	delete testingArrayStack;
	//test dequeue array
	cout << "testing array dequeue \n\n";
	arrayDequeue* testingArrayDequeue = new arrayDequeue(20.4, 54);
	testingArrayDequeue -> print();
	testingArrayDequeue -> addFirst(22);
	testingArrayDequeue -> print();
	testingArrayDequeue -> addFirst(42);
	testingArrayDequeue -> print();
	testingArrayDequeue -> addLast(77);
	testingArrayDequeue -> print();
	testingArrayDequeue -> removeTop();
	testingArrayDequeue -> print();
	testingArrayDequeue -> addLast(23);
	testingArrayDequeue -> print();
	testingArrayDequeue -> removeBottom();
	testingArrayDequeue -> print();
	testingArrayDequeue -> empty();
	testingArrayDequeue -> print();
	delete testingArrayDequeue;

	return 0;
}
