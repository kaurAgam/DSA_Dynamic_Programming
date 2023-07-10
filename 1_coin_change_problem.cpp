//https://www.codingninjas.com/studio/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// CODEHELP BY LOVE BABBAR L-104
#include <bits/stdc++.h> 

//simple recursion
#include <bits/stdc++.h> 

int solve(vector<int>& nums,int x){
    if(x==0){return 0;}
    if(x<0){return INT_MAX;}

    int min0=INT_MAX;
    for(int i=0;i<nums.size();i++){
        int ans=solve(nums,x-nums[i]);
        if(ans!=INT_MAX){ min0=min(min0,1+ans);}
    }
    return min0;
}

//using memoization
int solvemem(vector<int>& nums,int x,vector<int>& dp){

    if(x==0){return 0;}
    if(x<0){return INT_MAX;}
    if(dp[x]!=-1){return dp[x];}

    int min0=INT_MAX;
    for(int i=0;i<nums.size();i++){
        int ans=solvemem(nums,x-nums[i],dp);
        if (ans!=INT_MAX && min0>(ans+1)) {min0 = ans + 1;}
    }
    
    dp[x]=min0;
    return min0;
}

//using tabulation
int solvetab(vector<int>& nums,int x){
    if(x==0){return 0;}
    if(x<0){return INT_MAX;}
    //BOTTOM UP APPROACH 
    //dp[i] represents min. no. of coins required to make sum = i (initialize with INT_MAX)
    int dp[x+1];
    for(int i=0;i<x+1;i++){dp[i]=INT_MAX;}
    dp[0]=0;

    for(int i=1;i<=x;i++){
        for(int j=0;j<nums.size();j++){
            if(i-nums[j]>=0 && dp[i-nums[j]]!=INT_MAX){
                dp[i]=min(dp[i],dp[i-nums[j]]+1);
            }
        }
    }
    return dp[x];
}

//DRIVER FUNCTION
int minimumElements(vector<int> &nums, int x)
{    
    //int ret=solve(nums,x);
    // vector<int> dp(x+1,-1);
    // dp[0]==0;
    // int ret=solvemem(nums,x,dp);
    int ret=solvetab(nums,x);
    if(ret==INT_MAX){return -1;}
    return ret;
}
