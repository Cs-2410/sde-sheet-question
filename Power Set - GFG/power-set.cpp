// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    private:
    void solve(string s, int in , string out , vector<string>& ans){
                if(in >= s.length()){
                    if(out.length() > 0)
                         ans.push_back(out);
                    
                     return;
                }
                
        out.push_back(s[in]);
        solve(s , in + 1, out , ans);
        
        out.pop_back();
        
        solve(s , in + 1 , out , ans);
        }
	public:
		vector<string> AllPossibleStrings(string s){
		     vector<string> ans;
            string out = "";
            int in = 0;
           solve(s, in , out , ans);
           sort(ans.begin() , ans.end());
            return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends