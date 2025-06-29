class Solution {
    
    void solve(vector<int>& arr, int idx, vector<int>& temp, vector<vector<int>>& res){
        if(idx == arr.size()){
            
            res.push_back(temp);
            return;
        }
        
        temp.push_back(arr[idx]);
        
        solve(arr,idx+1,temp,res);
        
        temp.pop_back();
        
        
        solve(arr,idx+1,temp,res);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<vector<int>> res;
        
        vector<int> temp;
        
        solve(arr,0,temp,res);
        
        
        vector<int> ans;
        for(auto &vec: res){
            int sum = accumulate(vec.begin(),vec.end(),0);
            ans.push_back(sum);
        }
        
        return ans;
        
    }
};