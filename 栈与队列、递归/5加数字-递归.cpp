//
//  5加数字-递归.cpp
//  DataStructurePractice
//
//  Created by 官文豪 on 2019/4/9.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int getNum(stack<int> number,int n){
    for (int i=1; i<=number.top()/2; i++) {
        number.push(i);
        n=getNum(number, ++n);
        number.pop();
    }
    return n;
}

int main(){
    int num;
    cin>>num;
    stack<int> number;
    while (num!=0) {
        number.push(num%10);
        num/=10;
    }
    cout<<getNum(number, 1);
    return 0;
}
