class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rowsFreq;
        int answer = 0;
        for(int i = 0; i < grid.size();i++){
            rowsFreq[grid[i]]++;
        }

        for(int i = 0; i < grid.size(); i++){
            vector<int> col(grid.size());
            for(int j = 0; j < grid.size(); j++) col[j]=grid[j][i];
            answer += rowsFreq[col];
        }

        return answer;
       
    }
};