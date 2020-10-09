// USACO 2016 February Contest, Bronze
// Problem 2. Circular Barn

#include <iostream>
#include <string>
using namespace std;

int main()
{
    freopen("cbarn.in","r",stdin);
    // reuse standard in to read from "cbarn.in"
    freopen("cbarn.out","w",stdout);
    // reuse standard out to write to "cbarn.out"
    int numberOfBarn, totalCow = 0, minTotal = (int)1e9;
    cin >> numberOfBarn;
    int cows[numberOfBarn];

    for(int i = 0; i < numberOfBarn; i++) {
        cin >> cows[i];
        totalCow += cows[i];
    }

    for(int i = 0; i < numberOfBarn; i++) {
        int total = 0, totalRemaining = totalCow; 
        for(int j = i; j < (i + numberOfBarn); j++) {
            totalRemaining -= cows[(j%numberOfBarn)];
            total += totalRemaining;
        }
        minTotal = min(minTotal, total);
    }
    cout << minTotal << "\n";
}
