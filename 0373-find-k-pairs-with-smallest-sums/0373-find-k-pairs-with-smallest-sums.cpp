#define PII pair<int, int>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         priority_queue<PII,vector<PII>,greater<PII>>pq;
         for(int x : nums1) 
         {
            pq.push({x+nums2[0],0});
         }
         vector<vector<int>>ans;
         while(!pq.empty() && k--)
         {
            int sum  = pq.top().first;
            int pos = pq.top().second;
            
            ans.push_back({sum-nums2[pos],nums2[pos]});
            pq.pop();
           if(pos+1<nums2.size()){
            pq.push({sum-nums2[pos]+nums2[pos+1],pos+1});
           }
         }
         return ans;
    }
};