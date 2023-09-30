class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int length = nums.size();

        // Check if the array has less than 3 elements
        if (length < 3)
            return false;

        // Stack to keep track of decreasing elements.
        stack<int> decreasingStack;

        // Maximum value of the third element in the 132 pattern.
        int maxThirdElement = INT_MIN;

        // Traverse the array from right to left
        for (int i = length - 1; i >= 0; i--) {
            int currentNumber = nums[i];

            // Check for 132 pattern
            if (currentNumber < maxThirdElement)
                return true;  // Found a 132 pattern.

            // Maintain the stack with decreasing elements
            while (!decreasingStack.empty() && decreasingStack.top() < currentNumber) {
                maxThirdElement = decreasingStack.top();
                decreasingStack.pop();
            }

            // Push the current element onto the stack.
            decreasingStack.push(currentNumber);
        }

        return false; // No 132 pattern found
    }
};