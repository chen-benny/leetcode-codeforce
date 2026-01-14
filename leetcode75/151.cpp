class Solution {
public:
    string reverseWords(string s) {
        /*
         * Reverse the words in string
         *
         * Two Pointers: start reading from backward, each time append one word
         * Clean leading, trailing and extra spaces
         * T: O(n)
         * S: O(n)
         */
        int n = s.size();
        int end = n - 1;
        int start;
        string res;
        res.reserve(n);

        while (end >= 0) {
            while (end >= 0 && s[end] == ' ') {
                end--;
            }
            if (end < 0) {
                break;
            }

            start = end;
            while (start >= 0 && s[start] != ' ') {
                start--;
            }

            if (!res.empty()) {
                res += ' ';
            }
            res.append(s, start + 1, end - start);
            end = start;
        }
        return res;
    }
};

// follow-up: O(1) space
class Solution {
public:
    string reverseWords(string s) {
        /*
         * Reverse all characters and then reverse per word
         * Two pointers: read, write
         */
        reverse(s.begin(), s.end());

        int n = s.size();
        int write = 0;
        for (int read = 0; read < n; read++) {
            if (s[read] == ' ') {
                continue;
            }

            if (write != 0) {
                s[write++] = ' ';
            }

            int start = write;
            while (read < n && s[read] != ' ') {
                s[write++] = s[read++];
            }
            reverse(s.begin() + start, s.begin() + write);
        }
        s.resize(write);
        return s;
    }
};
