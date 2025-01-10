//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
    unordered_map<int, int> mp;
    int n = arr.size();
    int unique = 0;
    vector<int> ans;

    // Initialize the first window
    for (int i = 0; i < k; i++) {
        if (mp[arr[i]] == 0) {
            unique++;
        }
        mp[arr[i]]++;
    }
    ans.push_back(unique);

    // Slide the window through the array
    for (int i = k; i < n; i++) {
        // Remove the element going out of the window
        if (mp[arr[i - k]] == 1) {
            unique--;
        }
        mp[arr[i - k]]--;

        // Add the new element coming into the window
        if (mp[arr[i]] == 0) {
            unique++;
        }
        mp[arr[i]]++;

        // Push the count of unique elements in the current window
        ans.push_back(unique);
    }

    return ans;
        
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends