// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


class Solution{
    int lonestOnes{
        int longest = 0;

        // Sliding Window Approach
        // left and right. Use right to traverse and use left if we exhaust the k zeroes ( when zeroCount > k)
        int zeroCount = 0;
        int left = 0;
        int right;
        for(right = 0; right < nums.size(); right++){
            if(nums[right] == 0) zeroCount++;

            // when I exhaust all the k zeroes to replace with 1, we calcuale the longest for that period and move the window (left++)
            if(zeroCount > k){
                if(nums[left] == 0) zeroCount--; // we are getting rid of first element and removing if it's a zero
                left++;
            }
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
}


// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {

//         // O(n) Solution for time
//         int left = 0;
//         int longest = 0;
//         int zeroCount = 0;

//         for(int right = 0; right < nums.size(); right++){
//             if(nums[right] == 0){
//                 zeroCount++;
//             }
//             if(zeroCount > k){
//                 if(nums[left] == 0) zeroCount--;
//                 left++;
//             }
//             longest = max(longest, right - left + 1);
//         }

//         return longest;
//     }
        
//     // This is O(n^2)
//     //     int longest = 0;
//     //     int remainingKs = k;
//     //     int i = 0;
//     //     int counter = 0;
//     //     int j = i;
//     //     while(i < nums.size()){
//     //         if(j < nums.size() && ((nums[j] == 1) || (nums[j] == 0 && remainingKs > 0))){
//     //             counter++;
//     //             if(nums[j] == 0) remainingKs--;
//     //             j++;
//     //         } else{
//     //             longest = max(longest, counter);
//     //             counter = 0;
//     //             remainingKs = k;
//     //             i++;
//     //             j  = i;
//     //         }
//     //     }
//     //     return longest;
        
// };