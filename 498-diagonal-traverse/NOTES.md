```
```
int flag  = 0;
int row = 0, col = -1;
int m = mat.size();
int n = mat[0].size();
vector<int> ans;
while(row<m || col<n){
if(flag==0){
++col;
if(row==m){
--row;
++col;
}
while(row>=0 || col<n){
ans.push_back(mat[row--][col++]);
}
flag = 1;
}
else if(flag){
++row;
if(col==n){
--col;
++row;
}
while(col>=0 || row<m){
ans.push_back(mat[row++][col--]);
}
flag = 0;
}
}
return ans;``
```
```