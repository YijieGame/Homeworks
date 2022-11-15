#include<iostream>
using namespace std;
#define ElemType char

class node {
public:
	ElemType value;
	node* next;
	node* prior;
};

class queue {
public:
	node* head;
	node* last;

	queue() {
		head = NULL;
		last = NULL;
	}
	void enqueue(ElemType x) {
		if (head == NULL) {
			node* p = (node*)malloc(sizeof(node));
			p->value = x;
			head = p;
			last = p;
		}
		else {
			node* p = (node*)malloc(sizeof(node));
			p->value = x;
			last->next = p;
			p->prior = last;
			last = p;
		}
	}//进队 尾插一个节点
	void dequeue() {
		node* p = head;
		head->next->prior = NULL;
		head = head->next;
		delete(p);
	}

	bool IsEmpty() {
		if (head == last) {
			return 1;
		}
		else {
			return 0;
		}//判断是否空
	}
	void show() {
		for (node* p = head; p != last; p = p->next) {
			cout << p->value << " ";
			if (p->next == last) {
				cout << p->next->value << endl;
			}
		}

	}//输出队列
};


int main() {

	queue a;
	a.enqueue('x');
	a.enqueue('y');
	a.enqueue('z');
	a.show();
	a.dequeue();
	a.show();

	return 0;
}