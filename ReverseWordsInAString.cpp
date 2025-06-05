class Solution {
public:
    string reverseWords(string s) {

        string answer = "";

        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++){
            string word = "";
            while(i < s.size() && s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.size() > 0) answer += " " + word;
        }

        cout << "answer: " << answer << endl;

        return answer.substr(1);    
    }
};