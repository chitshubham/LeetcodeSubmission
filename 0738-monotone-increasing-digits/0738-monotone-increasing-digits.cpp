class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n<10) return n;
       string s = to_string(n);
       int index = s.length();
       for(int i = index-1;i>0;i--)
       {
         if(s[i-1]>s[i]) 
         {
            s[i-1]--;
            index = i;
         }
       }
       for(int i = index ; i<s.length();++i) 
       {
        s[i] = '9';
       }
      int N =  stoi(s);
   
      return N;
    }
};