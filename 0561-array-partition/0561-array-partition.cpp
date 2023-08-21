class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size()-1;i+=2){
            int minm=0;
            minm=min(nums[i],nums[i+1]);
            ans+=minm;

        }
        return ans;
    }
};