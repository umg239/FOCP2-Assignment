#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    unordered_map<int, long long> m;

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "CREATE") {
            int x; long long y;
            cin >> x >> y;
            if (m.count(x)) {
                m[x] += y;
                cout << 0 << endl;
            } else {
                m[x] = y;
                cout << 1 << endl;
            }
        }
        else if (cmd == "DEBIT") {
            int x; long long y;
            cin >> x >> y;
            if (!m.count(x) || m[x] < y) cout << 0 << endl;
            else {
                m[x] -= y;
                cout << 1 << endl;
            }
        }
        else if (cmd == "CREDIT") {
            int x; long long y;
            cin >> x >> y;
            if (!m.count(x)) cout << 0 << endl;
            else {
                m[x] += y;
                cout << 1 << endl;
            }
        }
        else if (cmd == "BALANCE") {
            int x;
            cin >> x;
            cout << (m.count(x) ? m[x] : -1) << endl;
        }
    }
}
