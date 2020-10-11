class Solution {
public:
    string countAndSay(int n) {
        if ( n== 1 ) {
            return "1";
        }

        // Recursion call
        string s = countAndSay(n-1) + "?";
        
        
        string res;
        int times = 1;
        
        for( auto it = s.begin(); it != s.end()-1; it++ ) {
            if( *it == *(it+1) ) {
                times++;
            } else {
                res = res + to_string(times) + *it;
                times = 1;
            }
        }
        return res;
    }
};