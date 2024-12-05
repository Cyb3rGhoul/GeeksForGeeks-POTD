//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        
        int one = 0, two = 0;
        for(int i =0; i<n; i++){
            if(arr[i]==1) one++;
            else if(arr[i]==2) two++;
        }
        int z = n - (one+two);
        int j = 0;
        while(j<n){
            if(z){
                arr[j] = 0;
                j++;
                z--;
            }
            else if(one){
                arr[j] = 1;
                j++;
                one--;
            }else{
                arr[j] = 2;
                j++;
                two--;
            }
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends