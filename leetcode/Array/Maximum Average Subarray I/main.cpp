class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // could be double sum = accumulate(nums.begin(), nums.begin() + k, 0) better 
        double sum = 0;
        for ( int i=0; i<k; i++ ) {
            sum += nums[i];
        }

        // first max
        double res = sum;

        for ( int i=k; i<nums.size(); i++ ) {
            sum -= nums[i-k];
            sum += nums[i];
            res = max(res, sum);
        }

        return res/k;
    }
};