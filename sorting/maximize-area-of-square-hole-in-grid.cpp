class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        hBars.push_back(n+2);
        hBars.push_back(1);
        vBars.push_back(m+2);
        vBars.push_back(1);
        sort(hBars.begin(),hBars.end());
         sort(vBars.begin(),vBars.end());
         long long area=0;
         long long len=0,bth=0;
         long long l=1,b=1;
        for(int i=1;i<hBars.size()-1;i++){
            if(hBars[i+1]==hBars[i]+1){
                l++;
                len=max(len,l);
            }
            else{
                l=1;
            }
        }

        for(int j=1;j<vBars.size()-1;j++){
            if(vBars[j+1]==vBars[j]+1){
                b++;
                bth=max(bth,b);
            }
            else{
                b=1;
            }
        }
        area=min(len,bth)*min(len,bth);
        area=max(area,4LL);
        return area;
    }

};