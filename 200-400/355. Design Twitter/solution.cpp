class Twitter {
private:
    struct TweetNode {
        int seqLabel;
        int id;
        TweetNode* prev;
        
        TweetNode(int s=-1, int i=-1, TweetNode* node=nullptr): 
            seqLabel(s), id(i), prev(node) {}
        
        void clear() {
            if (prev) prev->clear();
            delete prev;
            prev = nullptr;
        }
        
        bool operator< (TweetNode* another) {
            return seqLabel < another->seqLabel;
        }
    };
    
    int tweetSeq = 0;
    unordered_map<int,TweetNode*> u2t; //user to tweets 
    unordered_map<int,set<int>> following;
    
public:
    Twitter() {
    }
    
    ~Twitter() {
        for (auto[user,tweets] : u2t) {
            tweets->clear();
        }    
    }
    
    void postTweet(int userId, int tweetId) {
        TweetNode* curNode = new TweetNode(tweetSeq,tweetId);
        tweetSeq++;
        if (u2t.find(userId) != u2t.end()) {
            curNode->prev = u2t[userId];
        }
        u2t[userId] = curNode;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto& followees = following[userId];
        priority_queue<TweetNode*> pq;
        if(u2t.find(userId) != u2t.end()) pq.emplace(u2t[userId]);
        for (auto each : followees) {
            if(u2t.find(each) != u2t.end()) pq.emplace(u2t[each]);
        }
        
        vector<int> feed;
        for (int i=0; i<10 && !pq.empty(); i++) {
            auto node = pq.top(); pq.pop();
            feed.push_back(node->id);
            if (node->prev) pq.push(node->prev);
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
