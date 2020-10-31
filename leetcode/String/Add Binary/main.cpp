class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size()-1, n = b.size()-1;
        int carry = 0;

        string res = "";
        

        while( m>=0 || n>=0 || carry==1 )
        {
            if ( m >= 0 ) {
                carry += a[m--] - '0';
            } 
            else {
                carry += 0;
            }

            if ( n>=0 ) {
                carry += b[n--] - '0';
            }
            else {
                carry += 0;
            }
            
            res = char( carry%2 + '0' ) + res;
            carry /= 2;
        }
        
        return res;
    }
};