// class Solution {
// public:  vector<vector<string>> ans;
//          vector<string> level;
//         bool check(string str){
//                 int l = 0;
//                 int h = str.size()-1;
//                 while(h>l){
//                         if(str[l++] != str[h--])
//                                 return false;
//                 }
//                                return true;
//         }
//         void solve(string s , int index){
//                 if(index >= s.size())
               
               
//                 }
// }
    
//         vector<vector<string>> partition(string s) {
//         if(s.size() == 0)
//                 return ans;
//                 solve(s ,0);
//                 return ans;
//     }
// };
class Solution {
public: 
    
        vector<vector<string>> ans;
        bool isPalindrome(string s,int i,int j){
                while(i<=j){
                        if(s[i]!=s[j]) return false;
                        i++;j--;
                }
                return true;
        }
        void func(string s,int start,int current,vector<int> cuts){
                if(current==s.size()){
                        if(start==current){
                                int index=0,iter=0;
                                vector<string> temp;
                                string str="";
                                while(index<s.size()){
                                        str+=s[index];
                                        if(index==cuts[iter]){
                                                temp.push_back(str);
                                                str="";
                                                iter++;
                                        }
                                        index++;
                                }
                                ans.push_back(temp);
                        }
                        return;
                }
                if(isPalindrome(s,start,current))
                {
                        cuts.push_back(current);
                        func(s,current+1,current+1,cuts);
                        cuts.pop_back();
                }
                func(s,start,current+1,cuts);
                return;
        }
        vector<vector<string>> partition(string s) {
                vector<int> cuts;
                func(s,0,0,cuts);
                return ans;
                
    }
};