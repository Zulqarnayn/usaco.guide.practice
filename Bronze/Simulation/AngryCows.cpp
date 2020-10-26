// USACO 2016 January Contest, Bronze
// Problem 2. Angry Cows

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int positionCount;
long long int position[101];

int balesExplodeAtForward(int idx, int radius) {
    int target = position[idx] + radius;
    int nextIndex = idx + 1;
    int count = 0;
    bool shouldExit = true;
    while(true) {
        while(nextIndex < positionCount && position[nextIndex] <= target) {
            count++;
            shouldExit = false;
            nextIndex++;
        }
        if (shouldExit) break;
        shouldExit = true;
        radius++;
        target = position[nextIndex-1] + radius;
    }
    cerr << "Count:  " << count << " value: "<< position[idx] << endl;
    return count;
}

int balesExplodeAtBackward(int idx, int radius) {
    int target = position[idx] - radius;
    int nextIndex = idx - 1;
    int count = 0;
    bool shouldExit = true;
    while(true) {
        while(nextIndex >= 0 && position[nextIndex] >= target) {
            count++;
            shouldExit = false;
            nextIndex--;
        }
        if (shouldExit) break;
        shouldExit = true;
        radius++;
        target = position[nextIndex+1] - radius;
    }
    cerr << "Count:  " << count << " value: "<< position[idx] << endl;
    return count;
}

int numberOfBalesExplodeAt(int idx, bool isForward) {
    if(isForward)
        return balesExplodeAtForward(idx, 1);
    else 
        return balesExplodeAtBackward(idx, 1);
}

int main()
{
    freopen("angry.in","r",stdin);
    // reuse standard in to read from "angry.in"
    freopen("angry.out","w",stdout);
    // reuse standard out to write to "angry.out"
    
    cin >> positionCount;

    for(int i = 0; i < positionCount; i++) {
        cin >> position[i];
    }

    sort(position, position + positionCount);
    int maximumBales = 1;
    for(int i = 0; i < positionCount; i++) {
        if(i == 0) {
            int noOfExplodedBales = numberOfBalesExplodeAt(i, true);
            cerr << noOfExplodedBales << "\n";
            maximumBales = max(maximumBales, noOfExplodedBales + 1);
        } else if (i == positionCount - 1) {
            int noOfExplodedBales = numberOfBalesExplodeAt(i, false);
            cerr << noOfExplodedBales << "\n";
            maximumBales = max(maximumBales, noOfExplodedBales + 1);
        } else {
            int noOfExplodedBalesForward = numberOfBalesExplodeAt(i, true);
            cerr << endl << noOfExplodedBalesForward << "\n";
            int noOfExplodedBalesBackward = numberOfBalesExplodeAt(i, false);
            cerr << noOfExplodedBalesBackward << "\n" << "\n";
            maximumBales = max(maximumBales, noOfExplodedBalesForward + noOfExplodedBalesBackward + 1);
        }
    }
    cout << maximumBales << "\n";

}
/*
7
5
7
9
10
11
13
15
*/

