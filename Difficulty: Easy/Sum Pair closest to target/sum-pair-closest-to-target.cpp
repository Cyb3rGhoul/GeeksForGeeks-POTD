//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // Sort the array
    sort(arr.begin(), arr.end());
    int n = arr.size();

    // Initialize variables
    int i = 0;
    int j = n - 1;
    int closestDiff = INT_MAX; // Start with the largest possible value
    int num1 = 0, num2 = 0;
    vector<int> ans;

    // Two-pointer approach
    while (i < j) {
        int sum = arr[i] + arr[j];
        int diff = abs(target - sum);

        // Update the closest pair if a better difference is found
        if (diff < closestDiff) {
            closestDiff = diff;
            num1 = arr[i];
            num2 = arr[j];
        }

        // Adjust pointers based on the sum
        if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    // Add the closest pair to the result
    if (closestDiff != INT_MAX) {
        ans.push_back(num1);
        ans.push_back(num2);
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends