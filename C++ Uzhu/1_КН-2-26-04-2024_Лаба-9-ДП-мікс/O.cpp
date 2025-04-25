#include <bits/stdc++.h>

const int MAX_TIME = 500000;
const int NUM_ENERGY_TYPES = 4;

std::vector<std::vector<int>> transitions;
std::vector<std::vector<bool>> dp(MAX_TIME, std::vector<bool>(NUM_ENERGY_TYPES, false));

int getEnergyIndex(const std::string& energyType) {
    if (energyType == "CHEMICAL") return 0;
    if (energyType == "ELECTRIC") return 1;
    if (energyType == "MECHANICAL") return 2;
    if (energyType == "THERMAL") return 3;
    return -1;
}

int calculateMinDifference(int target, const std::string& finalEnergyType) {
    std::fill(dp.begin(), dp.end(), std::vector<bool>(NUM_ENERGY_TYPES, false));  
    for (int i = 0; i < NUM_ENERGY_TYPES; ++i) {
        dp[0][i] = true;
    }

    for (int time = 0; time < 2 * target; ++time) {
        for (int energyType = 0; energyType < NUM_ENERGY_TYPES; ++energyType) {
            if (dp[time][energyType]) {
                for (const auto& transition : transitions) {
                    if (transition[0] == energyType) {
                        int nextTime = time + transition[2];
                        int nextEnergyType = transition[1];
                        if (nextTime < MAX_TIME) {
                            dp[nextTime][nextEnergyType] = true;
                        }
                    }
                }
            }
        }
    }

    int finalEnergyIndex = getEnergyIndex(finalEnergyType);
    if (finalEnergyIndex == -1) return -1;

    for (int i = 0; ; ++i) {
        if ((target + i < MAX_TIME) && dp[target + i][finalEnergyIndex]) {
            return i;
        }
        if ((target - i >= 0) && dp[target - i][finalEnergyIndex]) {
            return i;
        }
    }

    return -1;
}

int main() {
    int transitionCount, target;
    std::string finalEnergyType;

    while (std::cin >> transitionCount >> target >> finalEnergyType) {
        transitions.clear();

        for (int i = 0; i < transitionCount; ++i) {
            std::string inputEnergy, outputEnergy;
            int time;
            std::cin >> inputEnergy >> outputEnergy >> time;

            int inputIndex = getEnergyIndex(inputEnergy);
            int outputIndex = getEnergyIndex(outputEnergy);

            if (inputIndex == -1 || outputIndex == -1) continue;  

            transitions.push_back({inputIndex, outputIndex, time});
        }

        int result = calculateMinDifference(target, finalEnergyType);

        if (result == -1) {
            std::cout << "Error in processing" << std::endl;
        } else {
            std::cout << result << std::endl;
        }
    }

    return 0;
}
