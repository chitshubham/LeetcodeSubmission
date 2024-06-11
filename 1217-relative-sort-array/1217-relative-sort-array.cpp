class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int , int>mp;
        for(auto i : arr2)
        {
            mp[i]+=1;
        }
        for(auto i:arr1) 
        {
            if(mp.find(i)!=mp.end())
            mp[i]+=1;
        }
        vector<int>ans;
        for(auto i : arr2 )
        {
          while(mp[i]>=0)
          {
            if(mp[i]>1)
             ans.push_back(i);
            mp[i]--;
          }

        }
        vector<int>arr;
        for(auto i : arr1)
        {
            if(mp[i]!=-1) arr.push_back(i);
        }
        sort(arr.begin(),arr.end());
        ans.insert(ans.end(),arr.begin(),arr.end());
        return ans;

    }
};