class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int i = 0;
        while(n > 0 && i < flowerbed.size()){
                if(flowerbed[i] == 0){
                    bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
                    bool emptyRight = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                    if(emptyLeft && emptyRight) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                i++;
       }
        if(n > 0) return false;
        
        return true;
    }
};