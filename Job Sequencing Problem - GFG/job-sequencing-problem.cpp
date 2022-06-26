// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
   vector<int> JobScheduling(Job arr[], int n) 
    { 
        int mx=0;
        vector<pair<int,int>>a;
      for(int i=0;i<n;i++){
          mx=max(mx,arr[i].dead);
          a.push_back({arr[i].profit,arr[i].dead});
          
      }
      sort(a.begin(),a.end());
      reverse(a.begin(),a.end());
      vector<int>deadline(mx+1);
      int sum=0,cnt=0;
      for(int i=0;i<n;i++){
          for(int j=a[i].second;j>=1;j--){
              if(deadline[j]==0){
                  sum+=a[i].first;
                  deadline[j]=1;
                  
                  cnt++;
                  break;
              }
          }
      }
      vector<int>ans;
      ans.push_back(cnt);
      ans.push_back(sum);
      return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends