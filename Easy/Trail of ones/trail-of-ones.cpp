//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int numberOfConsecutiveOnes(int n) {
        long long mod = (int) 1e9 + 7, res = 1, a = 1, b = 1;
        if(n == 1 or n == 2)
            return 1;
            
        for(int i = 3; i <= n; i++) {
            long long c = (a + b) % mod;
            a = b;
            b = c;
            
            res = ((res * 1ll * 2) + a) % mod;
        }
        
        return (int) res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends