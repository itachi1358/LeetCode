class Solution {
public:
        //trick : you can literally xor any 2 nodes in the tree without changing the other nodes
        
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0;
        int xors=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int last=n-1;
        for(int i=n-1;i>=0;i--){
            if((nums[i]^k) > nums[i]){
                xors++;
                nums[i]^=k;
                last=i;
            }
        }
        if(xors%2==1){
            nums[last]^=k;
        }
        return accumulate(nums.begin(),nums.end(),0LL);      
    }
};