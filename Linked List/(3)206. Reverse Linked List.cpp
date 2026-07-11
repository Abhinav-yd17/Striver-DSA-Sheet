#include<bits/stdc++.h>
using namespace std;    
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
        ListNode*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
        }
        return prev;
    }
};