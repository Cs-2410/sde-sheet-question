class Solution {
public:
       int mod = 1e9 +7;
        long binarylen(int i){
                return log2(i)+1;
        }
    int concatenatedBinary(int n) {
        long ans = 0; 
            
            for(int i = 1; i <= n; i++){
                    long len = binarylen(i);
                    
                    ans = ((ans << len)%mod + i)%mod;
            }
            return ans;
    }
};