class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int  ans = 0 ;
        vector<bool>check(256,true);
        for(char ch : allowed){
            check[ch-'a']=false;
        }
        for(string st: words){
            int i;
            for( i = 0; i < st.length();++i){
                if(check[st[i]-'a']) break;
            }
            if(i==st.length()) ans++;
        }
        return ans;
    }
};