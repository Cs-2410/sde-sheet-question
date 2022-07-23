class Solution {
public:
        vector<int> xx{1,-1,0,0};
        vector<int> yy{0,0,1,-1};
    int shortestBridge(vector<vector<int>>& grid) {
        
            int n=grid.size();
            vector<vector<int>> vis(n,vector<int>(n,0));
            queue<pair<pair<int,int>,int>> q;
            queue<pair<pair<int,int>,int>> q1;
            int flag=0;
            for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                            if(grid[i][j]==1){
                                    q1.push({{i,j},0});
                                    flag=1;
                                    break;
                            }
                    }
                    if(flag) break;
            }
            while(!q1.empty()){
                    int x=q1.front().first.first;
                    int y=q1.front().first.second;
                    q1.pop();
                    if(x<0 || y<0 || x>=n || y>=n) continue;
                    if(grid[x][y]==0) continue;
                    if(vis[x][y]==1) continue;
                    
                    vis[x][y]=1;
                    q.push({{x,y},0});
                    
                    q1.push({{x-1,y},0});
                    q1.push({{x+1,y},0});     
                    q1.push({{x,y-1},0});
                    q1.push({{x,y+1},0});
                    
            }
            while(!q.empty()){
                    int x=q.front().first.first;
                    int y=q.front().first.second;
                    int dist=q.front().second;
                    q.pop();
                    if(vis[x][y]==0 && grid[x][y]==1) return dist-1;
                    if(dist!=0 && vis[x][y]==1) continue;
                    vis[x][y]=1;
                    for(int i=0;i<4;i++){
                            int xxx=x+xx[i];
                            int yyy=y+yy[i];
                            if(xxx>=n || xxx<0 || yyy>=n || yyy<0) continue;
                            if(vis[xxx][yyy]==1) continue;
                            q.push({{xxx,yyy},dist+1});
                    }
                    
            }
            return -1;
    }
};