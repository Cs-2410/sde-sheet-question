class Solution {
public:
        map<pair<int,int>,int> dp;
        int solve(int x,int y){
                if(x>=y) return 1;
                auto ele=make_pair(x,y);
                if(dp.find(ele)!=dp.end()) return dp[ele];
                int sum=0;
                for(int i=x;i<=y;i++)
                        sum+=solve(x,i-1)*solve(i+1,y);
                dp[ele]=sum;
                return sum;
        }
    int numTrees(int n) {
            dp.clear();
        return solve(1,n);
    }
};