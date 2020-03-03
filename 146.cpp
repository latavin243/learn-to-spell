class LRUCache {
private:
    int cap;
    int count;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
    }

    int get(int key) {
        int res = -1;
        auto p = m.find(key);
        if (p != m.end()) {
            res = p->second->second;
            l.erase(p->second);
            l.push_front(make_pair(key, res));
            p->second = l.begin();
        }
        return res;
    }

    void put(int key, int value) {
        auto p = m.find(key);
        if (p != m.end()) l.erase(p->second);
        else if (count == cap) {
            int del = l.back().first;
            l.pop_back();
            m.erase(del);
        }
        else count++;

        l.push_front(make_pair(key, value));
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */