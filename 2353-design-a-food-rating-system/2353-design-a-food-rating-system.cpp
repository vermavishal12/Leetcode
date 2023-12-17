class FoodRatings {
public:
    
    typedef pair<int,string> pair;
    
    unordered_map<string, int> rating;
    unordered_map<string,string>m;
    unordered_map<string, set<pair>> mapList;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n ; i++) {
            m[foods[i]] = cuisines[i];
            rating[foods[i]] = ratings[i];
            pair p = {-1*ratings[i] , foods[i]};
            mapList[cuisines[i]].insert(p);
        }
        
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = m[food];
        int oldRating = rating[food];
        pair p = {-1*oldRating, food};
        mapList[cuisine].erase(p);
        mapList[cuisine].insert({-newRating, food});
        rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        for(auto &mp : mapList[cuisine]) {
            return mp.second;
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */