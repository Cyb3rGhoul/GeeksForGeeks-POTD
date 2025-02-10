//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void collectLeft(Node *root, vector<int> &v){
        if(root == NULL) return;//Base condition if current node is null
        if((root->left==NULL) && (root->right==NULL)) return;//Base condition if it is a Leaf node
        v.push_back(root->data);//pushing in the vector
        //Checking if the left node is present. If present calling the collectLeaf Function on it.
        if(root->left){
            collectLeft(root->left,v);
        }
        //checking if a right nide exists in absence of any left node.If present calling the collectLeaf Function on it.
        else if(root->right){
            collectLeft(root->right,v);
        }
    }
    void collectLeaves(Node *root, vector<int> &v){
        
        if (root == NULL) return;//Base condition
        //if the current node is a leaf node insert it in the vector.
        if((root->left==NULL) && (root->right==NULL)) v.push_back(root->data);
        //checking for left and right children for further leaves
        if(root->left) collectLeaves(root->left,v);
        if(root->right)collectLeaves(root->right,v);

    }
    
    void collectRight(Node *root, vector<int> &v){
        if(root == NULL) return;//Base condition
        if((root->left==NULL) && (root->right==NULL)) return;//if leaf return
        //if the right is present
        if(root->right){
         collectRight(root->right,v);//check for more right nodes
         v.push_back(root->data);//push the right node data in the vector
        }   
        else if(root->left){
         collectRight(root->left,v);  
             v.push_back(root->data);

        } 
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> vect;
        vect.push_back(root->data);
        collectLeft(root->left, vect);
        collectLeaves(root->left,vect);
        collectLeaves(root->right,vect);
        collectRight(root->right,vect);
        return vect;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends