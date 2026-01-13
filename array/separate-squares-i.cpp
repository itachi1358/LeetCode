class Solution {
public:
    long double calculateAreaAbove(vector<vector<int>> &sq,double &y){
        long double area=0;
        for (auto &square : sq) {
            long double yc = square[1];
            long double len = square[2];
            long double top = yc + len;

            if (top <= y) continue;             
            if (yc >= y) area += len * len;     
            else area += len * (top - y);       
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        long double total_area=0;
        for(auto square:squares){
            int length=square[2];
            total_area+=((long double)length)*((long double)length);
        }
        double target=total_area/2;
        double low=0,high=2e9;
        for (int i = 0; i < 49; i++) {
            double mid = (low + high) / 2.0;
            double abv_area = calculateAreaAbove(squares, mid);

            if (abv_area > target) {
                low = mid;
            } else {
                high = mid;    
            }
        }
        return high;
    }
};