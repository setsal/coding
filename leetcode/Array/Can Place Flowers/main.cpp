class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if ( flowerbed.empty() ) return false;
        if ( flowerbed[0] == 0 ) flowerbed.insert(flowerbed.begin(), 0);
        if ( flowerbed[flowerbed.size()-1] == 0 ) flowerbed.push_back(0);


        int consecutive_zero_cnt = 0;
        int sum = 0;
        for ( int i=0; i<=flowerbed.size(); i++ ) {
            if ( i<flowerbed.size() && flowerbed[i] == 0 ) {
                consecutive_zero_cnt++;
            }
            else { 
                sum += (consecutive_zero_cnt-1)/2;
                consecutive_zero_cnt = 0;
            }
        }
        
        if ( sum >=n ) return true;
        return false;
    }
};