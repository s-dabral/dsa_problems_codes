class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      
        unordered_map<int, vector<int>> map1; // Create an unordered_map to store the numbers based on their parity

        // Iterate through the input vector nums
        for(auto x : nums){
            map1[x % 2].push_back(x); // Group the numbers based on their parity using modulo operator and store them in the map
        }

        // Check if there are no odd numbers in the input vector
        if(map1.find(1) == map1.end())
            return map1[0]; // Return the vector of even numbers

        // Check if there are no even numbers in the input vector
        if(map1.find(0) == map1.end())
            return map1[1]; // Return the vector of odd numbers

        // Concatenate the vectors of even and odd numbers and store the result in the vector ret
        map1[0].insert(map1[0].end(), map1[1].begin(), map1[1].end());

        return map1[0]; // Return the sorted vector
    }
};