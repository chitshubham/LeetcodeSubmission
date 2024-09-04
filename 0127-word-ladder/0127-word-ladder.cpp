class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty())
        {
            string Word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(Word==endWord) return step;
            for(int i = 0; i <Word.length();++i)
            {
                char org = Word[i];
                for(char ch = 'a';ch<='z';++ch)
                {
                    Word[i] = ch;
                    if(st.find(Word)!=st.end())
                    {
                        q.push({Word,step+1});
                        st.erase(Word);
                    }
                }
                Word[i] = org;
            }
        }
        return 0;
    }
};