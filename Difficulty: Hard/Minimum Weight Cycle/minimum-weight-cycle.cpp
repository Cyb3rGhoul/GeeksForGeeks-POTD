//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
      int dijkstra(int src, int des, unordered_map<int,vector<pair<int,int>>>& adj, int V) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> res(V,INT_MAX);
        pq.push({0,src});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
    
            for(auto& nbr : adj[u]){
                int v = nbr.first;
                int wt = nbr.second;
                if((u == src && v == des) || (u == des && v == src)){
                    continue;
                }
                if(d + wt < res[v]){
                    res[v] = d + wt;
                    pq.push({d+wt,v});
                }
            }
        }
        return res[des];
    }
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int ans = INT_MAX;
        
        for(auto& edge : edges){
            int path = dijkstra(edge[0],edge[1],adj,V);
            if(path != INT_MAX){
                ans = min(ans,path+edge[2]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends