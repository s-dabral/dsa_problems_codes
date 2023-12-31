class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res=-1;
        int flag=0;
        for(int i=0;i<s.size()-1;i++){
            for(int j=i+1;j<s.size();j++)
            {
                int count=-1;
                if(s[i]==s[j]){
                    
                    flag=1;
                    for(int k=i;k<j;k++){
                        count++;
                    }
                }
                res=max(res,count);
            }
        }
        if(flag==1){
            return res;
        }
        return -1;
    }
};