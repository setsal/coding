class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            if (n % 2)
                count++;
            
            n /= 2;
        }
        return count;
    }
};

// int hammingWeight(uint32_t n) {
//   int count=0;
//   while(n)
//   {
//     count+=n&1; 
//     n>>=1;
//   }
//   return count;
// }

// int hammingWeight(uint32_t n) {
//   int count=0;
//   while(n)
//   {
//     n &= (n-1);
//     count++;
//   }
//   return count;
// }