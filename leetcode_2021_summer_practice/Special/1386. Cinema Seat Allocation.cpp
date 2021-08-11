class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b11110000;   // [2, 3, 4, 5]
        int middle = 0b11000011; // [4, 5, 6, 7]
        int right = 0b00001111;  // [6, 7, 8, 9]

        unordered_map<int, int> occupied;
        
        for (auto &seat: reservedSeats) {
            if (seat[1] >= 2 && seat[1] <= 9) {
                occupied[seat[0]] |= (1 << (seat[1] - 2));
            }
        }

        // caculate the [2,3,4,5] + [6,7,8,9] times
        int ans = (n - occupied.size()) * 2; 
        
        // caculate the occupied 
        for (auto& [row, bitmask]: occupied) {
            if (((bitmask | left) == left) || ((bitmask | middle) == middle) || ((bitmask | right) == right)) {
                ++ans;
            }
        }
        return ans;
    }
};
