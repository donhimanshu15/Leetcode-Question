class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int inc) {
         if(inc == 0)
        return 0.0;
    double ans = 0;
    
   
    if(inc<b[0][0])
         {  
            ans += (b[0][1]== 0)?0:((double)inc*(b[0][1]))/100.0;
            return ans;
         }
    else 
        ans += (b[0][1]== 0)?0:((double)b[0][0]*(b[0][1]))/100.0;
   
    for(int i = 1;i<b.size();i++){
        
        if(b[i][0]<inc){
            ans += (b[i][1]==0)?0:((double)(b[i][0]-b[i-1][0]))*b[i][1]/100.0; 
        }
        else
        { 
            ans += (b[i][1]==0)?0:((double)(inc-b[i-1][0])*(b[i][1]))/100.0;
            break;
           }
    }
    return ans;
    }
};