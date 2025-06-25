class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int> freq(26,0);
        
        for(int i = 0; i<s.length(); i++){
            freq[s[i]-'a']++;
        }
        
        unordered_map<int,int> mp;
        for(char f: freq){
            if(f) mp[f]++;
        }
        
        if(mp.size()==1) return true;
        if(mp.size()!=2) return false;
        
        auto it = mp.begin();
        int f1 = it->first, c1 = it->second;
        it++;
        int f2 = it->first, c2 = it->second;
        
        if((f1==1 && c1==1)||(f2==1 && c2==1)) return true;
        if((abs(f1-f2)==1) && ((f1>f2 && c1 == 1) || (f2>f1 && c2==1))) return true;
        return false;
        
    }
};