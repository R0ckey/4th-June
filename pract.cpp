#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        unordered_map<int, int> first, last;
        for (int i = 0; i < n; i++) {
            int val = arr[i];
            if (first.find(val) == first.end()) first[val] = i;
            last[val] = i;
        }

        int minCost = INT_MAX;

        for (auto &[val, startIdx] : first) {
            int endIdx = last[val];
            int cost = val * startIdx + val * (n - 1 - endIdx);
            minCost = min(minCost, cost);
        }

        cout << minCost << endl;
    }

    return 0;
}
