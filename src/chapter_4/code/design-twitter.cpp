#include <iterator>
#include <list>
#include <memory>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
private:
  int time{0};

  struct Message {
    int time{-1};
    int id{-1};

    Message() = default;
    Message(int t, int i) : time{t}, id{i} {}
  };

  using HeapElement = list<Message>::iterator;

  class User {
  private:
    unordered_set<int> followees{};
    // Use the as the sentinel value for avoid using `end`
    list<Message> messages{Message{}};

    using HeapElement = list<Message>::iterator;

  public:
    void addNewMessages(int time, int tweetId) {
      messages.emplace_front(Message{time, tweetId});
    }
    void follow(int followeeId) {
      if (followees.count(followeeId) == 0) {
        followees.insert(followeeId);
      }
    }
    void unfollow(int followeeId) {
      if (followees.count(followeeId) != 0) {
        followees.erase(followeeId);
      }
    }

    list<Message> &getMessages() { return messages; }

    unordered_set<int> &getFollowees() { return followees; }

    User() = default;
  };

  struct Comp {
    bool operator()(HeapElement &iter1, HeapElement &iter2) {
      return iter1->time < iter2->time;
    }
  };

  unordered_map<int, User> users{};

public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    if (users.count(userId) == 0) {
      users[userId] = std::move(User{});
    }

    users[userId].addNewMessages(time++, tweetId);
  }

  vector<int> getNewsFeed(int userId) {
    if (users.count(userId) == 0) {
      users[userId] = std::move(User{});
      return {};
    }

    vector<int> newsFeed{};
    priority_queue<HeapElement, vector<HeapElement>, Comp> heap{};

    if (users[userId].getMessages().front().id > 0) {
      heap.push(users[userId].getMessages().begin());
    }

    for (int followee : users[userId].getFollowees()) {
      if (users[followee].getMessages().front().id > 0) {
        heap.push(users[followee].getMessages().begin());
      }
    }

    int num = 0;
    while (!heap.empty() && num < 10) {
      HeapElement iter = heap.top();
      heap.pop();
      newsFeed.push_back(iter->id);

      advance(iter, 1);
      if (iter->id > 0) {
        heap.push(iter);
      }
      num++;
    }

    return newsFeed;
  }

  void follow(int followerId, int followeeId) {
    if (users.count(followerId) == 0) {
      users[followerId] = std::move(User{});
    }
    users[followerId].follow(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (users.count(followerId) != 0) {
      users[followerId].unfollow(followeeId);
    }
  }
};
