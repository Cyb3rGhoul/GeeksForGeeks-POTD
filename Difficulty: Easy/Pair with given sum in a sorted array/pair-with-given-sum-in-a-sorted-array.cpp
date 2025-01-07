//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        
        int i = 0;
        int j = n-1;
        
        int ctn = 0;
        while(i<j){
            if(arr[i]+arr[j]==target){
                ctn++;
                int st = i+1;
                    int e  = j - 1;
                    while(st < j){
                        if(arr[st]+arr[j]==target) ctn++;
                        else if(arr[st]+arr[j] > target) break;
                        st++;
                    }
                    while(e > i){
                        if(arr[e]+arr[i]==target) ctn++;
                        else if(arr[e]+arr[j] < target) break;
                        e--;
                    }
                    i++;
                    j--;
            }
            else if(arr[i]+arr[j]>target){
                j--;
            }else{
                i++;
            }
        }
        return ctn;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends