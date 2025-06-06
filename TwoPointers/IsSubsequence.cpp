class Solution {
public:
    bool isSubsequence(string s, string t) {

        if(s.length() < 1)  return true;

        int slow = 0;
        int fast = 0;
        while(slow < s.length() && fast < t.length()){                                     
            if(s[slow] == t[fast]) {
                if(slow == s.length() - 1) return true;
                slow++; fast++;
            } else fast++;
        }

        return false;
    }
};