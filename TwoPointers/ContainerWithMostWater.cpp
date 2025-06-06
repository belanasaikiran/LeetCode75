class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left <= right ){
            int currentWater = (right - left)  * min(height[left], height[right]);
            maxWater = max(maxWater, currentWater);     
            if(height[left] < height[right]) left++;
            else right--;
        }

        return maxWater;
    }
};