class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestAltitude = 0;
        int prev = 0;
        for(int i = 0; i < gain.size(); i++){
            prev = prev + gain[i];
            highestAltitude = max(highestAltitude, prev);
        }
        return highestAltitude;        
    }
};