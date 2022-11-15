#include<iostream>
using namespace std;

class node {
public:
    int no;
    node* next;
};

int josephus(int n,int s, int m) {
     if (n <= 0 || s <= 0 || m <= 0) {
         cout << "n��m��s��������С�ڵ���0" << endl;
         return 0;
     }

    node *head = (node*)malloc(sizeof(node));
    node*p = head;

    for(int i=1;i<=n;i++){//��ʼ����Լɪ��
         p->no = i;
         if(i!=n){
             p->next = (node*)malloc(sizeof(node));
             p = p->next;
         }
         else{
             p->next = head;
         }
    }

    while (head->next != head) {//��ʼ����
        node* p = head;
        node* q = head;

        for (int i = 0; i < m-2; i++) {//ָ��pָ�������ߵ���һλ
            for (int j = 0; j < s; j++) {
                p = p->next;
            }
        }
        q = p->next;//qָ�������ڵ�
        if (q == head) {
            head = q->next;//���ͷ���������headָ����һ�ڵ�
        }
        p->next = q;//ɾ�����ڵ�
        free(q);//�ͷ������ڴ�
        p = q;
    }
    cout << head->no << "is still alive." << endl;
    return head->no;
}

int main(){
    josephus(10, 1, 3);

    return 0;
}