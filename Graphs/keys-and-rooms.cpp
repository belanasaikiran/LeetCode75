class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.size() <= 1) return true;

        vector<bool> visited(rooms.size(), false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int room = q.front();
            q.pop();
            if(visited[room]) continue;
            visited[room] = true;
            for(auto key : rooms[room]){
                q.push(key);
            }
        }

        for(auto room : visited){
            if(!room) return false;
        }

        return true;
    }
};