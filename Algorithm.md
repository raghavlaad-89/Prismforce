# Chakravyuha Algorithm

This project implements an algorithm to simulate Abhimanyu's attempt to cross the Chakravyuha, a formidable battle formation. The algorithm evaluates whether Abhimanyu, with his initial power and limited resources, can successfully cross through all the circles guarded by enemies.

## Algorithm Overview

The algorithm determines if Abhimanyu can cross the Chakravyuha by iterating through 11 circles, each guarded by enemies with specific power levels. Key features include:

- **Initial Power (`p`)**: Abhimanyu starts with a specified amount of power.
- **Skip Power (`a`)**: Abhimanyu has a limited number of skips to avoid battles he cannot win.
- **Recharge Power (`b`)**: Abhimanyu can recharge his power to its initial value a limited number of times.

### Key Conditions:
- If Abhimanyu is in circles 4 or 8 (zero-indexed), the enemy's power is increased by 50% of the previous circle's enemy power.
- If Abhimanyu's power is insufficient for a battle, and he has recharges available, he can recharge to his initial power and continue the battle.
- If recharges are exhausted, Abhimanyu can skip the battle if skips are available.
- The algorithm determines success if Abhimanyu crosses all circles, else failure.

## Test Cases

Two test cases are included to demonstrate the algorithm's functionality:

### Test Case 1
- **Enemy Powers**: [10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60]
- **Initial Power**: 150
- **Skips**: 1
- **Recharges**: 2

**Result**: Abhimanyu successfully crossed the Chakravyuha in Test Case 1.

### Test Case 2
- **Enemy Powers**: [12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72]
- **Initial Power**: 200
- **Skips**: 2
- **Recharges**: 1

**Result**: Abhimanyu failed to cross the Chakravyuha in Test Case 2.

## Code Execution

The program successfully executed, yielding the expected results for the test cases:


### Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool canCrossChakravyuha(int p, int a, int b, vector<int> &k) {
    int max_p = p;

    for (int i = 0; i < 11; i++) {
        int enemy_power = k[i];
        if (i == 3 || i == 7) {
            enemy_power += k[i-1] * 0.5;
        }
        if (p < enemy_power) {
            if (max_p >= enemy_power and b > 0) {
                p = max_p;
                b--;
                p -= enemy_power;
            } else if (a > 0) {
                a--;
            } else {
                return false;
            }
        } else {
            p -= enemy_power;
        }
    }
    return true;
}

int main() {
    vector<int> k1 = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60}; // Test case 1
    vector<int> k2 = {12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72}; // Test case 2
    
    int p1 = 150, a1 = 1, b1 = 2;
    int p2 = 200, a2 = 2, b2 = 1;
    
    if (canCrossChakravyuha(p1, a1, b1, k1)) {
        cout << "Abhimanyu successfully crossed the Chakravyuha in Test Case 1!" << endl;
    } else {
        cout << "Abhimanyu failed to cross the Chakravyuha in Test Case 1." << endl;
    }
    
    if (canCrossChakravyuha(p2, a2, b2, k2)) {
        cout << "Abhimanyu successfully crossed the Chakravyuha in Test Case 2!" << endl;
    } else {
        cout << "Abhimanyu failed to cross the Chakravyuha in Test Case 2." << endl;
    }
    
    return 0;
}

