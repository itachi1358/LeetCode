class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
       int n=nums.size();
        vector<int > ans(n);
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
           int a= INT_MAX;
            int x=0;
            for (int b=31;b>=0;b--){
                if ((num&(1<<b) )!=0){
                    x|=(1<<b);
                    if((x|x-1)==num){
                        a=min(a, x-1);
                    }
                }
            }
            if(a==INT_MAX){
                ans[i]=-1;
            }
            else{
            ans[i]=a;
            }
            
        }
        return ans;
    }
};