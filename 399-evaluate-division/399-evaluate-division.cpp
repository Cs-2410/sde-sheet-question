class Solution {
public:
        void dfs(string sr, string ds, map<string,vector<pair<string,double>>>& mp, map<string,int>& vis, double& ans, double temp){
                if(vis.find(sr)!=vis.end())
                        return ;
                else{
                vis.insert({sr,1});
                if(sr == ds){
                        ans = temp;
                        return ;
                }
                else{
                    for(auto ele:mp[sr]){
                            dfs(ele.first,ds,mp,vis,ans,temp*ele.second);
                    }    
                }
                }
        }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string , vector<pair<string ,double>>> mp;
            for(int i = 0; i < equations.size(); i++){
                mp[equations[i][0]].push_back({equations[i][1],values[i]});
                mp[equations[i][1]].push_back({equations[i][0],1/values[i]});       
            }
            vector<double> res;
            for(int i = 0; i < queries.size(); i++){
                    string s = queries[i][0];
                    string d = queries[i][1];
                    double ans = -1;
                    map<string,int> vis;
                    if(mp.find(s)!=mp.end())
                    dfs(s,d,mp,vis,ans,1.0);
                    res.push_back(ans);
            }
         return res;   
    }
};