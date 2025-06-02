class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1)
            return "";

        int len1 = str1.length();
        int len2 = str2.length();
        while (len2 != 0) {
            int temp = len1 % len2;
            len1 = len2;
            len2 = temp;
        }

        int lenGCD = len1; // len1 is the remainder now.

        return str1.substr(0, lenGCD);
    }
};