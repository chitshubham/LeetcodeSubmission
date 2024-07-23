class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int , string>>res;
        for(int i = 0; i<names.size();++i)
        {
            res.push_back({heights[i],names[i]});
        }
        sort(res.begin(),res.end(),greater<pair<int,string>>());
        vector<string>ans;
        for(auto it : res)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};