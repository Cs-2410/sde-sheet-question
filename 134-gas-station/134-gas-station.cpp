class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum1 = 0;
            int sum2 = 0, n= gas.size();
            for(int i = 0; i < gas.size(); i++){
               sum1 += gas[i];
               sum2 += cost[i]; 
                    
        }
            if(sum2 > sum1)
                    return -1;
            int start=0;
            while(start<n){
                    int curr_gas=0;
                    int flag=1,iter=start;
                    while(flag || iter!=start){
                            flag=0;
                            curr_gas+=gas[iter];
                            if(cost[iter]>curr_gas){
                                    start=(iter+1)%n;
                                    break;
                            }
                            curr_gas-=cost[iter];
                            iter=(iter+1)%n;
                    }
                    if(iter==start) return start;
            }
            return -1;
    }
};