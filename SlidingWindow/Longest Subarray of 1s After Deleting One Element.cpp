// This solution is an extension of previous problem where I set k = 1 and returning with longest - 1 (which says, it removed one element)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longest = 0;
        int zeroCount = 0;
        int left = 0;
        int right;
        for(right = 0; right < nums.size(); right++){
            if(nums[right] == 0) zeroCount++;
            if(zeroCount > 1){
                if(nums[left] == 0) zeroCount--;
                left++;
            }
            longest = max(longest, right - left + 1);
        }
        return longest - 1;
      }
};