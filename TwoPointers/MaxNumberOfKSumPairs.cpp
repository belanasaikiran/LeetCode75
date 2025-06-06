class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        int left = 0, right = nums.size() - 1;
        int counter = 0;

        sort(nums.begin(), nums.end()); // not optimal because of this sorting takes O(n log n)
        while(left < right){
            int sum =  nums[left] + nums[right];
            if(sum > k) right--;
            else if(sum < k) left++;
            else {
                counter++;
                nums.erase(nums.begin() + left);
                nums.erase(nums.begin() + right);
                right--; right--;
            }
        }


        for(auto number : nums){
            cout << number << " ";
        }

        return counter;

  }
    // Time: O(n) - if I don't need to delete from array, I could get away with a hash map (no use of two pointers)
    int maxOperationsUsingHash(vector<int>& nums, int k) {
        int counter = 0;
        unordered_map<int, int> numMap;
        for(auto number: nums){
            int compliment = k - number;
            if(numMap[compliment] > 0){
                counter++;
                numMap[compliment]--;
            } else{
                numMap[number]++;
            }
        }

        return counter;
    };


  
};