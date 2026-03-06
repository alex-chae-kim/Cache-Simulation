# include <iostream>
# include <vector>
# include <unordered_set>
# include <set>
# include <list>
using namespace std;

void test(int k, int m, vector<int> &requests) {
    cout << k << endl;
    cout << m << endl;
    for (auto &r : requests) cout << r << endl;
    return;
}

int FIFO(int k, int m, vector<int> &requests) {
    int misses = 0;
    unordered_set<int> cache;
    queue<int> q;
    for (auto r : requests) {
        if (cache.find(r) == cache.end()) {
            if (cache.size() == k) {
                int evict = q.front();
                q.pop();
                cache.erase(evict);
            }
            cache.insert(r);
            q.push(r);
            misses++;
        }
    }
    return misses;
}

int LRU(int k, int m, vector<int> &requests) {
    int misses = 0;
    list<int> lru;
    unordered_map<int, list<int>::iterator> pos;
    for (int r : requests) {
        auto it = pos.find(r);

        if (it != pos.end()) {
            lru.erase(it->second);
            lru.push_front(r);
            pos[r] = lru.begin();
        } else {
            if (lru.size() == k) {
                int evict = lru.back();
                lru.pop_back();
                pos.erase(evict);
            }
            lru.push_front(r);
            pos[r] = lru.begin();
            misses++;
        }
    }
    return misses;
}

int OPTFF(int k, int m, vector<int> &requests) {
    const int INF = 1e9;
    vector<int> nextPos(m, INF);
    unordered_map<int, int> lastSeen;
    for (int i = m - 1; i >= 0; i--) {
        int id = requests[i];
        auto it = lastSeen.find(id);
        nextPos[i] = (it == lastSeen.end()) ? INF : it->second;
        lastSeen[id] = i;
    }
    unordered_map<int, int> cacheNext;
    set<pair<int,int>> order;
    int misses = 0;
    for (int i = 0; i < m; i++) {
        int id = requests[i];
        int next = nextPos[i];
        auto it = cacheNext.find(id);
        if (it != cacheNext.end()) {
            order.erase({it->second, id});
            it->second = next;
            order.insert({next, id});
        } else {
            if (cacheNext.size() == k) {
                auto evIt = prev(order.end());
                int evictId = evIt->second;
                order.erase(evIt);
                cacheNext.erase(evictId);
            }
            cacheNext[id] = next;
            order.insert({next, id});
            misses++;
        }
    }
    return misses;
}

int main() {
    int k, m;
    cin >> k >> m;

    bool earlyExit = false;
    if (k < 1) {
        cout << "Please input k >= 1" << endl;
        earlyExit = true;
    }
    if (m < 1) {
        cout << "Please input m >= 1" << endl;
        earlyExit = true;
    }
    if (earlyExit) return 0;
    
    vector<int> requests(m);
    for (auto &r : requests) cin >> r;

    int fifoMisses = FIFO(k, m, requests);
    int lruMisses = LRU(k, m, requests);
    int optffMisses = OPTFF(k, m, requests);


    printf("FIFO  : %d\n", fifoMisses);
    printf("LRU   : %d\n", lruMisses);
    printf("OPTFF : %d", optffMisses);

    return 0;
}