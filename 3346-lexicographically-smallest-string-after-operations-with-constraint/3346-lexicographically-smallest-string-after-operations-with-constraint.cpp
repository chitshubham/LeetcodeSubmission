class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans;
        for(int i =0; i<s.length() ; ++i )
        {
            int left = s[i]-'a' , right = ('z'-s[i]) +1;
            int minToA =  min(left , right);
            if(minToA<=k)
            {
                k-=minToA;
                ans+='a';
            }
            else 
            {
                char ch = s[i] - k;
                ans+=ch;
                k=0;
            }
        }
        return ans;
    }
};