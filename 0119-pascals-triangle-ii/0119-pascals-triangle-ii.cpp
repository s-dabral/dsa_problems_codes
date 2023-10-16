class Solution {
public:
long long int ncr(int n,int r){
    long long int ans=1;
    for(int i=0;i<r;i++){
        ans=ans*(n-i);
        ans=ans/(i+1);

    }
    return ans;
} 
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i=0;i<=rowIndex;i++){
            res.push_back(ncr(rowIndex,i));
        }
        return res;
    }
};