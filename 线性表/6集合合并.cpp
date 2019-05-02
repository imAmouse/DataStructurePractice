//
//  6集合合并.cpp
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
    Node *first,*p,*r;
    int length;
public:
    List();
    void InsertNoChong(int n,int num);
    void Insert(int n,int m);
    void print();
    void pNext(){p=p->next;}
    int getLength(){return length;}
};
List::List(){
    length=0;
    first=new Node;
    first->next=NULL;
}
void List::InsertNoChong(int n,int num){
    Node* start=first->next;
    for (int i=0; i<n; i++) {
        if (start->data==num) {
            return;
        }
        start=start->next;
    }
    p=new Node;
    p->data=num;p->next=r->next;
    r->next=p;
    r=p;
    length++;
}
void List::Insert(int n,int m){
    int num;
    r=first;
    for (int i=0; i<n; i++) {
        cin>>num;
        p=new Node;
        p->data=num;p->next=r->next;
        r->next=p;
        r=p;
        length++;
    }
    for (int i=0; i<m; i++) {
        cin>>num;
        InsertNoChong(n,num);
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
    int a,b;
    cin>>a>>b;
    l1.Insert(a,b);
    cout<<l1.getLength()<<endl;
    l1.print();
    return 0;
}
