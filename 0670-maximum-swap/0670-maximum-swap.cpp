class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int arr[10]={-1};
        for(int i = 0; i < str.length();++i){
            char ch = str[i];
            arr[ch-'0'] = i;
        }
        string s = str;
        sort(s.begin(),s.end(),greater<char>());
        for(int i = 0; i<s.length();++i){
            if(s[i]!=str[i]) {
                int index = arr[s[i]-'0'];
               swap(str[i],str[index]);
               break;
            }
        }
        return stoi(str);
    }
};