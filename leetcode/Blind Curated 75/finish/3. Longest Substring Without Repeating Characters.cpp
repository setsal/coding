class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (s.size() == 0)  return 0;
        
        int slow = 0;
        int fast = 0;
        
        unordered_map<int, int> umap;
        int max_length = 0;
        
        while (fast < s.size()) {
            while ( fast < s.size() && !umap.count(s[fast])) {
                umap[s[fast]] = 1;
                fast++;
            }
            
            
            max_length = umap.size() > max_length ? umap.size() : max_length;
            // max_length = std::max(umap.size(), max_length);
            
            umap.erase(s[slow]);
            
            slow++;
            
        }
        return max_length;
    }
};