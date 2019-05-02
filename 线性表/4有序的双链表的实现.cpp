//
//  4有序的双链表的实现.cpp
//  DataStructurePractice
//
//  Created by Nostalgia.WH on 2019/3/16.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
using namespace std;

struct DNode{
    int data;
    DNode *llink,*rlink;
};
class DList {
    DNode *first,*last;
    DNode *p;
public:
    DList();
    void InsertData(int n);
    void Insert();
    void DeleteData(int n);
    void Delete();
    void Print();
    ~DList();
};
DList::DList(){
    first=new DNode;
    last=new DNode;
    first->rlink=last;
    last->llink=first;last->rlink=NULL;
    Insert();
}
void DList::InsertData(int n){
    DNode *t;
    if(first->rlink==last){
        p=new DNode;
        p->data=n;
        p->llink=first;p->rlink=last;
        first->rlink=p;last->llink=p;
        return;
    }else{
        p=first;
        while (p->rlink!=last) {
            if (n<p->rlink->data) {
                t=new DNode;
                t->data=n;
                t->rlink=p->rlink;t->llink=p;
                t->rlink->llink=t;p->rlink=t;
                return;
            }
            p=p->rlink;
        }
        t=new DNode;
        t->data=n;
        t->rlink=last;t->llink=p;
        last->llink=t;p->rlink=t;
    }
}
void DList::Insert(){
    int n;
    while (true) {
        cin>>n;
        if (n==0) {
            return;
        }
        InsertData(n);
    }
}
void DList::DeleteData(int n){
    p=first;
    while (p->rlink!=last) {
        if (p->rlink->data==n) {
            DNode *temp=p->rlink;
            p->rlink=p->rlink->rlink;
            p->rlink->llink=p;
            delete temp;
        }else
        p=p->rlink;
    }
}
void DList::Delete(){
    int n;
    while (true) {
        cin>>n;
        if (n==0) {
            return;
        }
        DeleteData(n);
    }
}
void DList::Print(){
    p=first->rlink;
    while (p!=last) {
        cout<<p->data<<" ";
        p=p->rlink;
    }
    cout<<endl;
}
DList::~DList(){
    p=first;
    while (p->rlink!=NULL) {
        DNode *temp=p->rlink;
        p->rlink=p->rlink->rlink;
        delete temp;
    }
    delete first;
}

int main(){
    DList list;
    list.Print();
    list.Insert();
    list.Print();
    list.Delete();
    list.Print();
    return 0;
}
