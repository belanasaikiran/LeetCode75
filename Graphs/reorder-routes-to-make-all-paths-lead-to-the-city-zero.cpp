class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        unordered_map<int, vector<pair<int, int>>> graph;
        for(auto connection : connections){
            // each connection has 2 values 
            graph[connection[0]].push_back({connection[1], 1});
            graph[connection[1]].push_back({connection[0], 0}); // reverse connection
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int changes = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto& [neighbor, needsReversal] : graph[curr]){
                if(!visited[neighbor]){
                    changes += needsReversal;
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
             return changes;
    }
};