class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        priority_queue<pair<int,int>>pq;
        int n = values.size();
        unordered_map<int , int>mp;
        for(int i =0 ;i< n;++i)
        {
            pq.push({values[i],labels[i]});
            mp[labels[i]]=useLimit;
        }
        int  sum =0 , chance=useLimit;
        while(!pq.empty()&&numWanted--)
        {
            while(!pq.empty()&&mp[pq.top().second]==0) pq.pop();
                if(mp[pq.top().second]>0)
                {
                    sum+=pq.top().first;
                     mp[pq.top().second]--;
                     pq.pop();
                }
               
               
            
        }
        return sum;
    }
};