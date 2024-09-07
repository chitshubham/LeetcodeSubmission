class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
         int l  = 0 , r = 0 , n = s.length() , maxlen =0;
         while(r<n)
         {
            if(mp[s[r]]!=-1)
            {
                l = max(mp[s[r]]+1,l);
            }
            mp[s[r]] = r;
            maxlen=max(maxlen,r-l+1);
            r++;
         }
         return maxlen;
    }
};