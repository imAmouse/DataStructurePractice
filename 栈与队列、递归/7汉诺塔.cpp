//
//  7汉诺塔.cpp
//  DataStructurePractice
//
//  Created by 官文豪 on 2019/4/13.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int ciShu=0;

void operate(int num,char a,char b,char c){
    if(num==0)return;
    operate(num-1, a, c, b);
    printf("Move %c->%c\n",a,c);
    ciShu++;
    operate(num-1, b, a, c);
}

int main(){
    int num;
    cin>>num;
    
    operate(num,'A', 'B', 'C');
    cout<<ciShu;
    return 0;
}
