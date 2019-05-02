//
//  3递归进制转换.cpp
//  DataStructurePractice
//
//  Created by 官文豪 on 2019/4/9.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void decToHex(int dec,string answer){
    if (dec!=0) {
        answer.insert(0, to_string(dec%2));
        dec/=2;
        decToHex(dec, answer);
    }
    else
        cout<< answer;
}

int main(){
    int num;
    string answer="";
    cin>>num;
    
    decToHex(num,answer);
}
