#include<iostream>
#include<vector>
using namespace std;
int checkPossiblities(int start, int end,vector<int> &dp)
{
    if(dp[start]!=-1)
    {
        return dp[start];
    }
    if(start>end)
    {
        return 0;
    }
    if(start == end)
    {
        return 1;
    }
    dp[start] = checkPossiblities(start+1,end,dp)+checkPossiblities(start+2,end,dp);
    return dp[start];

}
int main()
{
    int n;
    cin>> n;
    vector<int> dp(n+1);
    for(int i=0;i<=n;i++)
    {
        dp[i] = -1;
    }
    cout << checkPossiblities(0,n,dp);
    return 0;
}