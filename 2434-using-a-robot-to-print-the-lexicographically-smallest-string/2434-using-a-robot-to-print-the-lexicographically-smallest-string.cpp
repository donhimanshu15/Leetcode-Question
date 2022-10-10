class Solution {
public:
    
	// Returns the smaller element to the right of the current character
    char smaller(vector<int> &freq){
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                return ('a'+i);
            }
        }
        return ('a'+26);
    }
    
    string robotWithString(string s) {
		// Store the frequencies, which help in finding the smaller char to the right of the current char
        vector<int> freq(26, 0);
        for(char ch: s){
            freq[ch-'a']++;
        }
        
        string ans = "";
        stack<int> st;
        
        for(int i=0; i<s.size(); i++){
			// If there is no smaller character to the right of the top, then it should be added to the ans
            while(!st.empty() && s[st.top()] <= smaller(freq)){
                ans += s[st.top()];
                st.pop();
            }
            st.push(i);
            freq[s[i]-'a']--;
        }
        
        while(!st.empty()){
            ans += s[st.top()];
            st.pop();
        }
        
        return ans;
    }
};