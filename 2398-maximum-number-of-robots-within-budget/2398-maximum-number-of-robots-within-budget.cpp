class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rt, long long budget) {
        long long n = ct.size();
        long long max_robots = 0, i = 0, curr_cost = 0;
        
        priority_queue<pair<long long,long long>>pq;
        for(long long j=0;j<n;j++){
            curr_cost+=rt[j];
            pq.push({ct[j],j});
            
            if(pq.size() and curr_cost*(j-i+1)+pq.top().first<=budget){
                max_robots = max(max_robots,j-i+1);
            }else{
              
                while(pq.size() and curr_cost*(j-i+1)+pq.top().first>budget){
                    curr_cost-=rt[i];
                  
                    while(pq.size() and pq.top().second<=i){
                        pq.pop();
                    }
                    i++;
                }
                
                if(pq.size() and curr_cost*(j-i+1)+pq.top().first<=budget){
                    max_robots = max(max_robots,j-i+1);
                }
            }
        }
        return max_robots;
    }
};