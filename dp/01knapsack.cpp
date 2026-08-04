class Solution {
    
    int recursion(int index , int cap, int n , vector<int>&val , vector<int>&wt , vector<vector<int>>&dp){
        if(index==n) return 0;
        
        if(dp[index][cap] != -1) return dp[index][cap];
        if(wt[index] > cap) return dp[index][cap] = recursion(index+1 , cap , n , val , wt , dp);
        int include = val[index] + recursion( index+1, cap-wt[index] , n , val , wt , dp);
        int notinclude = recursion(index+1 , cap , n , val , wt , dp);
        return dp[index][cap] = max(include , notinclude);
    }
    
    
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>>dp(val.size() , vector<int>(W+1 , -1));
        return recursion(0 , W , val.size() , val , wt , dp);
        
        
        
    }
};