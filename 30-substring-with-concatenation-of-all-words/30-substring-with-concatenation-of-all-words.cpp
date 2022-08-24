class Solution {
public:
    bool solve(string s, int wordlen,unordered_map<string,int> m){
        for(int i=0;i<s.length();i+=wordlen){
            string temp=s.substr(i,wordlen);
            if(m[temp]>0) m[temp]--;
            
            else if(m[temp]==0) {
               return false;
            }
            else return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
     int n=s.length();
        int wordslen=words.size();
        int wordlen=words[0].size();
        unordered_map<string,int> m;
        for(auto x:words){
            m[x]++;
        }
        int i=0;
        vector<int> ans;
        while(i+(wordslen*wordlen)<=n){
            if(solve(s.substr(i,(wordslen*wordlen)),wordlen,m)) ans.push_back(i);
            i++;
        }
        return ans;
    }
};