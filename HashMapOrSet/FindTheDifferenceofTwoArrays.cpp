class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num1Set(nums1.begin(), nums1.end());
        unordered_set<int> num2Set(nums2.begin(), nums2.end());


        vector<int> answer1, answer2;
        for (auto number : num1Set) {
            if (!num2Set.contains(number)) {
                answer1.push_back(number);
            }
        }

        for (auto number : num2Set) {
            if (!num1Set.contains(number))
                answer2.push_back(number);
        }

        return {answer1, answer2};
    }
};