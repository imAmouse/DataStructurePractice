//
//  8反转诗句.cpp
//  DataStructurePractice
//
//  Created by 官文豪 on 2019/4/13.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

void fanZhuan(string words){
    stack<string> s;
    string word;
    for (int i=0; i<words.size(); i++) {
        if (words.at(i)!=' ') {
            word+=words.at(i);
        }
        if (words.at(i)==' ') {
            if(word!="")
                s.push(word);
            word="";
        }
    }
    if(word!="")
        s.push(word);
    while (!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    string words;
    while (true) {
        getline(cin, words);
        fanZhuan(words);
    }
}
