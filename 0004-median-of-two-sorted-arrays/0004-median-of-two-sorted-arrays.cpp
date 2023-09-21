class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        vector<int> nums(n+m);

        int index=0;
        int l=0;
        int r=0;
        while(l<n && r<m){
            if(nums1[l]<=nums2[r]){
                nums[index++]=nums1[l++];
            }
            else{
                nums[index++]=nums2[r++];
            }
        }
        while(l<n){
            nums[index++]=nums1[l++];
        }
        while(r<m){
            nums[index++]=nums2[r++];
        }

        double ans;
        int mid = (n+m)/2;
        if((n+m)%2==0){
            ans= (nums[mid] + nums[mid-1])/2.0;
        }
        else{
            ans= nums[mid];
        }
        return ans;
    }
};