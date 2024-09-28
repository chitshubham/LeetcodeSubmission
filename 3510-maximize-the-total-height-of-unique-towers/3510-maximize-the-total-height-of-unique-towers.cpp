class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
        int n = maximumHeight.size();
        for(int i = 1 ; i<n;++i){
           maximumHeight[i] = min(maximumHeight[i],maximumHeight[i-1]-1);
        //    cout<<maximumHeight[i-1]<<" "<<maximumHeight[i]<<endl;
           if(maximumHeight[i]==0 || maximumHeight[i]==maximumHeight[i-1]) return -1;
        }
        return accumulate(maximumHeight.begin(),maximumHeight.end(),0LL);
    }
};