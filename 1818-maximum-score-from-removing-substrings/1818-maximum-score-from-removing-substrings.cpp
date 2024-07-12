class Solution {
public:
    string charremoved(string s , string str) 
    {
       stack<char>st;
       for(char&ch : s ) 
       {
         if(ch==str[1]&& !st.empty() && st.top()==str[0]) 
         {
            st.pop();
         }
         else {
            st.push(ch);
         }
       }
       string temp;
       while(!st.empty())
       {
         temp.push_back(st.top());
         st.pop();
       }
       reverse(temp.begin(),temp.end());
       return temp;
    }
    int maximumGain(string s, int x, int y) {
        int n  = s.length();
        int score = 0;
        string maxStr = x>y ? "ab" :"ba";
        string minStr = x<y?"ab":"ba";
        string temp_first = charremoved(s,maxStr);
        int L =   temp_first.length();
        int char_removed = n - L ;
        score+= (char_removed/2)*max(x,y);
        string temp_second = charremoved(temp_first,minStr);
        int r  = temp_second.length();
        char_removed = L - r ; 
        score+= (char_removed/2)*min(x,y);
        return score;
    }
};