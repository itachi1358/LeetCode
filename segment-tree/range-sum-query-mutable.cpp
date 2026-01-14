class NumArray {
public:
    vector<int> seg;
    int n;
    NumArray(vector<int>& nums) {
        this->n=nums.size();
        seg.resize(4*n);
        build_tree(nums,0,0,n-1,seg);
    }

    void build_tree(vector<int>& arr,int i,int l,int r,vector<int> &seg){
        if(l==r){
            seg[i]= arr[l];
            return ;
        }

        int mid=(l+r)/2;
        build_tree(arr,2*i+1,l,mid,seg);
        build_tree(arr,2*i+2,mid+1,r,seg);

        seg[i]=seg[2*i + 1] +seg[2*i + 2];
    }


    void update_tree(int idx_to_update,int val,int i,int l,int r,vector<int> &seg){
        if(l==r){
            seg[i]=val;
            return;
        }
        int mid=(l+r)/2 ;
        if(idx_to_update<=mid){
            update_tree(idx_to_update,val,2*i+1,l,mid,seg);
        }
        else{
            update_tree(idx_to_update,val,2*i+2,mid+1,r,seg);
        }
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    void update(int index, int val) {
        update_tree(index,val,0,0,n-1,seg);
    }
    
    int calc_sum(int i,int l,int r,int given_l,int given_r,vector<int> &seg){
        if(l>given_r || r< given_l) return 0;

        if(l>=given_l && r<= given_r){
            return seg[i];
        }
        
        int mid=(l+r)/2;

        return calc_sum(2*i+1,l,mid,given_l,given_r,seg)+ calc_sum(2*i+2,mid+1,r,given_l,given_r,seg);
    }

    int sumRange(int left, int right) {
        return calc_sum(0,0,n-1,left,right,seg);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */