class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[n];
        arr[0]=1;
        int p2=0,p3=0,p5=0;   
        for(int i=1;i<n;i++){
            int val=min(arr[p2]*2,min(arr[p3]*3,arr[p5]*5));
            arr[i]=val;       
            if(val==arr[p2]*2)p2++;
            if(val==arr[p3]*3)p3++;
            if(val==arr[p5]*5)p5++;
        }
        return arr[n-1];
    }
};