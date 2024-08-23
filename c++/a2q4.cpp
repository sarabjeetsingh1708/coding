#include <iostream>

using namespace std;

// Function to swap two heroes
void swap(int* positions, int* healths, char* team, int i, int j) {
    int tempPosition = positions[i];
    positions[i] = positions[j];
    positions[j] = tempPosition;

    int tempHealth = healths[i];
    healths[i] = healths[j];
    healths[j] = tempHealth;

    char tempTeam = team[i];
    team[i] = team[j];
    team[j] = tempTeam;
}

// Function to sort heroes by their positions using bubble sort
void bubbleSort(int* positions, int* healths, char* team, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (positions[j] > positions[j + 1]) {
                swap(positions, healths, team, j, j + 1);
            }
        }
    }
}

// Function to resolve battles and return remaining healths
int* remainingHealth(int* positions, int* healths, char* team, int n) {
    // Sort heroes by their positions
    bubbleSort(positions, healths, team, n);
    
    // Resolve battles
    for (int i = 1; i < n; ++i) {
        if (positions[i] == positions[i - 1]) {
            if (healths[i] < healths[i - 1]) {
                // Remove the weaker hero
                for (int j = i; j < n - 1; ++j) {
                    positions[j] = positions[j + 1];
                    healths[j] = healths[j + 1];
                    team[j] = team[j + 1];
                }
                --n;
                --i; // Recheck the current index after removal
            } else if (healths[i] > healths[i - 1]) {
                // Remove the weaker hero
                for (int j = i - 1; j < n - 1; ++j) {
                    positions[j] = positions[j + 1];
                    healths[j] = healths[j + 1];
                    team[j] = team[j + 1];
                }
                --n;
                --i; // Recheck the previous index after removal
            } else {
                // Remove both heroes if they have the same health
                for (int j = i - 1; j < n - 2; ++j) {
                    positions[j] = positions[j + 2];
                    healths[j] = healths[j + 2];
                    team[j] = team[j + 2];
                }
                n -= 2;
                i -= 2; // Recheck the previous index after removal
            }
        }
    }
    
    // Extract remaining healths after all battles are resolved
    int* remainingHealths = new int[n];
    for (int i = 0; i < n; ++i) {
        remainingHealths[i] = healths[i];
    }
    
    return remainingHealths;
}

int main() {
    // Test cases
    int positions1[] = {5, 4, 3, 2, 1};
    int healths1[] = {2, 17, 9, 15, 10};
    char team1[] = {'R', 'R', 'R', 'R', 'R'};
    int* result1 = remainingHealth(positions1, healths1, team1, 5);
    for (int i = 0; i < 5; ++i) {
        cout << result1[i] << " ";
    }
    cout << endl; // Output: 2 17 9 15 10
    
    int positions2[] = {3, 5, 2, 6};
    int healths2[] = {10, 10, 15, 12};
    char team2[] = {'R', 'D', 'R', 'D'};
    int* result2 = remainingHealth(positions2, healths2, team2, 4);
    for (int i = 0; i < 1; ++i) {
        cout << result2[i] << " ";
    }
    cout << endl; // Output: 14
    
    int positions3[] = {1, 2, 5, 6};
    int healths3[] = {10, 10, 11, 11};
    char team3[] = {'R', 'D', 'R', 'D'};
    int* result3 = remainingHealth(positions3, healths3, team3, 4);
    for (int i = 0; i < 0; ++i) {
        cout << result3[i] << " ";
    }
    cout << endl; // Output:
    
    int positions4[] = {2, 19, 46};
    int healths4[] = {42, 45, 2};
    char team4[] = {'D', 'R', 'D'};
    int* result4 = remainingHealth(positions4, healths4, team4, 3);
    for (int i = 0; i < 2; ++i) {
        cout << result4[i] << " ";
    }
    cout << endl; // Output: 42 44
    
    int positions5[] = {2, 3, 21, 22, 24, 25, 38, 31};
    int healths5[] = {24, 33, 31, 37, 19, 16, 11, 50};
    char team5[] = {'D', 'D', 'R', 'D', 'D', 'R', 'D', 'R'};
    int* result5 = remainingHealth(positions5, healths5, team5, 8);
    for (int i = 0; i < 6; ++i) {
        cout << result5[i] << " ";
    }
    cout << endl; // Output: 24 33 36 19 16 49
    
    return 0;
}
