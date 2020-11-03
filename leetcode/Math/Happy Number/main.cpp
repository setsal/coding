class Solution {
public:
    bool isHappy(int n) {
        int tmp = n;
        int sum = 0;
        while ( n!=0 ) {
            sum += pow(n%10,2);
            if ( sum == 1 ) return true;
            n = n/10;
        }
        

    }
};