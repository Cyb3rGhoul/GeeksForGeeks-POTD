/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list->
    
    Node *merge(Node *a, Node *b){
        Node *temp = new Node(0);
        Node *res = temp;
        
        while(a!=NULL && b!=NULL){
            if(a->data < b->data){
                temp->bottom = a;
                temp = temp->bottom;
                a = a->bottom;
            }else{
                temp->bottom = b;
                temp = temp->bottom;
                b = b->bottom;
            }
        }
        
        if(a) temp->bottom = a;
        else temp->bottom = b;
        return res->bottom;
    }
    
    
    Node *flatten(Node *root) {
        if(root == NULL || root->next == NULL) return root;
        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
        
    }
};