#include<iostream>
#include<vector>
using namespace std;

vector<int> majorityElement(vector<int> v) {
    int n = v.size();
    vector<int> ls;

    for (int i = 0; i < n; i++) {
        // Skip if already in ls
        if ((ls.size() > 0 && ls[0] == v[i]) || (ls.size() > 1 && ls[1] == v[i]))
            continue;

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] == v[i]) count++;
        }
        if (count > n / 3) {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2) break;  // Only max 2 elements possible
    }
    return ls;
}
