//
//  4找出N个数中的最大值-递归.cpp
//  DataStructurePractice
//
//  Created by 官文豪 on 2019/4/9.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
using namespace std;

void diGui(int index,int i,int num,int c){
    int t;
    cin>>t;
    if (t>num) {
        num=t;
        i=index;
    }
    if (index==c-1) {
        cout<<i+1<<" "<<num<<endl;
        return;
    }
    diGui(++index,i, num, c);
}

int main()
{
    int c;
    cin>>c;
    diGui(0,0, 0,c);
    return 0;
}

