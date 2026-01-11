class Solution {
public:
    vector<int>  pse(vector<int> &v){
        stack<int> st;
        int n=v.size();
        vector<int> ans(n);

        for(int i=0;i<v.size();i++){
            if(st.empty()){
                st.push(i);
                ans[i]=-1;
            }
            else{
                while(!st.empty() && v[st.top()]>=v[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i]=-1;
                }
                else{
                    ans[i]=st.top();
                }
                st.push(i);
            }
        }
        return ans;
    }
    vector<int> nse(vector<int> &v){
        stack<int> st;
        int n=v.size();
        vector<int> ans(n);

        for(int i=v.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
                ans[i]=-1;
            }
            else{
                while(!st.empty() && v[st.top()]>=v[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i]=-1;
                }
                else{
                    ans[i]=st.top();
                }
                st.push(i);
            }
        }
        return ans;
    }

    int findMaxArea(vector<int> &v,vector<int> &pse,vector<int> &nse){
        int m=v.size();
        int area=0;
        for(int i=0;i<m;i++){
            int left=pse[i];
            int right=nse[i];
            if(right==-1) right=m;
            area=max(area,(right-left-1)*v[i]);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> prev(m);
        for(int i=0;i<m;i++){
            prev[i]=matrix[0][i]-'0';
        }
        vector<int> ipse=pse(prev);
        vector<int> inse=nse(prev);
        int area=findMaxArea(prev,ipse,inse);
        for(int i=1;i<n;i++){
            
            vector<int> a(m);
         
            for(int  idx=0;idx<m;idx++){
                if(matrix[i][idx]=='1'){
                    a[idx]=prev[idx]+ (matrix[i][idx]-'0');
                }
                else{
                    a[idx]=0;
                }
            }
        
            vector<int> previous_se=pse(a);
            vector<int> next_se=nse(a);

            area=max(area,findMaxArea(a,previous_se,next_se));
            prev=a;
        }
        return area;
    }
};