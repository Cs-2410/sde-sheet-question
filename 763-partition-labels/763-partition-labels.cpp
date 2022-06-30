class Solution {
public:
    vector<int> partitionLabels(string s) {
        
            int n=s.size();
            vector<int> ans;
            map<char,int> mp;
            for(auto ele:s)
                    mp[ele]++;
            int index=0,lastIndex=0,first=1;
            map<char,int> tm;
            while(index<n){
                    tm[s[index]]++;
                    int flag=0;
                    for(int i=0;i<26;i++){
                            char ch=(char)('a'+i);
                            if(tm.find(ch)!=tm.end() && tm[ch]!=mp[ch]){
                                    flag=1;
                                    break;
                            }
                    }
                    if(flag==0){
                            if(first){
                                ans.push_back(index+1);
                                first=0;
                            }
                            else
                                ans.push_back(index-lastIndex);
                            lastIndex=index;
                            for(int i=0;i<26;i++){
                                    char ch=(char)('a'+i);
                                    mp[ch]-=tm[ch];
                            }
                            tm.clear();
                    }
                    index++;
            }
            return ans;
    }
};