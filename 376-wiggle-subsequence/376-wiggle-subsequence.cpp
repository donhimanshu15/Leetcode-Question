class Solution {
public:
   int mem[1001][2][1001];
    int wiggleMaxLength(vector<int>& nums) {
       
        memset(mem,-1,sizeof(mem));
        return max( dp(1,1,nums[0] ,nums) , dp(1,0,nums[0] ,nums) ) +1;
    }
    
    int dp(int i, int high ,int prev,vector<int>& nums ){ 
        if(i==nums.size())return 0; 
        if(mem[i][high][prev] >-1)return mem[i][high][prev];
        
        if(high){ 
            if(nums[i] > prev)return mem[i][high][prev] = max(1 + dp(i+1, 0, nums[i],nums) , dp(i+1,1,prev,nums) ) ;
            else return mem[i][high][prev] = dp(i+1,1,prev, nums);
        }
        
        else{ 
             if(nums[i] < prev)return mem[i][high][prev] =  max(1+dp(i+1,1,nums[i] , nums) , dp(i+1,0,prev,nums));
            else return mem[i][high][prev] = dp(i+1,0,prev ,nums);
            
        }
        
    }
};