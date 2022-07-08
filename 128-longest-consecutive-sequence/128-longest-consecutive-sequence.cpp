class Solution {
public:
        map<long long int,int> par;
        map<long long int,int> rank;
        int find_par(int index){
                if(par[index]==index)
                        return index;
                par[index]=find_par(par[index]);
                return par[index];
        }
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        for(int num:nums){
                if(par.find(num)!=par.end()) continue;
                par[num]=num;
                rank[num]=1;
                if(par.find(num+1)!=par.end()){
                        par[num+1]=num;
                        rank[num]+=rank[num+1];
                }
                if(par.find(num-1)!=par.end()){
                        int index=find_par(num-1);
                        par[num]=index;
                        rank[index]+=rank[num];
                        ans=max(ans,rank[index]);
                }
                ans=max(ans,rank[num]);
        }
        return ans;
    }
};