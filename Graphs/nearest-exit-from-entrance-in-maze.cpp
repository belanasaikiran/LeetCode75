class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int shortestPath = INT_MAX;

        int m = maze.size();    // row size
        int n = maze[0].size(); // col size

        // directions to move -> up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<pair<int, int>, int>> q; // pair, distance
        pair<int, int> location =  {entrance[0], entrance[1]};
        q.push({location, 0}); // init where the lady is standing
        visited[entrance[0]][entrance[1]] = true;

       

        while (!q.empty()) {
            auto [pos, distance] = q.front(); q.pop();
            auto [row, col] = pos;
            
            // check all directions
            for (auto& [Rd, Cd] : directions) {
                int newRow = row + Rd;
                int newCol = col + Cd;

                if ((newRow >= 0 && newRow < m) &&
                    (newCol >= 0 && newCol < n) && !visited[newRow][newCol]) {
                    if (maze[newRow][newCol] == '.') {
                        // cout << "visiting: [" << newRow << "," << newCol << "]"
                        //      << endl;

                        if ((newRow == 0 || newRow == m - 1) ||
                            (newCol == 0 || newCol == n - 1)) {
                            // cout << "found at " << newRow << ", " << newCol
                            //      << endl;
                            return distance + 1;
                        } else {
                            int steps = distance;
                            steps++;
                            visited[newRow][newCol] = true;
                            q.push({{newRow, newCol}, steps});
                            // cout << "inserting: [" << newRow << ", " << newCol << "] with distance -> " << steps << endl;
                        }
                    }
                }
            }
        }

        return -1;
    }
};