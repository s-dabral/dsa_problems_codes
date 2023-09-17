class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int k = 0, n = arr.size(), i = 0;
        while(i<n){
            int curr = arr[i];
            int cnt = 0;
            while(i< n && arr[i] == curr){
                cnt++;
                i++;
            }
            if(cnt > 1){
                arr[k] = curr;
                k++;
                arr[k] = curr;
                k++;
            }
            else{
                arr[k] = curr;
                k++;
            }
        }
        return k;
    }
};