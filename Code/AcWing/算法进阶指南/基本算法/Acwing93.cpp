#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> chosen;

void calc(int x) {
    if (chosen.size() > m || chosen.size() + (n - x + 1) < m) {
        return;
    }
    
    if (x > n) {
        if (chosen.size() == m) {
            for (int i = 0; i < chosen.size(); i++) {
                if (i > 0) cout << " ";
                cout << chosen[i];
            }
            cout << endl;
        }
        return;
    }
    
    // 选择当前数x
    chosen.push_back(x);
    calc(x + 1);
    chosen.pop_back();
    
    // 不选择当前数x
    calc(x + 1);
}

int main() {
    cin >> n >> m;
    calc(1);
    return 0;
}
