class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<long long> diff(n);

        for(int i = 0; i < n; i++){
            diff[i] = (long long)target[i] - nums[i];
        }

        long long ans = 0;

        long long prevPos = 0, prevNeg = 0;

        for(int i = 0; i < n; i++){
            long long pos = max(0LL, diff[i]);     // need increments
            long long neg = max(0LL, -diff[i]);    // need decrements

            ans += max(0LL, pos - prevPos);
            ans += max(0LL, neg - prevNeg);

            prevPos = pos;
            prevNeg = neg;
        }

        return ans;
    }
};
