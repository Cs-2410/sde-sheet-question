class Solution {
public:
   #define MOD 1000000007     
    int countVowelPermutation(int n) {
        long long a = 1 , e = 1, i = 1, u = 1, o = 1;
            long long a2,e2,i2,u2,o2;
            
            for(int j = 2; j <= n; j++){
                    a2 = (e+i+u)%MOD;
                    e2 = (a+i)%MOD;
                    i2 = (e+o)%MOD;
                    o2 = i;
                    u2 = (i+o)%MOD;
                    
                    a = a2 , e = e2 ,  i = i2 , o = o2, u = u2;
            }
            return (a + e + i + o + u)%MOD;
    }
};