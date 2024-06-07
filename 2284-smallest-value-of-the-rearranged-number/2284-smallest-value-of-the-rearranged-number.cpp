class Solution {
public:
    long long smallestNumber(long long num) {

        stringstream stream;
          stream << num;
          string s;
          s = stream.str();
          long long ans = 0;
          if(s.size()==1) return num;
          if(num<0) 
          {
            sort(s.begin() , s.end() , greater<int>());
            ans = -1*stoll(s);
          }
          else 
          {
            string str ,str1;
            sort(s.begin() , s.end());
            for(char ch : s)
            {
                if(ch=='0') str.push_back(ch);
                else {
                   str1.push_back(ch);
                   if(!str.empty()){
                    str1  = str1+str;
                    str.clear(); 
                   }
                }
            }
            ans  = stoll(str1); 
          }
          return ans;
    }
};