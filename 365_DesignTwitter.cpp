/*
	https://leetcode.com/problems/design-twitter/
	shimon0505004
*/


#include <map>
#include <queue>
#include <set>

using std::vector;
using std::priority_queue;

typedef std::pair<int,int> Pair;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        mUserFeed.clear();
        tweetTimeStamp= 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        
        cout << userId << " " << tweetId << " " << tweetTimeStamp<< endl;
        
        //Each user maintains his own maxHeap of tweets;
        if(mUserFeed.find(userId) == mUserFeed.end())
        {
            vector<std::pair<int,int>> personalFeed;
            pair<int,int> p = std::make_pair(tweetId,tweetTimeStamp);
            
            personalFeed.push_back(p);
            mUserFeed[userId] = personalFeed;
            mFolloweeListForFollower[userId].insert(userId);
        }else
        {
            mUserFeed[userId].push_back(std::make_pair(tweetId,tweetTimeStamp));
        }
        
        tweetTimeStamp++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto lambda=[](const Pair& left, const Pair& right)->bool{
            return left.second < right.second;
        };
        
        priority_queue<Pair,vector<Pair>,decltype(lambda)> tweetFeed(lambda);
        
        for(const auto& followeeID:mFolloweeListForFollower[userId])
        {
            for(const auto& pair:mUserFeed[followeeID])
            {
                cout << "getNewsFeed" << endl;
                cout << pair.first << " " << pair.second <<std::endl;
                tweetFeed.push(pair);
            }
        }

        vector<int> mostRecentTweets;        
        for(int count=0; count<10 && !tweetFeed.empty();count++)
        {
            auto pair = tweetFeed.top();
            tweetFeed.pop();
            mostRecentTweets.push_back(pair.first);
        }
        return mostRecentTweets;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            mFolloweeListForFollower[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId!= followeeId && 
        mFolloweeListForFollower.find(followerId) != mFolloweeListForFollower.end())
            mFolloweeListForFollower[followerId].erase(followeeId);        
    }
    

    
    std::map<int,vector<std::pair<int,int>>> mUserFeed;
    std::map<int,set<int>> mFolloweeListForFollower;
    int tweetTimeStamp;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */