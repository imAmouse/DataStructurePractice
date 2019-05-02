//
//  1二叉树的遍历问题.cpp
//  DataStructurePractice
//
//  Created by 官文豪 on 2019/4/16.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

template <class T>
struct TNode {
    T data;
    TNode *left,*right;
};

template <class T>
class Tree {
public:
    TNode<T> *root;
    Tree(string str1,string str2);
    void Create(TNode<T> *&r,string str1,string str2);
    void PostOrder(TNode<T> *r);
    ~Tree();
};
template <class T>
Tree<T>::Tree(string str1,string str2) {
    root=NULL;
    if(str1.size()!=0){
        Create(root, str1, str2);
    }
}
template <class T>
void Tree<T>::Create(TNode<T> *&r,string strPre,string strIn){
    if (strPre.size()==0) {
        return;		
    }
    // 初始化根节点
    r=new TNode<T>;
    r->data=strPre.at(0);
    r->left=NULL;
    r->right=NULL;
    
    // 找到下一个根节点
    int i;
    for (i=0; strIn.at(i)!=strPre.at(0); i++) {
    }
    
    string leftStr1,leftStr2;
    string rightStr1,rightStr2;
    
    leftStr1=strPre.substr(1,i);
    leftStr2=strIn.substr(0,i);
    rightStr1=strPre.substr(i+1,strIn.size()-(i+1));
    rightStr2=strIn.substr(i+1,strIn.size()-(i+1));
    Create(r->left, leftStr1, leftStr2);
    Create(r->right, rightStr1, rightStr2);
}
template <class T>
void Tree<T>::PostOrder(TNode<T> *r) {
    if (r==NULL) {
        return;
    }
    PostOrder(r->left);
    PostOrder(r->right);
    cout<<r->data;
}
template <class T>
Tree<T>::~Tree() {
    
}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    Tree<char> t(str1, str2);
    t.PostOrder(t.root);
    return 0;
}
