class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;
        unordered_map<string, int> umap;
        
        int length = strs.size();
        
        for (string str : strs) {
            
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            
            if (!umap.count(tmp)) {
                umap[tmp] = res.size();
                res.push_back({});
            }
            res[umap[tmp]].push_back(str);
        }
        
        
        return res;
    }
};