#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> t[3];
    int n, from = 0, candidate = 1, move = 0;
    cout << "Please enter the number of rings:";
    cin >> n; 
    cout << endl;

    int close = (n % 2 == 0 ? 2 : 1), far = (n % 2 == 0 ? 1 : 2);
    int to = close;

    for (int i = n + 1; i >= 1; i--)
        t[0].push_back(i); 
    t[1].push_back(n + 1);
    t[2].push_back(n + 1);

    while (t[1].size() < n + 1) {
        cout << "Move #: " << ++move << " Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
        t[to].push_back(t[from].back());
        t[from].pop_back();

        if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back()) 
            from = (to + 1) % 3;
        else from = (to + 2) % 3;                                    
        candidate = t[from].back();

        if (candidate < t[(from + close) % 3].back()) to = (from + close) % 3;
        else to = (from + far) % 3;
    }
    return 0;
}