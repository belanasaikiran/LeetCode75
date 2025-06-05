class Solution {
public:

    // not a brute force but it takes a long time compared to optimal

    void moveZeroesNotOptimal(vector<int>& nums) {
        //  Two Pointers
        int slow = 0;
        int fast = 1;
        while(slow < nums.size() && fast < nums.size()){
            if(nums[slow] == 0 && nums[fast] != 0){
                int swap = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = swap;
                slow++;
                fast = slow + 1;
            } else if(nums[slow] == 0 && nums[fast] == 0){
                fast++;
            } else{
                slow++;
                fast = slow + 1;
            }
        }

    }




    //  Optimal
    void moveZeroes(vector<int>& nums) {

        //  Two Pointers
        int slow = 0;
        int fast = 0;

        for(fast = 0; fast < nums.size(); fast++){
            if(nums[fast] != 0){
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }

    }
};