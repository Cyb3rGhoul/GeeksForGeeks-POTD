// User Function Template
typedef pair<int,int> p;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<vector<p>> adj(V);
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> res(V,INT_MAX);
        
        res[src] = 0;
        
        pq.push({0,src});
        
        while(!pq.empty()){
            auto a = pq.top();
            pq.pop();
            int n = a.second;
            int d = a.first;
            
            for(auto &vec: adj[n]){
                int node = vec.first;
                int dist = vec.second;
                
                if(d+dist < res[node]){
                    res[node] = d+dist;
                    pq.push({d+dist,node});
                }
            }
            
        }
        return res;
    }
};