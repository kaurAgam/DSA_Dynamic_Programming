//https://www.codingninjas.com/studio/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h> 
int cutSegments(int n, int x, int y, int z) {

	int nums[3]={x,y,z};
	vector<int> dp(n+1,-1);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			if(i-nums[j]>=0 && dp[i-nums[j]]!=-1){
                dp[i]=max(dp[i],dp[i-nums[j]]+1);
            }
		}

	}
	if(dp[n]<0){return 0;}

	return dp[n];
}
