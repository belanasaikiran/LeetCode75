class Solution {
public:
    bool closeStrings(string word1, string word2) {
        array<int, 26> c1;
        array<int, 26> c2;
        for (char c : word1) c1[c - 'a']++;
        for (char c : word2) {
            c2[c - 'a']++;
            if (!c1[c - 'a']) return false; // just checks if that letter doesn't exist in c1
        }
        sort(c1.begin(), c1.end()); // O(26 log 26) = O(n)
        sort(c2.begin(), c2.end());

        return c1 == c2;
    }
};