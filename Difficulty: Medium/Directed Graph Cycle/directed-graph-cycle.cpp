#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isCyclic(int N, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list and compute indegree
        vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // Directed edge u -> v
            indegree[v]++;
        }

        // Step 2: Initialize queue with nodes having indegree 0
        queue<int> q;
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        // Step 3: Process nodes in topological order
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }

        // Step 4: If count != N, cycle exists
        return count != N;
    }
};