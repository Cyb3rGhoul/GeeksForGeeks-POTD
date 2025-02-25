//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> nextSmall(vector<int> a, int n){
        vector<int> res(n);
        stack<int> st;
        st.push(-1);
        for(int i = n-1; i>=0; i--){
            int curr = a[i];
            while(st.top() != -1 && a[st.top()]>=curr) st.pop();
            res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> prevSmall(vector<int> a, int n){
        vector<int> res(n);
        stack<int> st;
        st.push(-1);
        for(int i = 0; i<n; i++){
            int curr = a[i];
            while(st.top() != -1 && a[st.top()]>=curr) st.pop();
            res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        vector<int> nextg(n);
        nextg = nextSmall(arr,n);
        vector<int> prevg(n);
        prevg = prevSmall(arr,n);
        int area = INT_MIN;
        for(int i = 0; i<n; i++){
            int h = arr[i];
            if(nextg[i] == -1) nextg[i] = n;
            int b = nextg[i] - prevg[i] - 1;
            area = max(area,h*b);
        }
        return area;
        
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
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends