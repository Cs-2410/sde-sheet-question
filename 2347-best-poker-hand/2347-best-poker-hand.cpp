class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<char,int> mp;
            for(auto ele:suits)
                    mp[ele]++;
            
            for(auto it:mp){
                    if(it.second >= 5)
                            return "Flush";
            }
            
            map<int,int> mp2;
            for(auto ele:ranks)
                    mp2[ele]++;
            
            for(auto it:mp2){
                    if(it.second >= 3)
                            return "Three of a Kind";
            }
            for(auto it:mp2){
                    if(it.second == 2)
                            return "Pair";
            }
            return "High Card";
         
    }
};