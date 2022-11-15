#include<iostream>
using namespace std;
#define ElemType char
#define volume 10

class queue {
public:
	ElemType l[volume];
	int head=0;
	int last=volume-1;
	
	void enqueue(ElemType x) {
		l[(last + 1) % volume] = x;
		last = (last + 1) % volume;
	}//进队列
	void dequeue() {
		l[(head)] = '/0';
		head = (head + 1) % volume;
	}//出队列
	bool IsEmpty() {
		if (head == last) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void show() {
		for (int i = head; i <= last; i++) {
			if (i >= volume) {
				i = i % volume;
			}
			cout << l[i] << ' ';
		}
		cout << endl;
	}
};

int main() {
	queue a;
	a.enqueue('1');
	a.enqueue('2');
	a.enqueue('3');
	a.enqueue('4');
	a.enqueue('5');
	a.enqueue('6');
	a.enqueue('7');
	a.enqueue('8');
	a.enqueue('9');
	a.show();
	a.dequeue();
	a.enqueue('a');
	a.show();

	return 0;
}

