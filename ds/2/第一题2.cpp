#include<iostream>
using namespace std;
#define ElemType char

class node {
public:
	ElemType value;
	node* next;
	node* prior;
};

class stack {
public:
	node* head;
	node* last;


	stack() {
		head = NULL;
		last = NULL;
	}//��ʼ�� ������ڴ� head last��ָ��
	void push(ElemType x) {
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
	}//��ջ β��һ���ڵ�
	void pop() {
		node* p = last;
		last->prior->next = NULL;
		last = last->prior;
		delete(p);
	}//��ջ
	bool IsEmpty() {
		if (head == last) {
			return 1;
		}
		else {
			return 0;
		}//�ж��Ƿ��
	}
	void show() {
		for (node* p = head; p != last; p = p->next) {
			cout << p->value << " ";
			if (p->next == last) {
				cout << p->next->value << endl;
			}
		}

	}//���ջ
};

int main() {

	stack a;
	a.push('x');
	a.push('y');
	a.push('z');
	a.show();
	a.pop();
	a.show();

	return 0;
}

