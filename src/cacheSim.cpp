# include <iostream>
# include <vector>
# include <unordered_set>
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
            if (cache.size() >= k) {
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

    printf("FIFO  : %d", fifoMisses);

    return 0;
}