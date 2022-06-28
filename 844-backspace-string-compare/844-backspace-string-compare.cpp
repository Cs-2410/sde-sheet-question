// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         stack<char> ft , sd;
//             for(int i = 0; i < s.size(); i++){
//                     if(s[i] == '#')
//                             ft.pop();
//                     else ft.push(s[i]);
                   
//                     if(t[i] == '#')
//                             sd.pop();
//                     else sd.push(t[i]);
//             }      
            
//             if(ft.size() != sd.size())
//                     return false;
//             else
//                     while(!ft.empty()){
//                             if(ft.top() == sd.top()){
//                                     ft.pop();
//                                     sd.pop();
//                             }
//                             else 
//                                     return false;
//                     }
//             return true;
//     }
// };
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ft , sd;
            for(int i = 0; i < s.size(); i++){
                    if(s[i] == '#'){
                            if(!ft.empty()) ft.pop();
                    }
                    else ft.push(s[i]);
            }
            for(int i = 0; i < t.size(); i++){
                    if(t[i] == '#' ){
                            if(!sd.empty()) sd.pop();
                    }
                    else sd.push(t[i]);
            }
            if(ft.size() != sd.size())
                    return false;
            else
                    while(!ft.empty()){
                            if(ft.top() == sd.top()){
                                    ft.pop();
                                    sd.pop();
                            }
                            else 
                                    return false;
                    }
            return true;
    }
};