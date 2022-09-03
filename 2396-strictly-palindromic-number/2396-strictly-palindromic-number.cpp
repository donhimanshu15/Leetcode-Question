class Solution {
public:
    
    bool is_possible(int num, int b)
    {
        // find the number in base b
        
        string str = "";
        
        while(num)
        {
            int r = num % b;
            
            str = to_string(r) + str;
            
            num /= b;
        }
        
        // check is it palindrome or not
        
        int i = 0;
        
        int j = str.size() - 1;
        
        while(i <= j)
        {
            if(str[i] != str[j])
                return false;
            
            i++;
            
            j--;
        }
        
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
        
        for(int b = 2; b <= n - 2; b++)
        {
            if(is_possible(n, b) == false)
                return false;
        }
        
        return true;
    }
};