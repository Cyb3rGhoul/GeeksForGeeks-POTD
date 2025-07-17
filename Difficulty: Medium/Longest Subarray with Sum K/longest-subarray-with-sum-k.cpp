class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        int sum = 0, len = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
            if(sum==k){
                len = max(len,i+1);
            }
            
            if(mp.count(sum-k)){
                len = max(len,i-mp[sum-k]);
            }
            if(!mp.count(sum)){
                mp[sum] = i;
            }
        }
        return len;
    }
};