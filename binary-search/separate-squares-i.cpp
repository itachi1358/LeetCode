class Solution {
public:
    double calculateAreaAbove(vector<vector<int>> &sq,double &y){
        double area=0;
        for(auto square:sq){
            int xc=square[0];
            int yc=square[1];
            int len=square[2];
            if( yc + len <= y) continue;
            
            if(yc<= y && y< yc+len ){
                area+= (len)*(yc+len-y);
            }
            else{
                area+=(len*len);
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double total_area=0;
        for(auto square:squares){
            int length=square[2];
            total_area+=(length)*(length);
        }
        double target=total_area/2;
        double low=0,high=2e9;
        for (int i = 0; i < 80; i++) {
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