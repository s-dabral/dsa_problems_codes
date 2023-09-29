class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1;
        int max_ans = INT_MIN;
        while(start < end) {
            int curr_ans = (end-start)*min(height[start], height[end]);
            max_ans = max(curr_ans, max_ans);
            if(height[start] < height[end])
                start++;
            else
                end--;
        }
        return max_ans;
    }
};