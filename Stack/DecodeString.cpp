class Solution {
public:
    string decodeString(string s) {

        
        stack<char> st;
        stack<int> numbers;
        
        int k = 0;
        for(auto c: s){
            if(isdigit(c)){
                k = k * 10 + (c - '0');
            }else if(c == '['){
                 numbers.push(k);
                 k = 0;
                 st.push(c);
            }else if(c != ']'){
                st.push(c);
            }else{ // it has to be close bracket
                string temp = "";
                while(!st.empty() && st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop(); // remove "["
                string result = "";
                for(int i = 0; i < numbers.top(); i++){
                    result += temp; 
                }
                for(auto c : result){
                    st.push(c);
                }
                numbers.pop();
            }
        }
        string answer = "";
        while(!st.empty()){
            answer = st.top() + answer;
            st.pop();
        }
            return answer;      
    }
};