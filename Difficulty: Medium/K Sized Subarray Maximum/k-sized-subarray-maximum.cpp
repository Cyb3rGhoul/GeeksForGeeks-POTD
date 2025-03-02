//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
    vector<int> res;
    deque<int> dq;  // Stores indices of elements in the window
    
    for (int i = 0; i < n; i++) {
        // Remove elements that are out of this window
        if (!dq.empty() && dq.front() == i - k) 
            dq.pop_front();

        // Remove all elements smaller than the current one (they won't be useful)
        while (!dq.empty() && arr[dq.back()] <= arr[i]) 
            dq.pop_back();

        dq.push_back(i);

        // Store result when we have at least `k` elements processed
        if (i >= k - 1) 
            res.push_back(arr[dq.front()]);
    }
    return res;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends