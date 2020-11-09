class Solution {
public:
    string addStrings(string num1, string num2) {
        int c1, c2, sum;
        int m = num1.size()-1 , n = num2.size()-1 , carry = 0;
        string res = "";

        while ( m>=0 || n>=0 || carry == 1 ) {
            
            // reset 
            c1 = 0;
            c2 = 0;
            
            if ( m>=0 ) {
                c1 = num1[m] - '0';
                m--;
            }

            if ( n>=0 ) {
                c2 = num2[n] - '0';
                n--;
            }

            sum = c1 + c2 + carry;

            // insert 
            res.insert(res.begin(), sum%10+'0');

            // carry
            carry = sum/10;
        }

        return res;
    }

};