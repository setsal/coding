class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        
        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i] - 'a']++;
        }
        
        for (int j = 0; j < ransomNote.length(); j++) {
            record[ransomNote[j] - 'a']--;
            if (record[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};