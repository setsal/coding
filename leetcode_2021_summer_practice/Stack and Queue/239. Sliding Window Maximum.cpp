class Solution {
    
private:
    class MyQueue {   // from big to small
    public:
        deque<int> myQue;
        
        void pop(int val) {
            if (!myQue.empty() && val == myQue.front()) {
                myQue.pop_front();
            }    
        }
        
        void push(int val) {
            while (!myQue.empty() && val > myQue.back()) {
                myQue.pop_back();
            }
            myQue.push_back(val);
        }
        
        int front() {
            return myQue.front();
        }
    };

    
public:    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);    
        }
        
        res.push_back(que.front());
        
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            // cout << "debug: " << nums[i - k] << endl;
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};