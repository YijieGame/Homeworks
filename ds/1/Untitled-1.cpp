#include<iostream>
using namespace std;

#define ElemType char

class list {
public:
    ElemType data[100];
    int len;

    list() {
        len = 0;
        for (int i = 0; data[i] != '\0'; i++) {
            data[i] = NULL;
        }
    }

    void insert(int n, int x) {
        for (int i = len - 1; i >= n-1; i--) {
            data[i + 1] = data[i];
        }
        data[n - 1] = x;
        len++;
    }

    void remove(int n) {
        for (int i = n; i < len; i++) {
            data[i] = data[i + 1];
        }
        data[len] = NULL;
        len--;
    }

    ElemType search_loc(int n) {
        return data[n - 1];
    }

    int saerch_value(int x) {
        for (int i = 0; i < len; i++) {
            if (data[i] == x) {
                return i + 1;
            }
        }
    }

    int length() {
        return len;
    }

    void show() {
        for (int i = 0; i < len; i++) {
            cout << "no"<<i + 1 << ":" << data[i] << endl;
        }
    }
};

int main(){
    list l;
    l.insert(1,'a');
    l.insert(2,'b');
    l.insert(3,'c');
    l.insert(2,'d');
    cout<<l.saerch_value('b')<<endl;
    cout<<l.search_loc(2)<<endl;
    cout<<l.length()<<endl;
    l.show();
    
    
    return 0;
}







