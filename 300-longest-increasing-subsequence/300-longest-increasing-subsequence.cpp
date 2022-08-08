class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
     vector<int> temp = {nums[0]};
	for(int i=1;i<nums.size();i++){
		// if current element is greater than last element in temp array, then add it at last
		// else find the element to second largest element and replace it with current element
		if(nums[i] > temp.back()) {
			temp.push_back(nums[i]);
		} else {
			int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
			temp[idx] = nums[i];
		}
	}
	return temp.size();
    }
};