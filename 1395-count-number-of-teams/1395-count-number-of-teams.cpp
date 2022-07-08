class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
            int ans;
            for(int j = 0; j < n; j++){
                    int leftinc = 0, rightinc = 0;
                    int leftdec = 0, rightdec = 0;
                    for(int i = 0; i < j; i++){
                        if(rating[i] < rating[j])
                                leftinc++;
                            else if(rating[i] > rating[j])
                                leftdec++;
                    }
                    for(int k = j+1; k < n; k++){
                            if(rating[j] < rating[k])
                                    rightinc++;
                            else if(rating[j] > rating[k])
                                    rightdec++;
                    }
                  ans += leftinc*rightinc + leftdec*rightdec;
            }
            return ans;
    }
};