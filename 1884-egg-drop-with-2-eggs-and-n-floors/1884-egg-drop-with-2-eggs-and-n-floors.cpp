class Solution {
public:
    int fun(int eggCnt, int floor, vector<vector<int>> &dp)
{
    if (eggCnt == 1 or floor == 1 or floor == 0) 
        return floor;
    if (dp[eggCnt][floor] != -1)
        return dp[eggCnt][floor];

    int minEle = INT_MAX; 
    for (int i = 1; i <= floor; i++)
    {
        minEle = min(minEle, 1 + max(fun(eggCnt - 1, i - 1, dp), fun(eggCnt, floor - i, dp)));
    }
    return dp[eggCnt][floor] = minEle;
}
    int twoEggDrop(int n) {
          vector<vector<int>> dp(3, vector<int>(n + 1, -1));
    return fun(2, n, dp);
    }
};