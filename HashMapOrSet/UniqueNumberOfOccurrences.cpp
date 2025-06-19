class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int number : arr) map[number]++;
        
        unordered_set<int> occurences;
        for(auto pair: map) occurences.insert(pair.second);
        
        return map.size() == occurences.size();
    }
};