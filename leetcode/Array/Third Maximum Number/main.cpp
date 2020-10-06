class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long first_max = LONG_MIN;
        long second_max = LONG_MIN;
        long third_max = LONG_MIN;

        for ( int i=0; i<nums.size(); i++ ) {
            if ( nums[i] > first_max ) {                
            // move old max value
                third_max = second_max;
                second_max = first_max;

                first_max = nums[i];                
            }
            else if ( nums[i] < first_max && nums[i] > second_max ) { 
                third_max = second_max;
                second_max = nums[i];
            }            
            else if ( nums[i] < second_max && nums[i] > third_max ) {
                third_max = nums[i];
            }                           

        }

        if ( third_max == LONG_MIN || second_max == LONG_MIN ) return first_max;

        return third_max;
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()-1-2];
        // if ( nums.size() <=2 ) { return }
    }
};