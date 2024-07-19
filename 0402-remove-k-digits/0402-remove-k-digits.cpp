class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for(char ch : num)
        {
            while(!s.empty() && s.back()>ch && k)
            {
                s.pop_back();
                k--;
            }
            if(!s.empty() || ch!='0')
            {
                s.push_back(ch);
            }
        }
        while(!s.empty() && k--)
        {
            s.pop_back();
        }
        return s.empty() ? "0" : s;
    }
};