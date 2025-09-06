/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        
        if(head==nullptr || head->next==NULL) return 0;
        int len = 0;
        Node* fast = head->next->next;
        Node* slow = head->next;
        
        // Finding the meeting point
        while (fast != nullptr && fast->next != nullptr && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast==nullptr || fast->next==NULL || fast->next->next==NULL) return 0;
        
        slow = head;
        
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        while(fast->next!=slow){
            fast = fast->next;
            len++;
        }
        
        return len+1;
        
    }
};