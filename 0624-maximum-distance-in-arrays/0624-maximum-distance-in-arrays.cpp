class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int,int>>maxi , mini;
        int i = 0;
        for(auto it : arrays)
        {
            int maxi1 = *max_element(it.begin(),it.end());
            int mini1 = *min_element(it.begin(),it.end()); 
            maxi.push_back({maxi1,i});
            mini.push_back({mini1,i});
            i++;
        }
        sort(maxi.begin(),maxi.end() , greater<pair<int,int>>());
        sort(mini.begin(),mini.end());
        // cout<<maxi[0].first<<" "<<maxi[0].second<<endl;
        // cout<<mini[0].first<<" "<<mini[0].second<<endl;
        if(maxi[0].second==mini[0].second)
        {
            int ele = abs(maxi[0].first-mini[1].first);
            int ele1 = abs(maxi[1].first-mini[0].first);
             return max( ele ,ele1); 
        }
        else
         return abs(maxi[0].first-mini[0].first);
    }
};