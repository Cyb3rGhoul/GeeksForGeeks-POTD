//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<int> st;
    int min;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(st.empty()) min = x;
        else
        {
            if(x<=min)
            {
                st.push(min);
                min=x;
            }
        }
        st.push(x);
        // code here
    }

    // Remove the top element from the Stack
    void pop() {
        if(st.empty()) return;
        int temp = st.top();
        st.pop();
        if(temp==min && !st.empty())
        {
            min= st.top();
            st.pop();
        }
        
        // code here
    }

    // Returns top element of the Stack
    int peek() {
        if(st.empty()) return -1;
        return st.top();
        // code here
    }

    // Finds minimum element of Stack
    int getMin() {
        if(st.empty()) return -1;
        return min;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends