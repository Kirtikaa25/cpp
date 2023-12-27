int solve(int ind,int trans,int n,vector<int>& prices,vector<vector<int>> &dp){
    if(trans==0) return 0;
    if(ind==n) return 0;
    int profit=0;    
    if(dp[ind][trans]!=-1) return dp[ind][trans];

    if(trans%2==0){
      profit=max(-prices[ind]+solve(ind+1,trans-1,n,prices,dp),solve(ind+1,trans,n,prices,dp));
    }else{
        profit=max(prices[ind]+solve(ind+1,trans-1,n,prices,dp),solve(ind+1,trans,n,prices,dp));
    }
    return dp[ind][trans]=profit;
}
int maxProfit(vector<int>& prices)
{
    // Write your code here.
     int n=prices.size();
     vector<vector<int>> dp(n,vector<int>(5,-1));
     return solve(0,4,n,prices,dp);
}
