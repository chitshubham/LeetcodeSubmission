class Solution {
public:
    int numSplits(string s) {
        // map<char , int >leftmp;
        // map<char , int>rightmp;
        // for(char ch : s)
        // {
        //     rightmp[ch]++;
        // }
        // string left , right = s;
        // int cnt  = 0;
        // for(int i = 0; i<s.length()-1;++i)
        // {
        //     left+=s[i];
        //     leftmp[s[i]]+=1;
        //     right.erase(right.begin());
        //     rightmp[s[i]]=rightmp[s[i]]-1;
           
        //     if(rightmp[s[i]]==0)  rightmp.erase(s[i]);
        //     if(leftmp.size()==rightmp.size()){
                 
        //     cnt++;
        //     } 
        // }
        // return cnt;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for (auto x : s) mp1[x]++;
        int n = s.length();
        int ans = 0 ;
        for (int i=0; i<n-1; i++)
        {
            mp1[s[i]]--;
            if (mp1[s[i]]==0) mp1.erase(s[i]);
            mp2[s[i]]++;
            if (mp1.size()==mp2.size()) ans++;
        }
        return ans;
    }
};