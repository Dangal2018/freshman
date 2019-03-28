#include <bits/stdc++.h>
using namespace std;
//实现stack，使用链表
template <class T>
struct stack {
 struct Node {
 T item;
 Node* next;
 };
 Node *first;
 int count;
 stack() {
 //new返回一个指针？不是引用吗？
 count = 0;
 }
 void push(T n) {
 count++;
 Node *oldfirst = first;
 first = new Node();
 first->item = n;
 first->next = oldfirst;
 }
 void pop() {
 if (isEmpty()) return;
 count--;
 first = first->next;
 }
 T top() {
 return first->item;
 }
 bool isEmpty() {
 return !count;
 }
};
int main() {
 stack<int>s;
 s.push(1);
 s.push(2);
 s.push(3);
 while (!s.isEmpty()) {
 cout << s.top() << endl;
 s.pop();
 }
 cin.get();
}
