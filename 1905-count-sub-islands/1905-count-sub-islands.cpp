class Solution {
public:
    vector<int> aa{0,1};
    vector<int> bb{1,0};
    int find(vector<vector<int>>& par,int x,int y,int n){
            if(par[x][y]==(x*n+y))
                    return par[x][y];
            par[x][y]=find(par,par[x][y]/n,par[x][y]%n,n);
            return par[x][y];
    }
    void union1(vector<vector<int>>& par,int a,int b,int c,int d,int n){
            int p1=find(par,a,b,n);
            int p2=find(par,c,d,n);
            if(p1==p2) return;
            par[p1/n][p1%n]=p2;
            return;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        vector<vector<int>> parg2;
        for(int i=0;i<n;i++){
                vector<int> temp;
                for(int j=0;j<m;j++)
                        temp.push_back(i*m+j);
                parg2.push_back(temp);
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        if(grid2[i][j]==0)
                                parg2[i][j]=-1;
                        else{
                               for(int k=0;k<2;k++){
                                       int xx=i+aa[k];
                                       int yy=j+bb[k];
                                       if(xx<0 || xx>=n || yy<0 || yy>=m)
                                               continue;
                                       if(grid2[xx][yy]==1)
                                               union1(parg2,i,j,xx,yy,m);
                               } 
                        }
                }
        }
            map<int,int> mp;
            
            int count=0;
            for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                            if(parg2[i][j]==-1)
                                    continue;
                            mp[find(parg2,i,j,m)]=1;
                    }
            }
            for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                           if(parg2[i][j]==-1)
                                    continue;
                            if(grid2[i][j]==1 && grid1[i][j]==0){
                                    mp[find(parg2,i,j,m)]=0;
                            }
                    }
            }
            for(auto ele:mp)
                    count+=ele.second;
            return count;
    }
};