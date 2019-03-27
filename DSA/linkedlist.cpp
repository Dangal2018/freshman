//cpp
#include <bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
 struct Node{
     int value;
     Node * next;
 };
  struct DNode{
     int value;
     DNode * left;
     DNode * right;
 };
 struct BinaryTreeNode{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};
 //p节点后插入值为i的节点
void insertNode(Node *p, int i){
    Node* node = new Node;
    node->value = i;
    node->next = p->next;
    p->next = node;
}
void deleteNode(Node *p){
    p->value = p->next->value;
    p->next = p->next->next;
}
//1.stack
void printLinkedListReversinglyByStack(Node *head){
    stack<Node* > nodesStack;
    Node* pNode = head;
    //遍历链表
    while (pNode != NULL) {
        nodesStack.push(pNode);
        pNode = pNode->next;
    }
    while (!nodesStack.empty()) {
        pNode=nodesStack.top();
        printf("%d\t", pNode->value);
        nodesStack.pop();
    }
}
//2.递归
void printLinkedListReversinglyRecursively(Node *head){
    if (head!=NULL) {
        if (head->next!=NULL) {
            printLinkedListReversinglyRecursively(head->next);
        }
        printf("%d\t", head->value);
    }
}
//找出中间节点
Node* findMidNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    while (fast->next != 0&&fast->next->next!=0) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//找出倒数第k个节点
Node* findKNode(Node* head,int k){
    Node *temp1 = head;
    Node *temp2 = head;
    while (k-->0) {
        if(temp2 == NULL){
            return NULL;
        }
        temp2 =temp2->next;
    }
    while (temp2->next != NULL&&temp2->next->next!=NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }
    return temp1;
}
//翻转链表
Node * reverseLinkedList(Node* head,int k){
    Node *reversedHead = NULL;
    Node *pNode = head;
    Node *pre = NULL;
    while (pNode!=NULL) {
        if (pNode->next==NULL) {
            reversedHead = pNode;
        }
        Node* nxt = pNode->next;
        pNode->next = pre;
        pre=pNode;
        pNode=nxt;
    }
    return reversedHead;
}
//Node* findCrosspoint(Node* l1, Node* l2){
//    int m = getLinkedListLength(l1);
//    int n = getLinkedListLength(l2);
//    int distance=0;
//    Node *temp1= l1;
//    Node *temp2= l2;
//    if (m>n) {
//        distance = m - n;
//        while (distance>0) {
//            distance--;
//            temp1=temp1->next;
//        }
//    } else{
//        distance = n - m;
//        while (distance>0) {
//            distance--;
//            temp2 = temp2->next;
//        }
//    }
//    while(temp1!=temp2&&temp1->next!=NULL&&temp2->next!=NULL){
//        temp1=temp1->next;
//        temp2=temp2->next;
//    }
//    if(temp1 == temp2){
//        return temp1;
//    }
//    return 0;
//}
//判断是否含有环
bool containLoop(Node* head){
    if (head==NULL) {
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while (slow!=fast&&fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast==NULL) {
        return false;
    }
    return true;
}
//获得环的长度
int getLoopLength(Node* head){
    if (head==NULL) {
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    while (slow!=fast&&fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast==NULL) {
        return 0;
    }
    //slow和fast首次相遇后，slow和fast继续走
    //再次相遇时，即slow走了一圈，fast走了两圈
    int length = 0;
    while (slow!=fast) {
        length++;
        slow = slow->next;
        fast = fast->next->next;
    }
    return length;
}
//获得环的连接点
Node* getJoinpoit(Node* head){
    if (head==NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while (slow!=fast&&fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast==NULL) {
        return NULL;
    }
    Node* fromhead = head;
    Node* fromcrashpoint = slow;

    while (fromcrashpoint!=fromhead) {
        fromhead = fromhead->next;
        fromcrashpoint = fromcrashpoint->next;
    }
    return fromhead;
}
BinaryTreeNode* convertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInLast){
    if (pNode == NULL) {
        return NULL;
    }
    BinaryTreeNode *pCurrent = pNode;
    if (pCurrent->left != NULL) {
        convertNode(pCurrent->left, pLastNodeInLast);
    }

    pCurrent->left = *pLastNodeInLast;
    if (*pLastNodeInLast != NULL) {
        (*pLastNodeInLast)->right=pCurrent;
    }

    *pLastNodeInLast = pCurrent;
    if (pCurrent->right != NULL) {
        convertNode(pCurrent->right, pLastNodeInLast);
    }
    return NULL;
}

BinaryTreeNode* convertBTToDLL(BinaryTreeNode* root){
    BinaryTreeNode *pLastNodeInLast = NULL;
    convertNode(root, &pLastNodeInLast);
    BinaryTreeNode *pHeadOfList = pLastNodeInLast;
    while (pHeadOfList != NULL && pHeadOfList->left != NULL) {
        pHeadOfList = pHeadOfList->left;
    }
    return pHeadOfList;
}
int main()
{
	
	return 0 ;
} 
