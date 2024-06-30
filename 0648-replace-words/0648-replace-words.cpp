
class Solution {
public:
  struct TrieNode{
     TrieNode* child[26];
     bool wordEnd;
     TrieNode(){
        wordEnd = false;
        for(int i = 0; i<26;++i) 
        {
            child[i] = NULL;
        }
     }
  };
    void insertKey(TrieNode* root , string s) 
    {
         TrieNode* currNode = root;
         for (auto c : s  ) 
         {
            if(currNode->child[c-'a']==NULL) 
            {
                TrieNode* newNode = new TrieNode();
                currNode->child[c-'a']= newNode;
            }
            currNode = currNode->child[c-'a'];
         }
          currNode->wordEnd = 1;
    }
    string Search(TrieNode* root , string& key)
    {
        TrieNode* currNode = root;
        string ans;
        for(auto c : key)
        {
            if(currNode->child[c-'a']==NULL) 
            {
                return key;
            }
            ans+=c;
            if(currNode->child[c-'a']->wordEnd) return ans;
            currNode=currNode->child[c-'a'];
        }
        return ans;
    } 
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for(auto key : dictionary)
        {
            insertKey(root,key);
        }
        stringstream ss(sentence);
        vector<string> v;
        string s ;
        while (getline(ss, s, ' ')) {
        v.push_back(s);
        }
        string ans="";
        for (auto str: v ){
            string str1 = Search(root,str);
            if(str1.size()==0) {
                if(ans.empty()) ans+=str;
                else ans=ans+" "+str;
            }
            else 
            {
              if(ans.empty()) ans+=str1;
                else ans=ans+" "+str1;   
            } 
     }
     return ans;
    }
};