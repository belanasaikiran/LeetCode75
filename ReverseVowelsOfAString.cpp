// Time: O(n); Space: O(n)
// class Solution {
// public:
//     string reverseVowels(string s) {
//         string answer = s;

//         unordered_set<char> vs({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}); // VS - Vowel Set

//         int left = 0;
//         int right = s.length() - 1;


//         while(left < right){
//             if(!vs.count(s[left])) left++;
//             if(!vs.count(s[right])) right--;

//             if(vs.count(s[left]) && vs.count(s[right])) {
//                 answer[left] = s[right];
//                 answer[right] = s[left];
//                 left++;
//                 right--;
//             }  

//         }

//         return answer;       
//     }
// };

// Time: O(n); Space: O(1)
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vs({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}); // VS - Vowel Set
        int left = 0;
        int right = s.length() - 1;


        while(left < right){
            if(!vs.count(s[left])) left++;
            if(!vs.count(s[right])) right--;

            if(vs.count(s[left]) && vs.count(s[right])) {
                char swap = s[left];
                s[left] = s[right];
                s[right] = swap;
                left++;
                right--;
            }  

        }

        return s;       
    }
};