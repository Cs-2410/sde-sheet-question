class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int , int> mp;
            for(int i = 0; i < arr.size(); i++){
                    mp[arr[i]]++;
            }
            priority_queue<pair<int , int>> pq;
            for(auto ele : mp){
                    pq.push(make_pair(ele.second , ele.first));
            }
            int n1 = arr.size()-1, n = n1;
            int count = 0;
            while(n > n1/2){
                    // cout<<n<<" "<<n1<<endl;
                    int sub = pq.top().first;
                    n -= sub;
                    pq.pop();
                    count++;
            }
            return count;
    }
};