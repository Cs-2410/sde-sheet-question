// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int add(int x, int y){
        long long MOD = 1000000000+7;
     return (x%MOD + y%MOD)%MOD;
}
int mul(int x , int y){
    long long MOD = 1000000000+7;
     return ((x%MOD)*1LL * (y%MOD))%MOD;
}
    
    long long countWays(int n, int k){
       int prev2 = k;
       if(n == 1)
       return prev2;
     int prev1 = add(k , mul(k , k-1));
   for(int i = 3; i <= n; i++){
        int curr = add(mul(prev2 , k-1) , mul(prev1 , k-1));
            prev2 = prev1;
            prev1 = curr;
   }
    return prev1;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends