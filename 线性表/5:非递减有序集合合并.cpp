//
//  5:非递减有序集合合并.cpp
//  DataStructurePractice
//
//  Created by Nostalgia.WH on 2019/3/16.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
class List{
    Node *first,*last,*p;
    int length;
public:
    List();
    void Insert(int n);
    void pNext();
    void print();
    int getLength(){return length;}
};
List::List(){
    length=0;
    first=new Node;
    last=new Node;
    first->next=last;
}
void List::pNext(){
    p=p->next;
}
void List::Insert(int n){
    if(n==0){
        p=new Node;
        p->data=n;
        p->next=last;
        first->next=p;
        length++;
    }else{
        p=first;
        for(int i=0;i<length;i++){
            if(p->next->data==n)
                return;
            if(p->next->data>n){
                Node *t=new Node;
                t->data=n;
                t->next=p->next;
                p->next=t;
                length++;
                return;
            }
            pNext();
        }
        Node *t=new Node;
        t->data=n;
        t->next=p->next;
        p->next=t;
        length++;
    }
}
void List::print(){
    p=first->next;
    for(int i=0;i<length;i++,p=p->next)
        cout<<p->data<<" ";
    cout<<endl;
}

int main(){
    List l1;
    int a,b,n;
    cin>>a>>b;
    for (int i=0; i<a+b; i++) {
        cin>>n;
        l1.Insert(n);
    }
    cout<<l1.getLength()<<endl;
    l1.print();
    return 0;
}
