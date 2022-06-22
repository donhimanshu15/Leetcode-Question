class Solution {
private:
	long long f(int row, int col, map<pair<int,int>,long long> &mp,vector<vector<long long>> &dp){
		//Check pre-computed previously or not
		if(dp[row][col] != -1) return dp[row][col];

		//Base Case is tackled under this
		long long ans = mp[{row,col}]; 

		for(int i = 1;i <= row/2;i++) //Partitions Row-wise
			ans = max(ans,f(i,col,mp,dp) + f(row-i,col,mp,dp));

		for(int j = 1;j <= col/2;j++) //Partitions Column-wise
			ans = max(ans,f(row, j, mp,dp) + f(row, col-j, mp,dp));

		//store ans in dp array before returning so that we can use it again.
		return dp[row][col] = ans; 
	}
public:
	long long sellingWood(int m, int n, vector<vector<int>>& prices) {
		//Declaring the HashMap
		map<pair<int,int>,long long> mp;

		//Storing Prices in HashMap where {height,width} of wood is key and {Price} is value
		for(int i = 0;i < prices.size();i++)
			mp[{prices[i][0],prices[i][1]}] = prices[i][2];

		vector<vector<long long>> dp(m+1,vector<long long>(n+1,-1));
		return f(m,n,mp,dp);
	}
};