class Solution {
public:
    // Helper to find the maximum consecutive sequence length in a sorted vector
    int getMaxConsecutive(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int max_consecutive = 1;
        int current_consecutive = 1;
        
        for (int i = 1; i < bars.size(); ++i) {
            if (bars[i] == bars[i - 1] + 1) {
                current_consecutive++;
            } else {
                current_consecutive = 1;
            }
            max_consecutive = max(max_consecutive, current_consecutive);
        }
        return max_consecutive;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // Gap size = number of consecutive bars + 1
        int maxH = getMaxConsecutive(hBars) + 1;
        int maxV = getMaxConsecutive(vBars) + 1;
        
        int side = min(maxH, maxV);
        return side * side;
    }
};