class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
            int count = 0;
            vector<int> vis(n+1 , 0);
            for(int i = 0; i < n; i++){
                    if(!vis[i]){
                            queue<int> q;
                            q.push(i);
                            vis[i]=1;
                            while(!q.empty()){
                                   int t = q.front();
                                    // cout<<t<<" "<<endl;
                                    q.pop();
                                    
                                    for(int j = 0; j < n; j++){
                                           if(isConnected[t][j] == 1 && vis[j]==0) {
                                                   q.push(j);
                                            vis[j]=1;
                                           }
                                    }
                            }
                            count++;
                            // cout<<count<<"**"<<endl;
                    }     
            }
            return count;
    }
};