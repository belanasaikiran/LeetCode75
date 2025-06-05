class Solution {
public:
    int compress(vector<char>& chars) {

        int counter = 0;
        int vectorIndex = 0;
        for(int i = 0; i < chars.size(); i++){
            // first element
            if(i == 0) counter = 1;
            else if(i > 0 && chars[i] == chars[i - 1]) counter++;
            else if (chars[i] != chars[i - 1]){
                chars[vectorIndex++] = chars[i - 1]; 
                if(counter > 1){
                    string str = to_string(counter); 
                    for(char c: str) chars[vectorIndex++] = c; 
                } 
                counter = 1;
            } 


            // last element
            if(i == chars.size() - 1) 
            {
                chars[vectorIndex++] = chars[i];
                if(counter > 1) {
                    string str = to_string(counter); 
                    for(char c: str) {
                        chars[vectorIndex++] = c;
                    }
                }
            }
        }

        chars.erase(chars.begin() + vectorIndex, chars.end());
        return vectorIndex;
    }
};