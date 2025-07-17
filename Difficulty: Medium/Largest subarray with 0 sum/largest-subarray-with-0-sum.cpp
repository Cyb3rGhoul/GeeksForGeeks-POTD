class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        
        int sum = 0;
        
        int len = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
            if(sum == 0){
                len = max(len,i+1);
            }
            
            if(mp.count(sum)){
                len = max(len,i-mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
        
        return len;
    }
};