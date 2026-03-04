# include <iostream>
using namespace std;

void test(int k, int m, vector<int> &requests) {
    cout << k << endl;
    cout << m << endl;
    for (auto &r : requests) cout << r << endl;
    return;
}

int main() {
    int k, m;
    cin >> k >> m;
    vector<int> requests(m);
    for (auto &r : requests) cin >> r;

    test(k, m, requests);

    return 0;
}