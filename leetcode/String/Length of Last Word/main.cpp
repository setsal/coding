class Solution {
public:
    int lengthOfLastWord(string s) {
        int ptr = s.size() - 1;
        int cnt = 0;        
        while ( ptr>=0 && s[ptr] == ' ') {
            ptr--;
        }

        while ( ptr>=0 && s[ptr] != ' ') {
            ptr--;
            cnt++;
        }

        return cnt;
    }
};