class Solution {
public:
    bool check(string first , string second , string rem){
        if((first.size()>1 && first[0]=='0') || (second.size()>1 && second[0]=='0')) return false;
        string sum = to_string(stol(first)+stol(second));
        if(sum==rem) return true;
        int sumSize = sum.size();
        if(sumSize>=rem.size() || rem.substr(0,sumSize)!= sum) return false;
        return check(second,sum,rem.substr(sumSize));
    }
    bool isAdditiveNumber(string num) {
       int n = num.size();
       for(int i =1;i<=n/2;++i){
        for(int j =1;j<=(n-i)/2;++j){
            if(check(num.substr(0,i),num.substr(i,j),num.substr(i+j))) return true;
        }
       }
       return false;
    }
};