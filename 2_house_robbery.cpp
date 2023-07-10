//https://www.codingninjas.com/studio/problems/house-robber_839733?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden. All houses along this street are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, an adjacent house has a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night. You are given an array/list of non-negative integers 'ARR' representing the amount of money for each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alarming them all.

#include <bits/stdc++.h> 

long long int houseRobber(vector<int>& valueInHouse)
{
    //SPACE OPTIMIZED
    int n=valueInHouse.size();    
    if(n==1){return valueInHouse[0];}
    long long int prev2=0;
    long long int prev1=valueInHouse[0];
    for(int i=1;i<n-1;i++){
        long long int temp=prev1;
        prev1=max(prev2+valueInHouse[i],prev1);
        prev2=temp;
    }
    long long int max0=prev1;

    prev2=0;
    prev1=valueInHouse[1];
    for(int i=2;i<n;i++){
        long long int temp=prev1;
        prev1=max(prev2+valueInHouse[i],prev1);
        prev2=temp;
    }
    long long int max1=prev1;
    return max(max0,max1);


    // int n=valueInHouse.size();
    // if(n==1){return valueInHouse[0];}
    // vector<int> dp(n,0);
    
    // dp[0]=valueInHouse[0];
    // int max0;
    // int incl,excl;
    // for(int i=1;i<n-1;i++){
    //     incl=dp[i-2]+valueInHouse[i];
    //     excl=dp[i-1];
    //     max0=max(incl,excl);
    //     dp[i]=max0;
    // }
    // dp.clear();
    // dp.assign(n,0);
    // valueInHouse.erase(valueInHouse.begin());
    // dp[0]=valueInHouse[0];
    // int max1;
    // for(int i=1;i<n-1;i++){
    //     incl=dp[i-2]+valueInHouse[i];
    //     excl=dp[i-1];
    //     max1=max(incl,excl);
    //     dp[i]=max1;
    // }
    // return max(max0,max1);
}
