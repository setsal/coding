class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;
        
        for (int num_1 : nums1) {
            for (int num_2 : nums2) {
                umap[num_1 + num_2]++;
            }
        }
        
        int count = 0;
        
        for (int num_3 : nums3) {
            for (int num_4 : nums4) {
                if (umap.find(0 - (num_3 + num_4)) != umap.end()) {
                    count += umap[0 - (num_3 + num_4)];
                }
            }
        }
        return count;
    }
};