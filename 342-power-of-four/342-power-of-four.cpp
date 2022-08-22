class Solution {
public:
        bool solve(int n){
                if(n==1) return true;
                if(n%4==0){
                        if(solve(n/4)) return true;
                }
                return false;
                
        }
    bool isPowerOfFour(int n) {
        if(n==0) return false;
            if(n==1) return true;
            if(solve(n)) return true;
            
            return false;        
    }
};