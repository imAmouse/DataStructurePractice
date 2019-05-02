//
//  2逆波兰表达式.cpp
//  DataStructurePractice
//
//  Created by 官文豪 on 2019/4/2.
//  Copyright © 2019 Nostalgia.WH. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    stack<double> number;
    string str,t="";
    getline(cin,str);
    
    double a,b;
    int n=0;//记录连续输入数字位数
    // 将数组 转换为 运算符/数字
    for (int i=(int)str.length()-1; i>=0; i--) {
        if (str[i]!=' ')
            t.insert(0,1, str[i]);
        else if(t!=""){
            double num=atof(t.c_str());
            number.push(num);
            n++;
            t="";
        }
        if(t=="+"||t=="-"||t=="*"||t=="/"){
                if (n>1) {
                    a=number.top();number.pop();
                    b=number.top();number.pop();
                    switch (t[0]) {
                        case '+':
                            number.push(b+a);
                            break;
                        case '-':
                            number.push(a-b);
                            break;
                        case '*':
                            number.push(b*a);
                            break;
                        case '/':
                            number.push(a/b);
                            break;
                    }
                    n--;
                }
                t="";
        }
    }
    
    printf("%f\n", number.top());
    return 0;
}
