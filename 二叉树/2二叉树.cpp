//
//  2二叉树.cpp
//  DataStructurePractice
//
//  Created by 官文豪 on 2019/4/23.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
using namespace std;

int getHeight(int node){
    
    int height;
    for (int i=1; node>(2<<(i-1))-1; i++) {
        height=i;
    }
    return ++height;
}

int Count(int m,int n){
    
    //计算树的高度
    int mHeight,nHeight;
    mHeight=getHeight(m);
    nHeight=getHeight(n);
    
    int count=
    
    return nHeight;
}

int main(){
    int m,n;
    while (true) {
        cin>>m>>n;
        if (m==0&&n==0) {
            break;
        }
        cout<<Count(m, n)<<endl;
    }
    return 0;
}
