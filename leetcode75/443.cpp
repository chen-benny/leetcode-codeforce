class Solution {
public:
    int compress(vector<char>& chars) {
        /*
         * Return new length of compressed string, compress in place
         * Compress: "abbccc" -> "ab2c3"
         *
         * Two pointers: read and write in place
         * T: O(n)
         * S: O(1)
         */
        int n = chars.size();
        int write = 0;
        int read = 0;

        while (read < n) {
            char cur = chars[read];
            int cnt = 0;

            while (read < n && chars[read] == cur) {
                read++;
                cnt++;
            }

            chars[write++] = cur;
            if (cnt > 1) {
                /*
                int digits[10];
                int len = 0;
                while(cnt) {
                    digits[len++] = cnt % 10;
                    cnt /= 10;
                }
                for (int i = len - 1; i >=0; i--) {
                    chars[write++] = digits[i] + '0';
                }   
                */
                string d = to_string(cnt);
                for (char c : d) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};
