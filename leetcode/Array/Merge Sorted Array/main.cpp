class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i;
        int ptr = m+n-1;
        n = n-1;
        m = m-1;
        
        while ( n>=0 ) {
            if ( m == -1 || nums1[m] < nums2[n] ) {
                nums1[ptr] = nums2[n];
                n--;
            } else {
                nums1[ptr] = nums1[m];
                m--;
            }
            ptr--;
        }
        
    }
};