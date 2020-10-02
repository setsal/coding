class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      for( int i=0; i<numbers.size(); i++ ) {
          for ( int j=i+1; j<numbers.size(); j++ ) {
              if ( numbers[i] + numbers[j] == target ) {
                  vector<int> res;
                  res.push_back(i+1);
                  res.push_back(j+1);
                  return res;
              }
          }
      }
      return vector<int>();
    }
};