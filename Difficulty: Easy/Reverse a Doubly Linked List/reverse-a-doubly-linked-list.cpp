/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head==NULL) return nullptr;
        
        Node* newHead = head;
        Node* nex = head;
        
        while(newHead!=nullptr) {
            nex = newHead->next;
            newHead->next = newHead->prev;
            newHead->prev = nex;
            head = newHead;
            newHead = nex;
        }
        
        
        
        return head;
    }
};