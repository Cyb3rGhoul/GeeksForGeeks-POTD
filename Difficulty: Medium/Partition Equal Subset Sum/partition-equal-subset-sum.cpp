//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum%2) return false ; 
        sum/=2;
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, 0));
        
        //find if there exist a set with sum n 
        for(int i=0 ; i<=n ; i++){
            dp[i][0] = 1 ; 
        }
        for(int i=1; i<=n ; i++){
            for(int j=1 ; j<=sum ; j++){
                //
                if(j<arr[i-1])
                dp[i][j] = dp[i-1][j] ;
                else
                dp[i][j] = dp[i-1][j-arr[i - 1]]  || dp[i-1][j] ;
            }
            
        }
        return dp[n][sum];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends