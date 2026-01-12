class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=1e9;
        for(int i=0;i<n;i++){
            int s=nums[i];
            int sum=target-s;
            int l=i+1,r=n-1;

            while(l<r){
                if( abs(target-(nums[i]+nums[l]+nums[r])) < abs(target-ans)){
                    ans=nums[i]+nums[l]+nums[r];
                }

                if(nums[l]+nums[r]>sum){
                    r--;
                }
                else if(nums[l]+nums[r]<sum){
                    l++;
                }
                else{
                    return target;
                }
            }
        }
        return ans;
    }
};