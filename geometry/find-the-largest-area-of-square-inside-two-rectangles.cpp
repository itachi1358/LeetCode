class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        int sx=bottomLeft[0][0]+1;
        int sy=bottomLeft[0][1]+1;
        long long ans=0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                long long x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long y1 = max(bottomLeft[i][1], bottomLeft[j][1]);

                long long x2 = min(topRight[i][0], topRight[j][0]);
                long long y2 = min(topRight[i][1], topRight[j][1]);

                long long w = max(0LL, x2 - x1);
                long long h = max(0LL, y2 - y1);

                long long side = min(w, h);
                ans = max(ans, side * side);
            }
        }
        return ans;
    }
};