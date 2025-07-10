#include <bits/stdc++.h>
using namespace std;
int countPairs(int code, const vector<int>& fragments) {
    string codeStr = to_string(code);
    int count = 0;
    // Convert all fragments to string and store frequencies
    unordered_map<string, int> freq;
    for (int num : fragments) {
        freq[to_string(num)]++;
    }
    // Now loop through each fragment
    for (int num : fragments) {
        string prefix = to_string(num);
        // Check if codeStr starts with prefix
        if (codeStr.substr(0, prefix.length()) == prefix) {
            string suffix = codeStr.substr(prefix.length());
            // Check how many fragments match this suffix
            int matches = freq[suffix];
            // Avoid self-pairing if prefix == suffix
            if (prefix == suffix) matches--;
            count += matches;
        }
    }
    return count;
}
int main() {
    int code = 1212;
    vector<int> fragments = {1, 12, 12, 212};
    cout << "Number of valid pairs: " << countPairs(code, fragments) << endl;
    return 0;
}
