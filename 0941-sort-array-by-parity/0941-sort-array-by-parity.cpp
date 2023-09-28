class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      
        unordered_map<int, vector<int>> map1; 

        for(auto x : nums){
            map1[x % 2].push_back(x); 
        }
        if(map1.find(1) == map1.end())
            return map1[0]; 

        if(map1.find(0) == map1.end())
            return map1[1]; 
        map1[0].insert(map1[0].end(), map1[1].begin(), map1[1].end());

        return map1[0];
    }
};