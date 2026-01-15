class Solution {
public:
    void build_tree(int i,int l,int r,vector<int> &seg,vector<int> &nums){
        if(l==r){
            seg[i]=nums[l];
            return;
        }
        int mid= (l+r)/2;
        build_tree(2*i +1,l,mid,seg,nums);
        build_tree(2*i+2,mid+1,r,seg,nums);

        seg[i]=max(seg[2*i + 1 ], seg[2*i + 2]);
    }

    int getMax(int i,int l,int r,int given_l,int given_r,vector<int> &seg){
        if(l>given_r || r<given_l) return INT_MIN;

        if(l>=given_l && r<=given_r){
            return seg[i];
        }
        int mid=(l+r)/2;
        return max(getMax(2*i + 1,l,mid,given_l,given_r,seg),getMax(2*i + 2,mid+1,r,given_l,given_r,seg));
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        deque<int> dq;
        for(int i=0;i<n;i++){

            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};