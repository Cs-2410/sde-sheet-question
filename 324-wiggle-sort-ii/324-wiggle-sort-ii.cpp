class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
            vector<int> arr(n,-1);
            for(int i = 0; i < n; i++){
                arr[i] = nums[i];    
            }
            sort(arr.begin() , arr.end());
            int mid =  n/2;
            int m = mid;
            
            int end = n-1;
            int  i = 0, j = 0;
            if(n%2 == 0){
                    mid -= 1;
            for(int  i = 0; i < n; i++){
                    if((i%2 == 0)&&(mid >= 0))
                    nums[i] = arr[mid--];
                    else
                    nums[i] = arr[end--];
            } 
            }
            else{
             for(int  i = 0; i < n; i++){
                    if((i%2 == 0)&&(mid >= 0))
                    nums[i] = arr[mid--];
                    else
                    nums[i] = arr[end--];
            }       
            }
            
    }
};