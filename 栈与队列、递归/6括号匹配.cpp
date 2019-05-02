//
//  6括号匹配.cpp
//  DataStructurePractice
//
//  Created by 官文豪 on 2019/4/13.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string checkBrackets(string str){
    stack<char> chars;
    for (int i=0; i<str.size(); i++) {
        if (!chars.empty()) {
            if ((chars.top()=='('&&str.at(i)==')')||
                (chars.top()=='['&&str.at(i)==']')||
                (chars.top()=='{'&&str.at(i)=='}')) {
                chars.pop();
            }else
                chars.push(str.at(i));
        }
        else
            chars.push(str.at(i));
    }
    
    if (chars.empty()) {
        return "Brackets match";
    }else{
        bool leftEx=false,rightEx=false;
        char a;
        while (!chars.empty()) {
            a=chars.top();chars.pop();
            if (a=='('||a=='['||a=='{') {
                leftEx=true;
            }
            if (a==')'||a==']'||a=='}') {
                rightEx=true;
            }
        }
        if (leftEx&&rightEx) {
            return "Brackets not match";
        }
        if (leftEx) {
            return "Extra left brackets";
        }
        if (rightEx) {
            return "Extra right brackets";
        }
    }
    return "Brackets match";
}

int main(){
    string str;
    cin>>str;
    cout<<checkBrackets(str);
    return 0;
}
