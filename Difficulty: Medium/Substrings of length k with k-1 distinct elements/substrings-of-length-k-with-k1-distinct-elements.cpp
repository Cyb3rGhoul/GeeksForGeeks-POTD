class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        unordered_map<char,int> mp;
        int n = s.length();
        int ctn = 0;
        
        for(int i = 0; i<k; i++){
            mp[s[i]]++;
        }
        
        if(mp.size()==k-1) ctn++;
        
        int l = 0;
        int r = k;
        
        while(r<n){
            mp[s[l]]--;
            if(mp[s[l]]==0) mp.erase(s[l]);
            l++;
            mp[s[r]]++;
            r++;
            if(mp.size()==k-1) ctn++;
        }
        
        return ctn;
    }
};