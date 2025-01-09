//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
    int n = arr.size();
    int l = 0;
    int sum = 0;
    vector<int> ans;

    for (int r = 0; r < n; ++r) {
        sum += arr[r];
        
        while (sum > target && l <= r) {
            sum -= arr[l];
            l++;
        }
        
        if (sum == target) {
            ans.push_back(l + 1); // Convert to 1-based indexing
            ans.push_back(r + 1); // Convert to 1-based indexing
            return ans;
        }
    }

    return {-1}; // Return -1 if no subarray with the target sum is found
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends