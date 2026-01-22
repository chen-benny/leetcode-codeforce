class Solution {
public:
    int maxVowels(string s, int k) {
        /*
         * Return the max num of vowels letters in any sub str of size k in string s
         *
         * Sliding window to exhaust all num of vowels letter in sub str
         * Vowel test: loopkup table of char-index[]
         */
        bool vowels[128] = {};
        vowels['a'] = vowels['e'] = vowels['i'] = vowels['o'] = vowels['u'] = true;

        int winCnt = 0;
        for (int i = 0; i < k; i++) {
            if (vowels[s[i]]) {
                winCnt++;
            }
        }

        int maxCnt = winCnt;
        for (int i = k; i < s.size(); i++) {
            if (vowels[s[i]]) {
                winCnt++;
            }
            if (vowels[s[i - k]]) {
                winCnt--;
            }
            maxCnt = max(maxCnt, winCnt);
            if (maxCnt == k) { // early exit
                return k;
            }
        }

        return maxCnt;
    }
};
