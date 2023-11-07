class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        for(int i=0;i<n;i++){
            dist[i]=ceil(dist[i]/(double)speed[i]);
        }
        sort(dist.begin(),dist.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(dist[count]<=i){
                return count;
            }
            count++;
        }
        return n;
    }
};