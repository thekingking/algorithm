#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <list>

using namespace std;

class LRUCache {
private:
    unordered_map<int, int> map_;
    unordered_map<int, list<int>::iterator> map_iter_;
    list<int> lru_cache_;
    int cap_;
public:
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        auto iter = map_iter_.find(key);
        if (iter != map_iter_.end()) {
            lru_cache_.erase(iter->second);
            lru_cache_.push_front(iter->first);
            iter->second = lru_cache_.begin();
            return map_[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            map_[key] = value;
        } else {
            if (lru_cache_.size() >= cap_) {
                map_.erase(lru_cache_.back());
                map_iter_.erase(lru_cache_.back());
                lru_cache_.pop_back();
            }
            map_[key] = value;
            lru_cache_.push_front(key);
            map_iter_[key] = lru_cache_.begin();
        }
    }
};