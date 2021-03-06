// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // Returns the maximum value that  
    // can be put in a knapsack of capacity W 
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[n+1][W+1];
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=W;j++)
           {
               if(i==0 || j==0)
                dp[i][j] = 0;
                
                else{
                    dp[i][j] = dp[i-1][j]; //isne batting nhi ki to na hi balls khayi aur na hi runs(value) add ki
                    if(wt[i-1]<=j) //iski required no of balls current available balls se kam hain to ek baar ise bhi khila ke dekh lo
                        dp[i][j] = max(dp[i][j],val[i-1] + dp[i-1][j-wt[i-1]]);
                }
           }
       }
       
       return dp[n][W];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends