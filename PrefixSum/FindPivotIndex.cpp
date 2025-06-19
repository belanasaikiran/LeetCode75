class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int Lsum = 0;
        int Rsum = 0;
        for(int i = 0; i < nums.size(); i++){
            Rsum += nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
            Rsum = Rsum - nums[i];
            if(Lsum == Rsum) return i;
            Lsum = Lsum + nums[i];
        }

        return -1;
    }
};