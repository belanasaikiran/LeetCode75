class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       
        vector<bool> foreachKid(candies.size(), false);

        int Max = 0;

        for(int i = 0; i < candies.size(); i++){
            Max = max(candies[i], Max);
        }


        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= Max)  foreachKid[i] = true;
        }


        return foreachKid;
        
    }
};