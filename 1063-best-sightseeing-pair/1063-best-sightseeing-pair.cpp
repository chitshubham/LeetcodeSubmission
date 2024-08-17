class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // vector<int>inc;
        int n = values.size();
        vector<int>dec(n);
        dec[n-1] = values[n-1]-(n-1);
        for(int i = values.size()-2 ; i>=0;i--)
        {
            // inc.push_back(values[i]+i);
            dec[i] = max(dec[i+1],values[i]-i);
        }
        int  ans = 0;
        for(int i= 0;i<dec.size()-1;++i)
        {
         int res = values[i] + i +dec[i+1];
         ans = max(res,ans);
        }
        return ans;
    }
};