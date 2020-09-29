class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        // initial
        vector<int> res;

        // first element
        res.push_back(1);
        if ( rowIndex == 0 ) return res;

        // second element
        res.push_back(1);
        if ( rowIndex == 1 ) return res;
    
        int tmp;

        // third to last
        for(int i=1; i<=rowIndex-1; i++) {
            res.insert(res.begin()+1, res[1]);
            for ( int j=0; j<i; j++ ) {
                tmp = res[j+1];
                if ( j==0 ) {
                    res[j+1] = res[j]+res[j+2];
                }
                else {
                    res[j+1] = tmp+res[j+2];
                }
            }
        }

        return res;
    }
};