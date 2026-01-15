class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int a=arr1[0];
        int n=arr1.size();
        int m=arr2.size();
        for(auto num:arr1) a=a^num;
        for(auto num:arr2) a=a^num;

        vector<int> xor_v(31,0);
        
        for(int i=30;i>=0;i--){
            int n_set=0,m_set=0;
            for(auto num:arr1){
                if( (num & (1<<i)) != 0){
                    n_set++;
                }
            }
            for(auto num:arr2){
                if( (num&(1<<i)) !=0 ){
                    m_set++;
                }
            }

            long long x=(long long)n_set*m_set;
            if(x%2==1){
                xor_v[i]=1;
            }
        }
         int ans=0;
        for(int i=30;i>=0;i--){
            if(xor_v[i]==1){
                ans|=(1<<i);
            }
        }  
        return ans;
    }
};