//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        vector<int> ans;
    
    // Sort both arrays for efficient duplicate handling
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = 0, j = 0;
    
    // Use two-pointer technique to find the intersection
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            // Add to `ans` only if it is not a duplicate of the last added element
            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++; // Move pointer `i` if a[i] is smaller
        } else {
            j++; // Move pointer `j` if b[j] is smaller
        }
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
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends