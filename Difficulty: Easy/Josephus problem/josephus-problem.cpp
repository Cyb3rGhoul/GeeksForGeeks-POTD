/*You are required to complete this method */

class Solution {
  public:
    int solve(int idx, vector<int> &res, int k){
        if(res.size()==1) return res[0];
        
        idx = (idx + k)%res.size();
        
        res.erase(res.begin()+idx);
        
        solve(idx,res,k);
    }
    int josephus(int n, int k) {
        // Your code here
        vector<int> res(n);
        
        for(int i = 0; i<n; i++){
            res[i] = i+1;
        }
        
        int ans = solve(0,res,k-1);
        
        return ans;
    }
};