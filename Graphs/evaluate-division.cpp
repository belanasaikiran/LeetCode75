class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> adjList;
    double queryAnswer;

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        for (int i = 0; i < equations.size(); i++) {
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back(
                {equations[i][0], 1.0 / values[i]});
        }

        vector<double> answer;

        for (int i = 0; i < queries.size(); i++) {
            queryAnswer = 1.0;
            string start = queries[i][0];
            string end = queries[i][1];

            // any variable not found, we return -1
            if (!adjList.count(start) || !adjList.count(end)) {
                answer.push_back(-1.0);
                continue;
            }

            // if both are same, return 1
            if (start == end) {
                answer.push_back(1.0);
                continue;
            }

            unordered_set<string> visited;
            stack<pair<string, double>> st;
            st.push({start, 1.0});
            bool found = false;

            while (!st.empty()) {
                auto [node, val] = st.top();
                st.pop();

                if (node == end) {
                    queryAnswer = val;
                    found = true;
                    break;
                }

                visited.insert(node);

                for (auto& [neighbor, weight] : adjList[node]) {
                    if (visited.count(neighbor) == 0) {
                        st.push({neighbor, val * weight});
                    }
                }
            }

            if (!found) {
                answer.push_back(-1.0);
            } else {
                answer.push_back(queryAnswer);
            }
        }
        return answer;
    }
};