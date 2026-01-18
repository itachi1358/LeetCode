/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int mid_finder(MountainArray& arr) {
        int s=0;
        int e=arr.length()-1;
        while(s<=e){
            int mid=s+((e-s)/2);
            int md=arr.get(mid);
            int md1=arr.get(mid+1);
            int mdminus1=arr.get(mid-1);

            if(md>md1 && md>mdminus1){
                return mid;
            }
            else if(md<md1 && md>mdminus1 ){
                s=mid+1;
            }
            else if(md>md1 && md<mdminus1){
                e=mid;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int s=0;
        int e=mid_finder(mountainArr);
        int ans1=INT_MAX;
        int ans2=INT_MAX;
        while(s<=e){
            int m=s+((e-s)/2);
            int x=mountainArr.get(m);
            if(x==target){
                ans1=m;
                break;
            }
            else if(x>target){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        int st=mid_finder(mountainArr);
        int ed=mountainArr.length()-1;
        while(st<=ed){
            int m=st+((ed-st)/2);
            int x=mountainArr.get(m);
            if(x==target){
                ans2=m;
                break;
            }
            else if(x<target){
                ed=m-1;
            }
            else{
                st=m+1;
            }
        }
        if(ans1==INT_MAX && ans2==INT_MAX){
            return -1;
        }
        return min(ans1,ans2);
    }
};