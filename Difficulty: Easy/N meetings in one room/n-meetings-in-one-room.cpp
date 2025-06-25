
bool comp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}


class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>> st;
        
        for(int i = 0; i<start.size(); i++){
            st.push_back({start[i],end[i]});
        }
        
        sort(st.begin(),st.end(),comp);
        
        // int s = st[0][0];
        int ctn = 0;
        int e = -1;
        for(int i = 0; i<start.size(); i++){
            if(st[i].first>e){
                e = st[i].second;
                ctn++;
            }
        }
        return ctn;
    }
};