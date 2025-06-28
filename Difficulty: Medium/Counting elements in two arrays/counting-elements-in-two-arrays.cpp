bool comp(pair<int,int> &p1, pair<int,int> &p2){
    return p1.first<p2.first;
}

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        
        int n = a.size();
        int m = b.size();
        
        //store the index and number
        vector<pair<int,int>> vec;
        
        for(int i = 0; i<n; i++){
            vec.push_back({a[i],i});
        }
        
        
        sort(vec.begin(),vec.end(),comp);
        
        sort(b.begin(),b.end());
        
        vector<int> res(n);
        int j = 0; // pointer for b
        
        for(int i = 0; i < n; i++){
            while(j < m && b[j] <= vec[i].first){
                j++;
            }
            res[vec[i].second] = j;
        }
        
        return res;
        
        
    }
};