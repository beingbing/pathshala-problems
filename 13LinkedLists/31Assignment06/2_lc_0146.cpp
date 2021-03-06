#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    int capacity;
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            keys.erase(mp[key].second);
            keys.push_front(key);
            mp[key].second = keys.begin();
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            keys.erase(mp[key].second);
            keys.push_front(key);
            mp[key] = {value, keys.begin()};
        } else {
            if (keys.size() >= capacity) {
                mp.erase(keys.back());
                keys.pop_back();
            }
            keys.push_front(key);
            mp[key] = {value, keys.begin()};
        }
    }
};
