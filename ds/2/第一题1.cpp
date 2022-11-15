//数组实现栈

#include<iostream>
using namespace std;

#define ElemType char
#define StackLen 100

class stack;

int main() {

    return 0;
}

class stack {
private:
    ElemType l[StackLen];
    int last = 0;
public:
    stack() {
        for (int i = 0; i < StackLen; i++) {
            l[i] = '/0';
        }
    }

    void push(ElemType x) {
        l[last] = x;
        last++;
    }

    void pop() {
        l[last] = '/0';
        last--;
    }

    void PrintStack() {
        for (int i = 0; i < last; i++) {
            cout << l[i] << ' ';
        }
    }
};
