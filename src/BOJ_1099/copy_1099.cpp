#include <iostream>
#include <string>

using namespace std;
int n;
string sentence;
int length;
string words[50][50];
int index[50];
int dp[50];

int check_word(string word, int start, int l) {
    bool ch[l];
    for (int i = 0; i < l; ++i) {
        ch[i] = false;
    }

    for (int i = 0; i < l; ++i) {
        bool c = true;
        for (int j = 0; j < l; ++j) {
            if (ch[j]) continue;
            if (sentence[start + i] == word[j]) {
                ch[j] = true;
                c = false;
                break;
            }
        }
        if (c) return -1;
    }

    int cost = l;
    for (int i = 0; i < l; ++i) {
        if (sentence[start + i] == word[i]) cost--;
    }

    return cost;
}

int find(int info[50][50], int start, int length, int pos_cost = 0, int max = INT32_MAX) {
    if (pos_cost > max) return -1;
    for (int i = start; i < length; ++i) {
        if (info[start][i] == -1) continue;
        int c;
        if (i + 1 == length) {
            c = pos_cost + info[start][i];
        } else {
            c = find(info, i + 1, length, pos_cost + info[start][i], max);
        }
        if (c == -1) continue;
        if (c < max) max = c;
    }

    return max == INT32_MAX ? -1 : max;
}

int calc(int start) {
    if (dp[start] != -2) return dp[start];
    dp[start] = -1;

    int c;
    for (int i = start; i < length; ++i) {
        int l = i - start + 1;
        int cost = -1;
        for (int j = 0; j < index[l - 1]; ++j) {
            c = check_word(words[l - 1][j], start, l);
            if (c == -1) continue;
            if (cost == -1 || cost > c) cost = c;
        }

        if (cost == -1) continue;
        if (i + 1 == length) c = 0;
        else c = calc(i + 1);

        if (c == -1) continue;
        c += cost;

        if (dp[start] == -1 || c < dp[start])
            dp[start] = c;
    }

    return dp[start];
}

int main() {
    cin >> sentence;
    cin >> n;

    length = sentence.length();

    for (int i = 0; i < 50; ++i) {
        index[i] = 0;
        dp[i] = -2;
    }

    for (int i = 0; i < n; ++i) {
        string w;
        cin >> w;
        int l = w.length();
        words[l - 1][index[l - 1]++] = w;
    }

    cout << calc(0) << endl;

    return 0;
}