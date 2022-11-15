#include<iostream>
using namespace std;

#define ElemType char

typedef struct {
	ElemType data[100];
	int len = 0;
}list;

list SetList(int n) {
	list l;
	for (int i = 0; i < 100; i++) {
		l.data[i] = NULL;
	}
	l.len = 0;
	return l;
}

void insert(int n, int x, list& l) {
	for (int i = l.len; i > l.len - n; i--) {

	}
}