#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a;
    cin >> b;

    string na, nb;
    for (int i = a.size() - 1; i >= 0; i--) na += a[i];
    for (int i = b.size() - 1; i >= 0; i--) nb += b[i];

    int an, bn;
    an = atoi(na.c_str());
    bn = atoi(nb.c_str());
    if (an > bn) cout << an;
    else cout << bn;
}