// USACO 2015 December Contest, Bronze
// Problem 2. Speeding Ticket

#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main()
{
     freopen("speeding.in","r",stdin);
    // reuse standard in to read from "speeding.in"
     freopen("speeding.out","w",stdout);
    // reuse standard out to write to "speeding.out"

     int N, M;
     cin >> N >> M;
     int roadSegment[N], speedLimit[N], BessieSegment[M], BessieL[M];

     int limit[101], bessieLimit[101];
     for(int i = 1; i < 101; i++) {
          limit[i] = 0;
          bessieLimit[i] = 0;
     }

     for(int i = 0; i < N; i++) {
          cin >> roadSegment[i] >> speedLimit[i];
          if(i > 0) {
               roadSegment[i] += roadSegment[i-1];
               limit[roadSegment[i]] = speedLimit[i];
          } else {
               limit[roadSegment[i]] = speedLimit[i];
          }
     }

     for(int i = 0; i < M; i++) {
          cin >> BessieSegment[i] >> BessieL[i];
          if(i > 0) {
               BessieSegment[i] += BessieSegment[i-1];
               bessieLimit[BessieSegment[i]] = BessieL[i];
          } else {
               bessieLimit[BessieSegment[i]] = BessieL[i];
          }
     }

     for(int i = 100; i >= 1; i--){
          if(limit[i] == 0)
               limit[i] = limit[i+1];
     }

     for(int i = 100; i >= 1; i--){
          if(bessieLimit[i] == 0)
               bessieLimit[i] = bessieLimit[i+1];
     }

     int mn = 0;
     for(int i = 1; i < 101; i++){
          mn = max(mn, bessieLimit[i] - limit[i]);
     }
     cout << mn << "\n";
}
