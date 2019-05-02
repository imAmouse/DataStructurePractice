//
//  main.cpp
//  DataStructurePractice
//
//  Created by Nostalgia.WH on 2019/3/12.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class List{
private:
    int length=0;
    Node *first,*p;
public:
    List();
    List(int num);
    int getLength();
    int getYueSeFu(int k,int m);
    void pNext();
};
List::List(){
    length=0;
}
List::List(int num){
    List();
    Node *s,*r;
    first=new Node;
    first->next=first;
    r=first;
    for (int i=0; i<num; i++) {
        s=new Node;
        s->data=i+1;
        s->next=r->next;
        r->next=s;
        r=s;
    }
    length=num;
}
int List::getLength(){
    return length;
}
void List::pNext(){
    //切换下一个
    if (p->next->next==first) {
        p=first;
    }else{
        p=p->next;
    }
}
int List::getYueSeFu(int k, int m){
    p=first;
    Node *temp;
    for(int i=0;i<k-1;i++)
        pNext();
    int i=1;
    while(length>1){
        if ((i)%m==0) {
            //删除节点
            temp=p->next;
            p->next=p->next->next;
            delete temp;
            
            length--;
            if(p->next==first)
                p=p->next;
        }else{
            pNext();
        }
        i++;
    }
    
    return first->next->data;
}

int main() {
    
    int n,k,m;
    cin>>n>>k>>m;
    List l(n);
    cout<<l.getYueSeFu(k, m);
    
    return 0;
}
