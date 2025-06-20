class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int,int>> st;
        
        int n = color.size();
        
        for(int i = 0; i<n; i++){
            if(st.empty() || st.top().first != color[i] || st.top().second != radius[i]){
                st.push({color[i],radius[i]});
            }
            else{
                while(!st.empty() && st.top().first == color[i] && st.top().second == radius[i]){
                    st.pop();
                }
            }
        }
        
        return st.size();
    }
};