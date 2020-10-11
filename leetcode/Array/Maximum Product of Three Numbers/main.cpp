class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int first=-1000, second=-1000, third=-1000;
        int first_negative = 1000, second_negative = 1000;

        for ( int i=0; i<nums.size(); i++ ) {
            if ( nums[i] >= first ) {
                third = second;
                second = first;
                first = nums[i];
            }
            else if ( nums[i] >= second && nums[i] < first ) {
                third = second;
                second = nums[i];
            }
            else if ( nums[i] >= third && nums[i] < second ) {
                third = nums[i];
            }

            if ( nums[i] <= first_negative ) {
                second_negative = first_negative;
                first_negative = nums[i];
            }
            else if ( nums[i] <= second_negative && nums[i] > first_negative ) {
                second_negative = nums[i];
            }
        }

        
        return max(first*second*third, first_negative*second_negative*first);
    }
};