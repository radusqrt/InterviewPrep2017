// Cel mai lung subsir comun - top-down - 100p
#include <iostream>
#include <fstream>

int constexpr MAXN = 1025;

int count;
int cache[MAXN][MAXN], firstVec[MAXN], secondVec[MAXN], backwards[MAXN];
bool isCached[MAXN][MAXN];

int dp(int i, int j) {
    if (i < 0 || j < 0) return 0;

    if (isCached[i][j]) {
        return cache[i][j];
    }

    cache[i][j] = std::max(
        dp(i - 1, j - 1) + (firstVec[i] == secondVec[j]),
        std::max(dp(i - 1, j), dp(i, j - 1))
    );
    isCached[i][j] = true;
    return cache[i][j];
}

int main() {
    std::ifstream in("cmlsc.in");
    std::ofstream out("cmlsc.out");

    int lenFirst, lenSecond;

    in >> lenFirst >> lenSecond;
    for (int i = 0; i < lenFirst; ++i) {
        in >> firstVec[i];
    }

    for (int i = 0; i < lenSecond; ++i) {
        in >> secondVec[i];
    }

    // Print longest common sequence's size
    out << dp(lenFirst - 1, lenSecond - 1) << "\n";

    int i, j;
    for (i = lenFirst - 1, j = lenSecond - 1; i >= 0 && j >= 0; ) {
        if (firstVec[i] == secondVec[j]) {
            backwards[count++] = firstVec[i];
            --i;
            --j;
        } else if (i == 0 || cache[i-1][j] < cache[i][j-1]) {
            --j;
        } else {
            --i;
        }
    }

    // Print longest common sequence
    for (int i = count - 1; i >= 0; --i) {
        out << backwards[i] << " ";
    }
    out << "\n";
    return 0;
}
