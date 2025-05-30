class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0, p2 = 0;
        int w1Size = word1.length(), w2Size = word2.length();

        string answer = "";
        answer.reserve(w1Size+w2Size);
        while(p1 < w1Size || p2 < w2Size){
            if(p1 < w1Size){
                answer.push_back(word1[p1]);
                p1++;
            }

             if(p2 < w2Size){
                answer.push_back(word2[p2]);
                p2++;
            }
        }

        return answer;

        
    }
};
