class WordFilter {
public:


    unordered_map<string,int>m;
    vector<string>make_all_prefix(string &s){
        vector<string>prefix;
        vector<string>suffix;
        for(int i=0;i<s.length();i++)
        {
            string temp=s.substr(0,i+1);
            prefix.push_back(temp);
        }
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            string temp=s.substr(i,n-i);
            suffix.push_back(temp);
        }
        vector<string>ans;
        for(int i=0;i<prefix.size();i++){
            for(int j=0;j<suffix.size();j++){
                ans.push_back(prefix[i]+"#"+suffix[j]);
            }
        }
        return ans;
    }
    WordFilter(vector<string>& words) {
           for(int idx=0;idx<words.size();idx++){
               vector<string>ans=make_all_prefix(words[idx]);
               for(int j=0;j<ans.size();j++){
                   m[ans[j]]=idx;
               }
           }
    }
    
    int f(string prefix, string suffix) {
        string s=prefix+"#"+suffix;
      if(m.find(s)!=m.end()){
          return m[s];
      }
        return -1;
        
    }
};
/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */