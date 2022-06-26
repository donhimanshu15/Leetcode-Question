class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    int s1 = accumulate(nums1.begin(), nums1.end(), 0),s2 = accumulate(nums2.begin(), nums2.end(), 0);
        int n = nums1.size(),maxi = 0,maxi1 = 0;
        
       
        int sum1 = 0,sum2 = 0;
        for(int i = 0; i < n; i++)
        {
            sum1 += (nums2[i]-nums1[i]);
            if(sum1 < 0)sum1 = 0;
             maxi = max(maxi,sum1);
            
            sum2 += (nums1[i]-nums2[i]);
            if(sum2 < 0)sum2 = 0;
            maxi1 = max(maxi1,sum2);
        }
        
        return max(s1 + maxi , s2 + maxi1);
        
    }
};