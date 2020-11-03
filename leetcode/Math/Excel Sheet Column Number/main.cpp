class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        int sum = 0;
        for ( int i=0; i<len; i++ ) {
            sum += pow(26,len-1-i) * (s[i] - '@');
            // cout << pow(26,i) << " " << s[i] << " " << (s[i] - '@') << " " << sum << endl;
        }
        return sum;
    }
};