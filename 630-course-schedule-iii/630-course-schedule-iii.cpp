class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        int c=0;
        int cnt=0;
       priority_queue<int> pq;
      sort(courses.begin(),courses.end(),comp);  
        for(int i=0;i<courses.size();i++){
            int a=courses[i][0];
            int b=courses[i][1];
            b=b-c;
            if(a<=b) {
                
                c+=a;
            pq.push(courses[i][0]);}
            else{
                if(!pq.empty() && pq.top() > courses[i][0]){
                  c = c - pq.top() + a; 
               pq.pop(); 
                    pq.push(courses[i][0]); 
                }
              
                
            }
        }
          return pq.size();   
    }
};