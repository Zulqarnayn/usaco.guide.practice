#include <iostream>
#include <string>
using namespace std;

struct Shell {
    int a, b, g;
};

int calc(Shell arr[], int size, int initialPosition) {
	
    int currPos = initialPosition, cnt = 0;

    for(int i = 0; i < size; i++) {
        if(currPos == arr[i].a) {
            currPos = arr[i].b;
        } else if (currPos == arr[i].b) {
            currPos = arr[i].a;
        }
        cnt += (currPos == arr[i].g);
    }

    return cnt;
}

int main()
{
     freopen("shell.in","r",stdin);
    // reuse standard in to read from "paint.in"
     freopen("shell.out","w",stdout);
    // reuse standard out to write to "paint.out"
    int N, a, b, g;
    cin >> N;
    Shell arr[N];
    for(int i = 0; i < N; i++) {
        cin >> a >> b >> g;
        arr[i].a = a;
        arr[i].b = b;
        arr[i].g = g;
    }
    
	int ans1 = calc(arr, N, 1);
	int ans2 = calc(arr, N, 2);
	int ans3 = calc(arr, N, 3);
	
	cout << max( ans1 , max(ans2, ans3)) << "\n";
}
