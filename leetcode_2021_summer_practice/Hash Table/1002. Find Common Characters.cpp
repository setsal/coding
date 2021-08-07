class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        int hash[26] = {0};
        
        if ( words.size() == 0 ) return result;
    
        for (int i = 0; i < words[0].size(); i++) {
            hash[words[0][i] - 'a']++;
        }
        
        
        for (int i = 1; i < words.size(); i++) {
            int hash2[26] = {0};
            for (int j = 0; j < words[i].size(); j++) {
                hash2[words[i][j] - 'a']++;
            }
            
            for (int k = 0; k < 26; k++) {
                hash[k] = min(hash[k], hash2[k]);
            }
        }
        
        for (int i = 0; i < 26; i++) {
            while (hash[i] != 0) {
                string s(1, i + 'a');
                result.push_back(s);
                hash[i]--;
            }
        }
        return result;
    }
};