//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int i = 0;
        int j = 0;
        int k = 0;
        int count = 0;
        while(i<n-2){
            j = i+1;
            while(j<n-1){
                k = j+1;
                while(k<n){
                    if(arr[i]+arr[j]>arr[k]){
                        count++;
                        k++;
                    }else{
                        break;
                    }
                }
                j++;    
            }
            i++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends