class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int asteroid : asteroids){
            int flag = 1;
            while(!st.empty() && st.top() > 0 && asteroid < 0){
                if(abs(asteroid) > st.top()){
                    st.pop();
                    continue;
                }else if (abs(asteroid) == st.top()) st.pop();

                flag = 0;
                break;
            }
            if(flag) st.push(asteroid);
        }

        vector<int> answer(st.size());
        for(int i = answer.size() - 1; i >= 0; i--){
            answer[i] = st.top(); st.pop();
        }

        return answer;       
    }
};