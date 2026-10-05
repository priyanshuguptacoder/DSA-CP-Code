class Twitter {
private:
    unordered_map<int, unordered_set<int>> following; //Users -> Set of users they follow
    unordered_map<int, vector<pair<int, int>>> tweets; //User -> {tweets, timestamps}
    int timer = 0;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});    
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> pq; //Max Heap it can store timeStamps, tweetId, userId, index
        
        if(!tweets[userId].empty()){ //User own tweets
            int idx = tweets[userId].size() - 1;

            auto [time, tweetId] = tweets[userId][idx];
            pq.push({time, tweetId, userId, idx});
        }

        for(int follow : following[userId]){
            if(!tweets[follow].empty()){
                int idx = tweets[follow].size() - 1;

                auto [time, tweetId] = tweets[follow][idx];
                pq.push({time, tweetId, follow, idx});
            }
        }

        vector<int> ans;
        while(!pq.empty() && ans.size() < 10){
            auto [time, tweetId, userId, idx] = pq.top();
            pq.pop();
            ans.push_back(tweetId);

            if(idx > 0){ //Push previous tweet of same user uska phele wala khtama ho gaya toh previos wale ko daal do priority queue me uske baad for uspe time ke hisab se dekh lenge
                idx--;

                auto [prevTime, prevTweetId] = tweets[userId][idx];
                pq.push({prevTime, prevTweetId, userId, idx});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId){
            return ;
        }

        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */