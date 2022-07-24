class FoodRatings {
public:
        map<string, priority_queue< pair<int,pair<string,int>> , vector<pair<int,pair<string,int>>> , greater<pair<int,pair<string,int>>> > > ratingMap;
        map<string,int> timeMap;
        map<string,string> cuisineMap;
        int time;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
            time=0;
            ratingMap.clear();
            timeMap.clear();
            cuisineMap.clear();
            int n=foods.size();
            for(int i=0;i<n;i++){
                    cuisineMap[foods[i]]=cuisines[i];
                    timeMap[foods[i]]=0;
                    ratingMap[cuisines[i]].push({-ratings[i],{foods[i],0}});
            }
            time++;
            return;
    }
    
    void changeRating(string food, int newRating) {
            timeMap[food]=time;
            ratingMap[cuisineMap[food]].push({-newRating,{food,time}});
            time++;
    }
    
    string highestRated(string cuisine) {
        
            while(!ratingMap[cuisine].empty() && ratingMap[cuisine].top().second.second<timeMap[ratingMap[cuisine].top().second.first])
                    ratingMap[cuisine].pop();
            return ratingMap[cuisine].top().second.first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */