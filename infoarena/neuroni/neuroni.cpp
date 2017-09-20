// Neuroni - bottom-up - 100p
#include <iostream>
#include <fstream>

int constexpr MAXN = 101;

int dp[MAXN][MAXN], n, m;

int main() {
    std::ifstream in("neuroni.in");
    std::ofstream out("neuroni.out");

    in >> n >> m;
    dp[0][0] = m;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            int smallHalf = dp[i][j] / 2;
            int biggerHalf = dp[i][j] - smallHalf;

            if (i % 2 == 1) {
                std::swap(biggerHalf, smallHalf);
            }

            dp[i + 1][j + 1] += biggerHalf;
            dp[i + 1][j] += smallHalf;
        }
    }

    for (int i = 0; i < n; ++i) {
        out << dp[n - 1][i] << " ";
    }
    out << "\n";

    return 0;
}
