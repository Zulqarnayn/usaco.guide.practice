// USACO 2016 January Contest, Bronze
// Problem 3. Mowing the Field

#include <iostream>
#include <string>
#include <cstring> 
using namespace std;

int grid[1001][1001];
int offsetX = 500, offsetY = 500, currTime = 0;

void setOffsetValueAt(string dir) {
    if(dir[0] == 'N') {
          offsetY++;
    } else if(dir[0] == 'S') {
        offsetY--;
    } else if(dir[0] == 'E') {
        offsetX++;
    } else if(dir[0] == 'W') {
        offsetX--;
    }
}

int main()
{
    freopen("mowing.in","r",stdin);
    // reuse standard in to read from "mowing.in"
    freopen("mowing.out","w",stdout);
    // reuse standard out to write to "mowing.out"
    
    int N;
    cin >> N;

    int steps, maxVal = (int) 2e9;
    string direction;
    memset(grid, -1, sizeof(grid));

    grid[offsetX][offsetY] = 0;

    for(int i = 0; i < N; i++) {
        cin >> direction >> steps;

        for(int j = 0; j < steps; j++) {
            setOffsetValueAt(direction);

            if(grid[offsetX][offsetY] == -1) {
                grid[offsetX][offsetY] = ++currTime;
            } else {
                currTime++;
                maxVal = min(maxVal, currTime - grid[offsetX][offsetY]);
                grid[offsetX][offsetY] = currTime;
            }
        }
    }

    if(maxVal == (int)2e9) {
        cout << -1 << "\n";
    } else {
        cout << maxVal << "\n";
    }
}

