class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int ,int>>arr;
        for(int i = 0; i<profits.size();++i) 
        {
            arr.push_back({capital[i],profits[i]});
        }
        sort(arr.begin(),arr.end());
        priority_queue<int>pq;
        for(int i =0;i<arr.size()&&k>=0;++i) 
        {
            // cout<<arr[i].first<<" "<<arr[i].second<<" "<<w<<endl;
             if(arr[i].first<=w) 
             {
                pq.push(arr[i].second);
             }
             else 
             {
                while(!pq.empty()&&w<arr[i].first && k>0)
                {
                    w+=pq.top();
                    pq.pop();
                    k--;
                }
                // cout<<w<<endl;
               if(w>=arr[i].first) pq.push(arr[i].second);
               else return w;
                
                
             }
        }
        while(k--&&!pq.empty()) {
            w+=pq.top();pq.pop();
        }
        return w;
    }
};