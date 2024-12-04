//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        string pat = s2;
        string txt = s1+s1;
        int k = pat.length();
        vector<int> lps(k,0), res;
        for(int i = 1, len = 0; i<k; ){
            if(pat[i]==pat[len]){
                lps[i++] = ++len;
            }
            else if (len){
                len = lps[len-1];
            }else{
                lps[i++]=0;
            }
        }
        for(int i =0, j=0; i<txt.length();){
            if(txt[i]==pat[j]){
                i++,j++;
                if(j==k) return true;
            }else if(j){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends