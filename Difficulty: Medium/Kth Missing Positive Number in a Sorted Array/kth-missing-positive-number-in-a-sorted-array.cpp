//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
    int n = arr.size();
    int missing = 0; // Tracks missing count
    int prev = 0;    // Tracks the last checked number
    
    for (int i = 0; i < n; ++i) {
        int gap = arr[i] - prev - 1; // Missing numbers between prev and arr[i]
        
        if (missing + gap >= k) {
            // The kth missing number lies in this gap
            return prev + (k - missing);
        }
        
        // Update missing count and previous number
        missing += gap;
        prev = arr[i];
    }
    
    // If the kth missing number is beyond the last element in arr
    return prev + (k - missing);
}

};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends