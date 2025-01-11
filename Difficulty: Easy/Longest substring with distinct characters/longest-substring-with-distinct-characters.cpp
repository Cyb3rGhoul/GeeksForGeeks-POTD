//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

int longestUniqueSubstr(string &s) {
    int n = s.length();
    unordered_map<char, int> mp;
    int res = 0;
    int l = 0;

    for (int r = 0; r < n; r++) {
        mp[s[r]]++;
        
        // If a character is repeated, shrink the window from the left
        while (mp[s[r]] > 1) {
            mp[s[l]]--; // Remove the character at the left pointer
            l++;        // Move the left pointer forward
        }

        // Update the result with the current window size
        res = max(res, r - l + 1);
    }
    return res;
}

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends