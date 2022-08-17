#include <vector>
#include <string>
#include <iostream>

using namespace std;

void first_part(vector<string> v) {
    long long n;
    cin >> n;
    cout << n << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
    vector<long long> m(v.size());
    m[0] = 1;

    for (long long i = 0; i < n; i++) {
        vector<long long> new_m(m);
        for (int j = 0; j < m.size(); j++) {
            for (int k = 0; k < v[j].length(); k++) {
                new_m[v[j][k] - 'a'] += m[j];
            }
            if (m[j] != 0) {
                new_m[j] -= m[j];
            }
        }
        m = new_m;
    }
    long long l = 0;
    for (int i = 0; i < m.size(); i++) {
        l += m[i];
    }
    cout << l << endl;
}

void second_part(vector<string> v) {

}

void third_part(vector<string> v) {

}

void fourth_part(vector<string> v) {

}

int main() {
    int k;
    cin >> k;
    vector<string> morph(k);
    for (int i = 0; i < k; i++) {
        cin >> morph[i];
    }
    int t;
    cin >> t;
    while (t--) {
        int ch;
        cin >> ch;
        if (ch == 0) {
            first_part(morph);
        }
        else if (ch == 1) {
            second_part(morph);
        }
        else if (ch == 2) {
            third_part(morph);
        }
        else if (ch == 3) {
            fourth_part(morph);
        }
    }
    return 0;
}