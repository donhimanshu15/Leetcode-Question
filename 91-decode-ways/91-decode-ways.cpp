class Solution {
public:
     int helper(string& s, int n, vector<int>& t){
        if(n==0 || n==1) return 1;
        if(t[n] != -1) return t[n]; 
         
         
         
        //1 digit ways
         
        int oneDigitWays = 0;
        if(s[n-1] != '0'){
            oneDigitWays = helper(s, n-1, t);
        }
         
         
         
         //2 digit ways
         
        int twoDigitWays = 0;
        if(n >= 2 && s[n-2] != '0'){
            int num = (s[n-2] - '0') * 10 + (s[n-1] - '0');
            if(num > 0 && num <= 26){
                twoDigitWays = helper(s, n-2, t);
            }
        }
         
         
        return t[n] = oneDigitWays + twoDigitWays;
    }
    int numDecodings(string s) {
         if(s[0] == '0') return 0;
        int stringSize = s.size();
        vector<int> t(101, -1);
        return helper(s, stringSize, t);
    }
};