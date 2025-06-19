class Solution {
public:
    string removeStars(string s) {
        string answer = "";
        for(char &c : s){
            if(c != '*'){
                answer.push_back(c);
            } else{
                answer.pop_back();
            }
        }
        return answer;        
    }
};