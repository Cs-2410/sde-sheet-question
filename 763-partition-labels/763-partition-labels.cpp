class Solution {
public:
    vector<int> partitionLabels(string s) {
        
            int n=s.size();
            map<char,int> mp;
            for(int i=n-1;i>=0;i--){
                    if(mp.find(s[i])==mp.end())
                            mp[s[i]]=i;
            }
            int index=0,curmax=0,lastIndex=0,first=1;
            vector<int> ans;
            while(index<n){
                    curmax=max(curmax,mp[s[index]]);
                    if(curmax==index){
                            if(first){
                                    ans.push_back(index+1);
                                    first=0;
                            }
                            else
                                    ans.push_back(index-lastIndex);
                            lastIndex=index;
                    }
                    index++;
            }
            return ans;
    }
};