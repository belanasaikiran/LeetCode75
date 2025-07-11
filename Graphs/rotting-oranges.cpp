class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // 1. Set Directions
        // 2. Create Queue for BFS
        // 3. Visited Element
        int minutes = 0;
        int m = grid.size(), n = grid[0].size();

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Create QUEUE
        queue<pair<pair<int, int>, int>> q;

        pair<int, int> rottenOrange;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    rottenOrange = {i, j};
                    // insert the rottenOrange
                    q.push({rottenOrange, 0});
                }
            }
        }

        // BFS
        while (!q.empty()) {
            auto [currLocation, min] = q.front();

            minutes = max(min, minutes);

            q.pop();

            int row = currLocation.first;
            int col = currLocation.second;

            // check all the surroundings of the current orange.
            for (auto& [rD, cD] : directions) {
                int newRow = row + rD;
                int newCol = col + cD;
                // if the surroundings orange is fresh, rotten it now and add to
                // the
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2; // rot it
                    q.push({{newRow, newCol}, min + 1});
                }
              
            }
        }

         for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minutes;
    }

};