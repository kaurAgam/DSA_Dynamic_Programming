//  CODING NINJAS: You are given an array/list of 'N' integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.
// CODEHELP BY LOVE BABBAR L-105 DP SERIES

#include <bits/stdc++.h> 
int solverec(vector<int>& nums,int i){
    if(i<0){return 0;}
    if(i==0){return nums[0];}

    int max0=INT_MIN;
    max0=max(max0,solverec(nums,i-2)+nums[i]);
    max0=max(max0,solverec(nums,i-1));
    return max0;

}
//MEMOIZATION
int solvemem(vector<int>& nums,vector<int>& dp,int i){
    if(i<0){return 0;}
    if(i==0){return nums[0];}
    if(dp[i]!=INT_MIN){return dp[i];}
    int max0=INT_MIN;
    max0=max(max0,solverec(nums,i-2)+nums[i]);
    max0=max(max0,solverec(nums,i-1));
    dp[i]=max0;
    return max0;
}
//TABULATION
int solvetab(vector<int>& nums){
    int n=nums.size();
    if(n<=0){return 0;}    
    if(n==1){return nums[0];}

    vector<int> dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int incl, excl;

        incl=dp[i-2]+nums[i];

        excl=dp[i-1];

        dp[i]=max(incl,excl);
    }

    return dp[n-1];
  
}
//Space Optimized
int solve4(vector<int>& nums){
    int n = nums.size();
    int prev2=0;
    int prev1=nums[0];
    int sum=0;
    for (int i = 1; i < n; i++){
        int temp = prev1;
        prev1 = max(prev2 + nums[i], prev1);
        prev2 = temp;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // int ret=solverec(nums,nums.size()-1);
    // return ret;

    // vector<int> dp(nums.size()+1,INT_MIN);
    // dp[0]=nums[0];
    // int ret=solvemem(nums,dp,nums.size()-1);
    // return ret;
    
    //return solvetab(nums);
    return solve4(nums);
}
