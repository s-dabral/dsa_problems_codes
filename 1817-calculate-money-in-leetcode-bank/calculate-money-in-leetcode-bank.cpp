class Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(i/7+1)+(i%7);
        }
        return sum;
    }
};