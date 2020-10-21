class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
    
        int len = nums.size(), degree = 0, res=50000;
        
        unordered_map<int, int> maps;

        unordered_map<int, pair<int, int>> pos;
        
        for ( int i=0; i<len; i++ ) {
            // add to maps
            maps[nums[i]]++;
            
            // record 
            if (maps[nums[i]] == 1) {
                // first location
                pos[nums[i]] = {i, i};
            } else {
                // last location
                pos[nums[i]].second = i;
            }
            
            // get the max degree
            degree = max(degree, maps[nums[i]]);
        }


        for ( auto map : maps ) {
            if ( map.second == degree ) {
                res = min(res, pos[map.first].second - pos[map.first].first + 1);
            }
        }
        return res;
    }
};