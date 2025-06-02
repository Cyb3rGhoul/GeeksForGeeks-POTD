class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        
        int n = arr.size();
        
        int ans = 0;
        
        for(int num:arr){
            pq.push(num);
        }
        
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans+=(a+b);
            pq.push(a+b);
        }
        return ans;
    }
};