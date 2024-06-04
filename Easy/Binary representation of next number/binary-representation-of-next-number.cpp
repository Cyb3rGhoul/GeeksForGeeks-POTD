//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        int n = s.size();
        int carry = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '0' && carry == 1)
            {
                s[i] = '1';
                carry = 0;
            }
            else if(s[i] == '1')
            {
                if(carry == 1)
                {
                    s[i] = '0';
                }
                else s[i] = '1';
            }
        }
        int i = 0;
        for(i = 0; i < n; i++)
        {
            if(s[i] == '1') break;
        }
        if(i != n)
        s = s.substr(i);
        if(carry == 1)
        s = "1" + s;
        return s;
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
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends