#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string decodeString(string s) {
        vector<int> cntStk;
        vector<string> strStk;
        string cur = "";
        int cnt = 0;

        for (char c : s) {
            if (isdigit(c)) {
                cnt = cnt * 10 + (c - '0');
            } else if (c == '[') {
                cntStk.push_back(cnt);
                strStk.push_back(cur);
                cnt = 0;
                cur = "";
            } else if (c == ']') {
                string tmp = cur;
                cur = strStk.back();
                strStk.pop_back();

                int n = cntStk.back();
                cntStk.pop_back();
                for (int i = 0; i < n; i++) {
                    cur += tmp;
                }
            } else {
                cur += c;
            }
        }

        return cur;
    }
};

// follow-up: recursion
class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        return decode(s, idx);
    }

private:
    string decode(const string& s, int& idx) {
        string res;
        res.reserve(s.length());

        while (idx < s.length() && s[idx] != ']') {
            if (!isdigit(s[idx])) {
                res += s[idx++];
            } else {
                int cnt = 0;
                while (idx < s.length() && isdigit(s[idx])) {
                    cnt = cnt * 10 + s[idx++] - '0';
                }

                ++idx; // skip '['
                string decoded = decode(s, idx);
                ++idx; // skip ']'

                size_t sz = res.size();
                res.resize(sz + decoded.size() * cnt);

                for (int i = 0; i < cnt; i++) {
                    for (size_t j = 0; j < decoded.size(); j++) {
                        res[sz + i * decoded.size() + j] = decoded[j];
                    }
                }
            }
        }

        return res;
    }
};
