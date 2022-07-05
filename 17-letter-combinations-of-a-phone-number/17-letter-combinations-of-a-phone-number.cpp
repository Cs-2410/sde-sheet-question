class Solution {
public:
    vector<string> ans;
    void func(string str,int index,string temp,vector<vector<int>>& keypad){
            if(index==str.length()){
                    ans.push_back(temp);
                    return;
            }
            int digit=(int)(str[index]-'0');
            for(int i=0;i<keypad[digit].size();i++)
                    func(str,index+1,temp+((char)('a'+keypad[digit][i])),keypad);
            return;
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<int>> keypad;
            if(digits==""){
                    return ans;
            }
        int index=0;
        vector<int> t1;
        keypad.push_back(t1);
        keypad.push_back(t1);
        for(int i=2;i<10;i++){
                int count=3;
                vector<int> t;
                if(i==7 || i==9) count=4;
                for(int j=0;j<count;j++){
                        t.push_back(index);
                        index++;
                }
                keypad.push_back(t);
        }
        func(digits,0,"",keypad);
        return ans;
    }
};