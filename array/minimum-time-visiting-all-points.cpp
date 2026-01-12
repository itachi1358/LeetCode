class Solution {
public:
    int distance(int x1,int y1,int x2,int y2){
        return max(abs(x2-x1),abs(y2-y1));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=1;i<points.size();i++){
            int x1=points[i-1][0];
            int x2=points[i][0];
            int y1=points[i-1][1];
            int y2=points[i][1];
            cout<<"distance when i = " <<i-1<<"is"<<distance(x1,y1,x2,y2)<<endl;
            ans+= distance(x1,y1,x2,y2);
        }
        cout<<(int)sqrt(13)<<endl;
        return ans;
    }
};