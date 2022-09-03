class Solution {
public:
        set<int> ans;
        void solve(int i, int pow, int k, int num){
              
                if(pow==0){
                 ans.insert(num); 
                      return ;   
                }
              
                 
                int a = pow;
                int t = i;
                while(a!=1){
                   t = t*10;
                        a--;
                }
                num += t;
                if(i+k <= 9)solve(i+k,pow-1,k,num);
                if(k!=0 && i-k >= 0)solve(i-k,pow-1,k,num);
                return ;
        }
    vector<int> numsSameConsecDiff(int n, int k) {
        
            for(int i = 1; i < 10; i++){
                
                     solve(i,n,k,0);
        }
           
            vector<int> numbers{ans.begin(), ans.end()};
            return numbers;
    }
};