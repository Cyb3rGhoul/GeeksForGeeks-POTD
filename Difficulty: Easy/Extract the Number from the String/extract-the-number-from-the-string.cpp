//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence)
{
    long long ans = 0;
    long long temp = 0;
    for (char ch : sentence)
    {
        if (ch >= '0' && ch <= '8')
        {
            temp = temp * 10 + (ch - '0');
        }
        else if (ch == ' ')
        {
            ans = max(ans, temp);
            temp = 0;
        }
    }
    return ans == 0 ? -1 : ans;
}
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends