class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        
        // count each alphbet in magazine
        for (char c : magazine) {
            m[c]++;
        }

        // check 
        for (char c : ransomNote) {
            if ( m[c] == 0 ) {
                return false;
            }
            m[c]--;
        }

        return true;        
    }
};