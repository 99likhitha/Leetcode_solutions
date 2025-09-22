class FoodRatings {
public:

    struct Byrating
    {
        bool operator()(const pair<int,string> &a,const pair<int,string>&b ) const
        {
            if(a.first !=b.first) return a.first<b.first;
            return a.second>b.second;
        }
    };

    unordered_map<string,pair<string,int>>food_to_rating;

    unordered_map<
    string, 
    priority_queue<pair<int,string>, vector<pair<int,string>>,
    Byrating>>cusine_to_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++)
        {
            food_to_rating[foods[i]]=make_pair(cuisines[i],ratings[i]);
            cusine_to_rating[cuisines[i]].push({ratings[i],foods[i]});  
        }
    }
    
    void changeRating(string food, int newRating) {
        auto it=food_to_rating.find(food);
        if(it ==food_to_rating.end()) return;
        const string &cusi=it->second.first;
        it->second.second=newRating;
        cusine_to_rating[cusi].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
         
         auto &topfood=cusine_to_rating[cuisine];
         while(!topfood.empty())
         {
            auto &[rate,food]=topfood.top();
            if(food_to_rating[food].second ==rate) return food;
            topfood.pop();
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