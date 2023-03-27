class Solution {
public:
    int reverse(int x) {
        
        long long ans = 0;
        long long z = x;
        while(z>=1 || z<=-1){
            long long a = z%10;
            if (ans >= pow(2, 31)/10 )
                return 0;
            ans = ans*10+a;
          
            z = z/10;
        }

       

        return (ans>INT_MAX || ans<INT_MIN)?0:ans;
    }
};