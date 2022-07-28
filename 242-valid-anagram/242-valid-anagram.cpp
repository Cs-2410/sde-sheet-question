class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;
            for(auto ele:s)
                    mp[ele]++;
            
            
            for(auto it:t){
                    if(mp.find(it)!=mp.end()){
                            if(mp[it]==1) mp.erase(it);
                            else
                            mp[it]--;
                    }
                    
                    else {
                            return false;
                    }
            }
            
            if(mp.empty()) return true;
            else return false;
    }
};