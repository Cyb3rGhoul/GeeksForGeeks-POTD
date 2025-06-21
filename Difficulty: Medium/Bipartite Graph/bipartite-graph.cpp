class Solution {
  public:
    bool dfs(unordered_map<int,vector<int>>& adj, int curr, vector<int>& col, int currCol){
        
        col[curr] = currCol;
        
        
        //ab jaate hai adjacent node par
        
        for(int &v: adj[curr]){
            if(col[v]==col[curr]) return false;
            if(col[v]==-1) {
                //never colourd
                int colOfV = 1 - currCol;
                if(dfs(adj,v,col,colOfV)==false) return false;
            }
        }
        
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> col(V, -1);
        //red = 1;
        //green = 0;
        
        unordered_map<int,vector<int>> adj;
        
        for(auto &vec:edges){
            int a = vec[0];
            int b = vec[1];
            
            adj[b].push_back(a);
            adj[a].push_back(b);
            
        }
        
        
        for(int i = 0; i<V; i++){
            if(col[i] == -1){
                if(dfs(adj,i,col,1)==false){
                    return false;
                }
            }
        }
        
        return true;
    }
};