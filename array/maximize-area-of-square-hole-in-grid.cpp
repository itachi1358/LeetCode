class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        sort(hBars.begin(),hBars.end());
         sort(vBars.begin(),vBars.end());
         long long area=0;
         long long len=1,bth=1;
         long long l=1,b=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==hBars[i-1]+1){
                l++;
            }
            else{
                l=1;
            }
            len=max(len,l);
        }

        for(int j=1;j<vBars.size();j++){
            if(vBars[j]==vBars[j-1]+1){
                b++;
               
            }
            else{
                b=1;
            }
            bth=max(bth,b);
        }
        int sid=min(len,bth)+1;
        area=sid*sid;
        return area;
    }

};