class Solution {
public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int ,int>>v;
        int n = difficulty.size();
        for(int i = 0; i<n;++i) 
        {
             v.push_back({difficulty[i],profit[i]});
        }
         sort(v.begin(),v.end());
          sort(worker.begin(),worker.end());
          int maxi = 0 , i = 0 , j = 0 , ans = 0 ;
          while(i<worker.size()&&j<n)
          {
            if(v[j].first>worker[i]) 
            {
                
                  ans+=maxi;
                  i++;
            }
            else 
            {
                

                 maxi = max(maxi,v[j].second);
                 j++;
            }
          }
          while(i<worker.size()) 
          {
            ans+=maxi;
            i++;
          }
        return ans;
    }
};