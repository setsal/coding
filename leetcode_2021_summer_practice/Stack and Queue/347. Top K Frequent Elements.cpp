class Solution {
public:
    
    class myComparison {
    public:
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pri_que;
        
        for(auto item : map) {
            pri_que.push(item);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};