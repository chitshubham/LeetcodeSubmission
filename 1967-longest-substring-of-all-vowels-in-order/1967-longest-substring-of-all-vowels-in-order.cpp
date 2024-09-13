class Solution {
public:
    int longestBeautifulSubstring(string word) {
        string v = "aeiou";
        int index = 0 , i = 0 , j = 0 , n = word.length() , ans = 0;
        // cout<<n-1<<endl;
        while(j<n){
            if(v[index]==word[j]){
                
                if(index==4){
                    // cout<<i<<" "<<j<<endl;
                ans = max(ans,j-i+1);
                }
                j++;
                if(index+1<5&&v[index+1]==word[j]) index++;
            }
            else {
                if(word[j]=='a')
                i = j;
                else
                { 
                    i = j+1;
                    j++;
                }
                // if(i==44)  cout<<i<<" "<<j<<endl;
                index= 0;
            }
            
        }
        return ans;
    }
};