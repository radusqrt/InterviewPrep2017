// Knapsack - top-down - 35p
#include <iostream>
#include <fstream>

int constexpr MAXN = 5001;
int constexpr MAX_WEIGHT = 10001;
int objectsNum, maxWeight;
int weights[MAXN], prices[MAXN], cache[MAXN][MAX_WEIGHT];
bool isCached[MAXN][MAX_WEIGHT];

int dp(int lastPos, int weight) {
    if (lastPos < 0 || weight < 0) {
        return 0;
    }

    if (isCached[lastPos][weight]) {
        return cache[lastPos][weight];
    }

    if (weights[lastPos] > weight) {
        return dp(lastPos - 1, weight);
    }

    cache[lastPos][weight] = std::max(
        dp(lastPos - 1, weight - weights[lastPos]) + prices[lastPos],
        dp(lastPos - 1, weight)
    );
    isCached[lastPos][weight] = true;

    return cache[lastPos][weight];
}

int main() {
  std::ifstream in("rucsac.in");
  std::ofstream out("rucsac.out");

  in >> objectsNum >> maxWeight;
  for (int i = 0; i < objectsNum; ++i) {
      in >> weights[i] >> prices[i];
  }

  out << dp(objectsNum - 1, maxWeight);
  return 0;
}
