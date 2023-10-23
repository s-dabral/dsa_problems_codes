class Solution {
public:
    bool isPowerOfFour(int n) {
        int i=0;
        do{
            if(n == pow(4,i)){
                return true;
            }
            i++;
        } while(i<=15);
        return false;
    }
};