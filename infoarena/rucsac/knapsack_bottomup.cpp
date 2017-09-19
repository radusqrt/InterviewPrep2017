// Knapsack - bottom-up - 100p
#include <iostream>
#include <fstream>

int constexpr MAXN = 5001;
int constexpr MAX_WEIGHT = 10001;
int objectsNum, maxWeight, globalMax;
int weights[MAXN], prices[MAXN], revenues[MAX_WEIGHT];

int main() {
    std::ifstream in("rucsac.in");
    std::ofstream out("rucsac.out");

    in >> objectsNum >> maxWeight;
    for (int i = 0; i < objectsNum; ++i) {
        in >> weights[i] >> prices[i];
    }

    for (int i = 0; i < objectsNum; ++i) {
        for (int weight = maxWeight - weights[i]; weight >= 0; --weight) {
            if (revenues[weight] + prices[i] > revenues[weight + weights[i]]) {
                revenues[weight + weights[i]] = revenues[weight] + prices[i];
                if (revenues[weight + weights[i]] > globalMax) {
                    globalMax = revenues[weight + weights[i]];
                }
            }
        }
    }

    out << globalMax << "\n";
    return 0;
}
