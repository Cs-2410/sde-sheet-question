class Solution {
public:
        bool issubseq(string a, string b){
                int n = 0, m = 0;
                int x = a.size(),y = b.size();
                while(n<x && m<y){
                        if(a[n]==b[m])
                                n++,m++;
                        else
                                n++;
                }
                return (m == y);
        }
    int numMatchingSubseq(string s, vector<string>& words) {
        map<string , int> mp;
            int i = 0;
            while(i<words.size())
                    mp[words[i++]]++;
            int count = 0;
            for(auto it:mp){
                    if(issubseq(s,it.first))
                            count += it.second;
            }
            return count;
    }
};