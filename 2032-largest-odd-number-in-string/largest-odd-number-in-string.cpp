#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const auto fast = []() { std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; } ();

class Solution {
public:
    string largestOddNumber(string num) {
        fast; 
        int len = num.size(); 
        bool append = false; 
        string res = ""; 
        for (int i = len - 1; i >=0; i--){
            if((num[i] - '0')&1) // convert from string digit to integer, then check it is odd, as the LSB must be 1
                append = true; 
            if (append)
                res+=num[i]; 
        }
        reverse(res.begin(), res.end());
        return  res;
    }
};