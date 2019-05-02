// 链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<stack>
using namespace std;

class BiNode {
public:
    char data;
    BiNode* lchild;
    BiNode* rchild;
};
class BiTree {
public:
    BiNode* root;
    BiTree();
};
void print(BiNode *&t)
{
    if (t != NULL)
    {
        print(t->lchild);
        print(t->rchild);
        cout << t->data;
    }
}
BiTree::BiTree() {
    
    int i = 0;
    int m;
    root = new BiNode;
    BiNode* p;
    string qian = "abdec";
    string zhong = "dbeac";
    
    stack<char> charat;
    BiNode** qianxu = new BiNode*[qian.length()];
    int length = (int)qian.length();
    for (int i = 0; i < qian.length(); i++)
    {
        qianxu[i] = new BiNode;
        qianxu[i]->data = qian[i];
    }
    while (qian.length() > 1)
    {
        
        if (i == qian.length())
            i = 0;
        for (int j = 0; j < zhong.length(); j++)
        {
            if (j == zhong.length() - 1)
                break;
            if (qian[i] == zhong[j] && (j == 0 || qian[i + 1] == zhong[j - 1] || qian[i + 1] == zhong[j + 1]))
            {
                
                if (j != 0 && qian[i + 1] == zhong[j - 1])
                {
                    p = qianxu[i+1];
                    qianxu[i]->lchild = p;
                    for (int k = i+1; k < length - 1; k++)
                    {
                        qianxu[k] = qianxu[k + 1];
                    }
                    length--;
                    qian.erase(i + 1, 1);
                    zhong.erase(j - 1, 1);
                    j-=2;
                }
                else if (qian[i + 1] == zhong[j + 1])
                {
                    p = qianxu[i + 1];
                    qianxu[i]->rchild = p;
                    for (int k = i + 1; k < length - 1; k++)
                    {
                        qianxu[k] = qianxu[k + 1];
                    }
                    length--;
                    qian.erase(i + 1, 1);
                    zhong.erase(j + 1, 1);
                    j-=2;
                }
            }
        }
        i++;
    }
    root = qianxu[0];
    print(root);
}

int main() {
    BiTree Tree;
}

