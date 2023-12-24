#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int minOperations(string& s) {
        //op[0] count op need for "0101.." 
        //op[1] count op need for "1010.."
        int n=s.size(), op[2]={0};
        for(int i=0; i<n; i+=2)
            op[s[i]=='0']++;
            
        for (int i=1; i<n; i+=2)
            op[s[i]=='1']++;
        return min(op[0], op[1]);
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();