class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int ,int> mp;
        for(int i = 0; i < bills.size(); i++){
           if(bills[i]==10){
               if(mp[5]==0)
               return false;
               else{
                   mp[10]++;
                   mp[5]--;
               }
           }
           else if(bills[i]==20){
               if(mp[5]==0){
               return false;
               }
               else if(mp[10]==0){
                   if(mp[5]<3)
                   return false;
                   else{
                       mp[5] -= 3;
                   }
               }
               
               else{
                   mp[10]--;
                   mp[5]--;
               }
           }
           else{
               mp[5]++;
           }
        }
        return true;
    }
};