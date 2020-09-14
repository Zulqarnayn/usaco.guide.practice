// USACO 2017 US Open Contest, Bronze
// Problem 1. The Lost Cow

#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main()
{
     freopen("lostcow.in","r",stdin);
    // reuse standard in to read from "lostcow.in"
     freopen("lostcow.out","w",stdout);
    // reuse standard out to write to "lostcow.out"

     int x, y;
     cin >> x >> y;

     if(x == y) {
          cout << 0 << "\n";
          return 0;
     }

     bool isDestinationLower = y < x;
     int curr = 1, total = 0, prevDist = x, newDist = 0;

     while(1) {
          newDist = x + curr;
          // cout << prevDist << " " << newDist << endl;
          total += abs(newDist - prevDist);
          // cout << total << endl;
          if(isDestinationLower) {
               if(newDist <= y) {
                    total -= (y - newDist);
                    break;
               }
          } else {
               if(newDist >= y) {
                    total -= (newDist - y);
                    break;
               }
          }
          prevDist = newDist;
          curr *= (-2);

     }
     cout << total << "\n";
     

}
