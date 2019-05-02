//
//  1循环链队列.cpp
//  DataStructurePractice
//
//  Created by Nostalgia.WH on 2019/3/23.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Quene {
    Node *last;
    int length;
public:
    Quene();
    void Insert();
    void Pop(int num);
};

Quene::Quene(){
    last=new Node;
    last->next=last;
    length=0;
}
void Quene::Insert(){
    Node *s;
    while (true) {
        int n,m;
        cin>>n>>m;
        if (n==0&&m==0) {
            break;
        }
        for (int i=0; i<n; i++) {
            int data;
            cin>>data;
            s=new Node;
            s->data=data;s->next=last->next;
            last->next=s;
            last=s;
            length++;
        }
        if (m>length) {
            //cout<<"Error"<<endl;
            break;
        }
        Pop(m);
    }
}
void Quene::Pop(int num){
    Node *p=last->next,*temp;
    for (int i=0; i<num; i++) {
        cout<<p->next->data<<" ";
        temp=p->next;
        p->next=p->next->next;
        length--;
        delete temp;
    }
    cout<<endl;
}

int main(){
    Quene quene;
    quene.Insert();
}
