class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> answer(nums.size(), 1);

        int mult = 1;
        for(int i = 0; i < nums.size(); i++){
            answer[i] = mult;
            mult = mult * nums[i];
        }

        //  from reverse now
        mult = 1;
        for(int i = nums.size() - 1;i >= 0; i--){
            answer[i] = mult * answer[i];
            mult = mult * nums[i];
        }


        return answer;        
    }
};