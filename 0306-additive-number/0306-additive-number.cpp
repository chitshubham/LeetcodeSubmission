class Solution {
public:
    bool check(const  string& str1 ,const string& str2 ,const string& rem){
      if ((str1.size() > 1 && str1[0] == '0') || (str2.size() > 1 && str2[0] == '0')){
         return false;
      }
        string sum = to_string(stol(str1) + stol(str2));
        int sumSize= sum.size();
        if(sum==rem) return true;
        else if(sum.size()>=rem.size() || rem.substr(0,sumSize)!=sum) return false;
        return check(str2,sum,rem.substr(sumSize));
        }
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for(int i =1;i<=n/2;++i){
            for(int j =1;j<=(n -i)/2;++j){
                if(check(num.substr(0,i),num.substr(i,j),num.substr(i+j))) return true;
            }
        }
        return false;
    }
};