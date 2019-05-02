//
//  3单链表的实现.cpp
//  DataStructurePractice
//
//  Created by Nostalgia.WH on 2019/3/16.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
class List {
    Node *first,*p,*r;
public:
    List();//头插
    List(bool a);//尾插
    void PrintAll();//遍历
    void Delete(int num);//按位删除
    void DeleteData(int num);//按值删除
    void DeletePNext();
    ~List();
};
List::List(){
    int num;
    first=new Node;
    first->next=NULL;
    while (true) {
        cin>>num;
        if (num==0) {
            break;
        }
        p=new Node;
        p->data=num;p->next=first->next;
        first->next=p;
    }
}
List::List(bool a){
    int num;
    first=new Node;
    first->next=NULL;
    r=first;
    while (true) {
        cin>>num;
        if (num==0) {
            break;
        }
        p=new Node;
        p->data=num;p->next=r->next;
        r->next=p;
        r=p;
    }
}
void List::PrintAll(){
    p=first;
    while (p->next!=NULL) {
        cout<<p->next->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void List::DeletePNext(){//删除指针p的下一个Node
    Node *temp=p->next;
    p->next=p->next->next;
    delete temp;
}
void List::Delete(int num){//按位置
    p=first;
    if (num==0) {
        cout<<"Error"<<endl;
        return;
    }
    for (int i=0; i<num-1; i++,p=p->next) {
        if (p->next->next==NULL) {
            cout<<"Error"<<endl;
            return;
        }
    }
    DeletePNext();
    PrintAll();
}
void List::DeleteData(int num){//按值
    p=first;
    while (p->next!=NULL) {
        if (p->next->data==num) {
            DeletePNext();
            PrintAll();
            return;
        }
        p=p->next;
    }
    cout<<"Error"<<endl;
}
List::~List(){
    p=first;
    while (p->next!=NULL) {
        DeletePNext();
    }
    delete p;
}

int main(){
    List w(true);
    List t;
    int num,n;
    cin>>num>>n;
    w.PrintAll();
    t.PrintAll();
    w.DeleteData(num);
    w.Delete(n);
    return 0;
}
