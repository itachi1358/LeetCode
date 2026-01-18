class Solution {
public:
    int findMin(vector<int>& nums) {
        // int s=0;
        // int e=nums.size()-1;
        // while(s<e){
        //     if(nums[s]<=nums[e]){
        //         return nums[s];
        //     }
        //     int mid=s+(e-s)/2;
        //     if(nums[mid]>= nums[s]){
        //         s=mid+1;
        //     }else{
        //         e=mid;
        //     }
        // }
        // return nums[s];

        int n=nums.size();
        int l=0,r=n-1;
        int ans=0;
        if(nums[r]>nums[l]) return nums[l];
        while(l<r){
            int mid=l+((r-l)/2);
            if(nums[mid]>nums[r]){
                l=mid+1;
              //  ans=mid;
            }
            else if(nums[mid]<nums[r]){
                r=mid;
            }
            else {
                r--;
            }
        }
           return nums[l];
    }
};