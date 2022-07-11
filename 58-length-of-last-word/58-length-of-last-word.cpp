class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int len=0;
        int flag=0;
        int temp=0;
        for(int i=0;i<n;i++){
            if(s[i]==' ' && len!=0) {temp=len; flag=0; len=0;}
            else if((s[i]>='a' && s[i]<='z') or (s[i]>='A' && s[i]<='Z')){
                flag=1;
                len++;
            }
        }
        if(len==0) return temp;
        else return len;
    }
};