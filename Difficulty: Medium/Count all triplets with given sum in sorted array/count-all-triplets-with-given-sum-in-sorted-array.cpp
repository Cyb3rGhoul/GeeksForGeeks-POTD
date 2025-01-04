//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        int count = 0;
        for(int i =0; i<n-2; i++){
            int left = i+1, right=n-1;
            while(left<right){
                int sum = arr[i]+arr[left]+arr[right];
                if(sum==target){
                    if(arr[left]==arr[right]){
                        int l = right - left + 1;
                        count+=(l*(l-1))/2;
                        break;
                    }
                    
                    int lCtn = 1;
                    
                    while(lCtn+1<right && arr[left]==arr[left+1]){
                        left++;
                        lCtn++;
                    }
                    
                    int rCtn = 1;
                    while(right-1>left && arr[right]==arr[right-1]){
                        right--;
                        rCtn++;
                    }
                    
                    
                    count+=lCtn*rCtn;
                    right--;
                    left++;
                }
                else if(sum>target){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends