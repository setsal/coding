class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        
        digits[len-1] = digits[len-1] + 1;
        
        int i;
        
        for ( i=len-1; i>0; i-- ) {
            if ( digits[i] == 10 ) {
                 digits[i] = 0;
                 digits[i-1] = digits[i-1] + 1;
            }
        }
    
        if ( digits[0] == 10 ) {
            digits.insert( digits.begin(), 1 );
            digits[1] = 0;
        }
        return digits;
    }
};