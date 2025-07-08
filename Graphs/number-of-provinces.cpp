class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        vector<bool> visited(isConnected.size(), false);

       
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                provinces++;

                stack<int> cities;
                cities.push(i);

                while(!cities.empty()){
                    int city = cities.top();
                    cities.pop();
                    if(visited[city]) continue;
                    visited[city] = true;
                    
                    auto currCity = isConnected[city];
                    for(int j= 0; j < currCity.size(); j++){
                        if(currCity[j] && !visited[j] ) {
                            cities.push(j);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};