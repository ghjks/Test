#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <numeric>
#include <climits>
#include <cassert>


using namespace std;
using ll = long long;
void solve() {
    ll n, k;
    cin >> n >> k;
    string s = "";
    ll j = 0;
    ll count_0 = 0;
    ll count_1 = 0;
    for (ll i = 0; i < n; i++) {
        char c;
        cin >> c;
        s += c;
        if (c == '0') {
            count_0++;
        } else {
            count_1++;
        }
    }
    string new_s = "";
    ll count_exceptions = 0;
    if (count_0 > count_1) {
        for (ll i = 0; i < n; i++) {
            if (j < k) {
                if (s[i]=='1') {
                    new_s += '0';
                    j++;
                } else {
                    new_s += s[i];
                }
            } else {
                new_s += s[i];
            }
            if (new_s[i] == '1') {
                count_exceptions++;
            }
        }
    } else {
        for (ll i = 0; i < n; i++) {
            if (j < k) {
                if (s[i]=='0') {
                    new_s += '1';
                    j++;
                } else {
                    new_s += s[i];
                }
            } else {
                new_s += s[i];
            }
            if (new_s[i] == '0') {
                count_exceptions++;
            }
        }
    }
    ll max_sum = 2 + (n-1)*(2+n)/2;
    if (count_exceptions == 0) {
        cout << max_sum << endl;
    } else if (count_exceptions == 1) {
        cout << max_sum - n + 1 << endl;
    } else {
        max_sum = max_sum - ((2*(n-1) - 2 * (count_exceptions-1))*count_exceptions/2);
        cout << max_sum << endl;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }
}
