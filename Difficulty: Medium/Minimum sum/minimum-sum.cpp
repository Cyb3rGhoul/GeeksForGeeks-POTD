//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
    // Initialize two strings for two numbers
    string n1, n2;
    
    // Sort the array in ascending order
    sort(arr.begin(), arr.end());

    // Distribute elements between n1 and n2
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            n1 += to_string(arr[i]);
        } else {
            n2 += to_string(arr[i]);
        }
    }

    // Perform the addition of n1 and n2 as strings
    string ans;
    int i = n1.size() - 1, j = n2.size() - 1, carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += n1[i--] - '0';
        if (j >= 0) sum += n2[j--] - '0';
        
        carry = sum / 10;
        ans += to_string(sum % 10);
    }
    
     while(ans.back()=='0')ans.pop_back();

    reverse(ans.begin(), ans.end());

    return ans;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends