class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return c == 'a' ||  c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {

        int maxVowelsCount = 0;

        int currentVowelCount = 0;
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])){
                currentVowelCount++;
            }
        }
        maxVowelsCount = max(currentVowelCount,  maxVowelsCount);

        for(int i = k; i < s.length(); i++){
            if(isVowel(s[i - k])) currentVowelCount--;
            if(isVowel(s[i])) currentVowelCount++;
            maxVowelsCount = max(currentVowelCount, maxVowelsCount);
        }

        return maxVowelsCount;
        
    }
};