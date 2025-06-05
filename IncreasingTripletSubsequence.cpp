class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;

        int first = INT_MAX;
        int second = INT_MAX;

        for(auto number : nums){
            if(number <= first) first = number;
            else if(number <= second)second = number;
            else return true; // first < second < number           
        }
        return false;
    }
};