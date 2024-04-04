// Category: Mathematics, Implementation
// Idea: Use "/" and "%" arithmetics to move quadrant at once

#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int D;
ll X, Y;
string S;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // input
    cin >> D >> S >> X >> Y;
    for (int i = S.length()-1; i >= 0; i--) {
        v.push_back(S[i] - '0');
    }

    // moving X side
    int idx = 0;
    while (X) {
        if (idx == D) {
            cout << -1;
            return 0;
        }

        ll now = X % 2;
        ll next = X / 2;
        
        if (now) {
            switch (v[idx]) {
                case 1:
                    v[idx] = 2;
                    if (X > 0) next++;
                    break;
                case 2:
                    v[idx] = 1;
                    if (X < 0) next--;
                    break;
                case 3:
                    v[idx] = 4;
                    if (X < 0) next--;
                    break;
                case 4:
                    v[idx] = 3;
                    if (X > 0) next++;
                    break;
            }
        }

        idx++;
        X = next;
    }

    // moving Y side
    idx = 0;
    while (Y) {
        if (idx == D) {
            cout << -1;
            return 0;
        }

        ll now = Y % 2;
        ll next = Y / 2;

        if (now) {
            switch (v[idx]) {
                case 1:
                    v[idx] = 4;
                    if (Y > 0) next++;
                    break;
                case 4:
                    v[idx] = 1;
                    if (Y < 0) next--;
                    break;
                case 3:
                    v[idx] = 2;
                    if (Y < 0) next--;
                    break;
                case 2:
                    v[idx] = 3;
                    if (Y > 0) next++;
                    break;
            }
        }

        idx++;
        Y = next;
    }

    // print answer
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }

    return 0;
}
