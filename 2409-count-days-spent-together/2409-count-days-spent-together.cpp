class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        unordered_map <int,int> umap;
        umap[1] = 31;
        umap[2] = 28;
        umap[3] = 31;
        umap[4] = 30;
        umap[5] = 31;
        umap[6] = 30;
        umap[7] = 31;
        umap[8] = 31;
        umap[9] = 30;
        umap[10] = 31;
        umap[11] = 30;
        umap[12] = 31;
    
        
        string arr;
        string dep;
        
        if(arriveAlice>arriveBob){
            arr = arriveAlice;
        }
        
        else{
            arr = arriveBob;
        }
        
        if(leaveAlice<leaveBob){
            dep = leaveAlice;
        }
        
        else{
            dep = leaveBob;
        }
        
        int am = stoi(arr.substr(0,2));
        int ad = stoi(arr.substr(3,2));
        int lm = stoi(dep.substr(0,2));
        int ld = stoi(dep.substr(3,2));   
    
        
        if(arr>dep){
            return 0;
        }
        
        if(am==lm){
            if(ad==ld){
                return 1;
            }
            return ld-ad+1;
        }    
        
        else{
            if(am==lm){
                return ld-ad+1;
            }
            else{
                int count = umap[am]-ad;
                am++;
                while(am!=lm){
                    count+=umap[am];
                    am++;
                }
                count+=(ld);
                return count+1;              
            }
        }
        
        return 0;
    }
};