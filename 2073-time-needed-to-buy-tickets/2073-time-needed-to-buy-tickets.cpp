class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int , int>> q;
            for(int i = 0; i < tickets.size(); i++)
                    q.push(make_pair(i , tickets[i]));
            int timer=0;
            while(!q.empty()){
                    timer++;
                    auto ele=q.front();
                    q.pop();
                    if(ele.second==1){
                            if(ele.first==k)
                                    return timer;
                    }
                    else{
                            q.push(make_pair(ele.first,ele.second-1));
                    }
                    
            }
            return 0;
    }
};