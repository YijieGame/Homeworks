#include<iostream>
using namespace std;

class node {
public:
    int no;
    node* next;
};

int josephus(int n,int s, int m) {
     if (n <= 0 || s <= 0 || m <= 0) {
         cout << "n、m、s均不可以小于等于0" << endl;
         return 0;
     }

    node *head = (node*)malloc(sizeof(node));
    node*p = head;

    for(int i=1;i<=n;i++){//开始建立约瑟夫环
         p->no = i;
         if(i!=n){
             p->next = (node*)malloc(sizeof(node));
             p = p->next;
         }
         else{
             p->next = head;
         }
    }

    while (head->next != head) {//开始鲨人
        node* p = head;
        node* q = head;

        for (int i = 0; i < m-2; i++) {//指针p指向牺牲者的上一位
            for (int j = 0; j < s; j++) {
                p = p->next;
            }
        }
        q = p->next;//q指向牺牲节点
        if (q == head) {
            head = q->next;//如果头结点牺牲，head指向下一节点
        }
        p->next = q;//删掉牺节点
        free(q);//释放牺牲内存
        p = q;
    }
    cout << head->no << "is still alive." << endl;
    return head->no;
}

int main(){
    josephus(10, 1, 3);

    return 0;
}