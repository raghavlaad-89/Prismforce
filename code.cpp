#include <iostream>
#include <vector>
using namespace std;

bool canCrossChakravyuha(int p, int a, int b, vector<int> &k) {
    int max_p = p;

    for (int i = 0; i < 11; i++) {
        int enemy_power = k[i];  // total enemy power
        if(i == 3 || i == 7){    // if Abhimanyu is in iteratively next circle
            enemy_power += k[i-1] * 0.5;
        }
        if (p < enemy_power) {
            if (max_p >= enemy_power and b > 0) {
                p = max_p; // Recharge to fight this enemy
                b--;
                p -= enemy_power;
            }
            else if (a > 0) {
                a--; // Use skip
            } else {
                return false; // Abhimanyu loses
            }
        } else {
            // battle is fought and Abhimanyu's powers are reduced
            p -= enemy_power;  
        }
    }
    return true; // Successfully crossed all circles
}

int main() {
    vector<int> k1 = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60}; // Test case 1  // Abhimanyu passed
    vector<int> k2 = {12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72}; // Test case 2  // Abhimanyu failed
    
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
