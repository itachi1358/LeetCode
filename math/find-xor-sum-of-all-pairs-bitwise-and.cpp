class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        
        // Iterate through all 31 possible bit positions
        for(int i = 0; i < 31; i++){
            long long count1 = 0;
            long long count2 = 0;

            // Count how many numbers in arr1 have the i-th bit set
            for(auto num : arr1){
                if((num >> i) & 1){ 
                    count1++;
                }
            }

            // Count how many numbers in arr2 have the i-th bit set
            for(auto num : arr2){
                if((num >> i) & 1){
                    count2++;
                }
            }

            // Total pairs contributing a '1' at this bit position
            long long pairs = count1 * count2;
            if(pairs % 2 == 1){
                ans |= (1 << i);
            }
        }
        
        return ans;
    }
};