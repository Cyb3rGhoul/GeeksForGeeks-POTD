//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int merge(vector<int>& arr, int l, int mid, int r){
        int count  = 0;
        vector<int> temp;
        int i = l,j=mid+1;
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]) temp.push_back(arr[i++]);
            else{
                count += mid + 1 - i;
                temp.push_back(arr[j++]);
            }
        }
        while(i<=mid) temp.push_back(arr[i++]);
        while(j<=r) temp.push_back(arr[j++]);
        
        for(int k = l; k<=r; k++) arr[k] = temp[k-l];
        
        return count;
    }
    int mergeSort(vector<int>& arr, int l, int r){
        if(l>=r) return 0;
        
        int count = 0;
        int mid = l + (r-l)/2;
        
        count+=mergeSort(arr,l,mid);
        count+=mergeSort(arr,mid+1,r);
        count+=merge(arr,l,mid,r);
        
        return count;
    }
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr,0,arr.size()-1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends