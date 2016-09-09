#include <cstdio>
#include <algorithm>

#define MAX_NUMBER_OF_STALLS 100100

int stallLocations[MAX_NUMBER_OF_STALLS];

void readStallLocations(int numberOfStalls) {
    for (int i = 0; i < numberOfStalls; i++) scanf("%d", &stallLocations[i]);
}

void sortStallLocations(int numberOfStalls) {
    std::sort(stallLocations, stallLocations + numberOfStalls);
}

bool allotmentPossible(int numberOfCows, int numberOfStalls, int distance) {
    int lastPosition = stallLocations[0];
    int currentCowsAllotted = 1;
    for (int i = 1; i < numberOfStalls; i++) {
        if (stallLocations[i] - lastPosition >= distance) {
            currentCowsAllotted++;
            lastPosition = stallLocations[i];
        }
    }
    return (currentCowsAllotted >= numberOfCows);
}

int binarySearchMaxMinDistance(int numberOfCows, int numberOfStalls) {
    int lower = 1, upper = 1000000006, ans = -1;
    while (lower <= upper) {
        int guess = (upper + lower) / 2;
        //printf("%d %d %d::\n", guess, lower, upper);
        if (allotmentPossible(numberOfCows, numberOfStalls, guess)) {
            lower = guess + 1;
            ans = guess;
        }
        else upper = guess - 1;
    }
    return ans;
}

void solveTcase(void) {
    int numberOfStalls, numberOfCows;
    scanf("%d%d", &numberOfStalls, &numberOfCows);
    readStallLocations(numberOfStalls);
    sortStallLocations(numberOfStalls);
    printf("%d\n", binarySearchMaxMinDistance(numberOfCows, numberOfStalls));

}

int main(void) {
    int tcase;
    scanf("%d", &tcase);
    for (int _i = 1; _i <= tcase; _i++) solveTcase();
}
