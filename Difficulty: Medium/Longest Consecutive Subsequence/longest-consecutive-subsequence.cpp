//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
    if (arr.empty()) return 0;

    sort(arr.begin(), arr.end());
    int n = arr.size();
    int prevLong = 1, nowLong = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            nowLong++;
        } else if (arr[i] != arr[i - 1]) { 
            prevLong = max(prevLong, nowLong);
            nowLong = 1;
        }
    }

    prevLong = max(prevLong, nowLong);
    return prevLong;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends