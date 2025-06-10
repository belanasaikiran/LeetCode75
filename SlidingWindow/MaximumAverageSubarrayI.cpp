class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        if(nums.size() <= k){
            for(int i = 0; i < nums.size(); i++){
                sum += nums[i];
            }
            return (double) sum / k;
        }


        for(int i = 0; i < k; i++){
                sum += nums[i];
        }
        double maxSum = sum;

        for(int i = k; i < nums.size(); i++){
                sum -= nums[i-k];
                sum += nums[i];
                if(sum > maxSum){
                    maxSum = sum;
                }
        }

        return maxSum / k;

    }
};