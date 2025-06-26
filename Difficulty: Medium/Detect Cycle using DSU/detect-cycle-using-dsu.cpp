class Solution {
  public:
    // Function to detect cycle using DSU in an undirected graph.
    
    
    vector<int> par;
    vector<int> rank;
    
    int find(int x){
        if(x==par[x]) return x;
        
        return par[x] = find(par[x]);    
    }
    
    void Union(int x, int y){
        int x_par = find(x);
        int y_par = find(y);
        
        if(x_par == y_par){
            return;
        }
        
        if(rank[x_par]>rank[y_par]){
            par[y_par] = x_par;
        }
        else if(rank[x_par]<rank[y_par]){
            par[x_par] = y_par;
        }else{
            par[x_par] = y_par;
            rank[y_par]++;
        }
        
    }
    
    
    int detectCycle(int V, vector<int> adj[]) {
        
        par.resize(V);
        rank.resize(V);
        
        for(int i = 0; i<V; i++){
            par[i] = i;
            rank[i] = 1;
        }
        // Code here
        for(int u = 0; u<V; u++){
            for(int &v : adj[u]){
                if(u<v){
                    int par_u = find(u);
                    int par_v = find(v);
                    
                    if(par_u == par_v) return 1;
                    
                    Union(par_u,par_v);
                }
            }
        }
        
        return 0;
    }
};