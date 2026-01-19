class Solution {
public:
    bool possible(int i,int j,int k,int threshold,vector<vector<int>> &pref){
        if(i<k || j<k) return false;

        int current_sum = pref[i][j] - pref[i-k][j] - pref[i][j-k] + pref[i-k][j-k];
        return current_sum<=threshold;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int len=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> pref(n+1,vector<int> (m+1,0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int l=0,r=min(n,m);
                while(l<=r){
                    int mid=l+((r-l)/2);
                    if(possible(i,j,mid,threshold,pref)){
                        len=max(len,mid);
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
            }
        }
        return len;
    }
};