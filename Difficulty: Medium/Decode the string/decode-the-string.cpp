//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        stack<string> st;
    stack<int> numStack;
    string res = "";
    int n = s.length();
    int num = 0;
    
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {  
            num = num * 10 + (s[i] - '0'); // Extracting multi-digit numbers
        } 
        else if (s[i] == '[') { 
            st.push(res);  // Store current result
            numStack.push(num); // Store the repeat count
            res = "";
            num = 0;
        } 
        else if (s[i] == ']') {  
            string temp = res;
            int repeatCount = numStack.top(); numStack.pop();
            res = st.top(); st.pop();  
            while (repeatCount--) {
                res += temp;
            }
        } 
        else {  
            res += s[i];
        }
    }
    
    return res;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends