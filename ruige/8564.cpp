/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-22 16:49:28
 * @Description: 队列【链表实现】
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct queueNode
{
    int data;
    queueNode *next;
}queueNode, *LinkQueue;

typedef struct headQueue
{
    int size;
    LinkQueue front, rear;
}headQueue;

headQueue creatQueue()
{
    headQueue s;
    s.size = 0;
    s.front = NULL;
    return s;
}

void push(headQueue &s, int value)
{
    LinkQueue node = new queueNode;
    node -> data = value;
    node -> next = NULL;
    s.rear -> next = node;
    s.rear = node;
    s.size ++;
    if (s.front == NULL) s.front = node;
    return ;
}

void pop(headQueue &s)
{
    if (s.front == NULL)
    {
        cout << "EMPTY QUEUE !!!" << endl;
        return ;
    }
    LinkQueue node = s.front;
    s.front = node->next;
    s.size --;
    // cout << "FRONT:" << s.front->data << endl;
    delete node;
    return;
}

int back(headQueue s)
{
    if (s.front == NULL)
    {
        cout << "EMPTY QUEUE !!!" << endl;
        return -1;
    }
    return s.front -> data;
}

int main()
{
    headQueue s = creatQueue();
    int x;
    while (cin >> x && x!=0)
    {
        push(s, x);
    }
    while (s.size)
    {
        cout << back(s) << " ";
        pop(s);
    }
    cout << endl;
    return 0;
}
