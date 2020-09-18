// USACO 2017 December Contest, Bronze
// Problem 2. The Bovine Shuffle

#include <iostream>
#include <string>
using namespace std;

int main()
{
     freopen("shuffle.in","r",stdin);
    // reuse standard in to read from "shuffle.in"
     freopen("shuffle.out","w",stdout);
    // reuse standard out to write to "shuffle.out"
    int n;
    cin >>  n;
    int a[n+1];
    string id, prevCopy[n+1], newCopy[n+1];

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> id;
        prevCopy[i] = id;
    }
    int count = 3;
    
    while(count--) {
        for(int i = 1; i <= n; i++) {
            newCopy[i] = prevCopy[a[i]];
        }
        for(int i = 1; i <= n; i++){
            prevCopy[i] = newCopy[i];
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << newCopy[i] << "\n";
    }
}
