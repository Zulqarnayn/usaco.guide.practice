// USACO 2018 December Contest, Bronze
// Problem 1. Mixing Milk

#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main()
{
     freopen("mixmilk.in","r",stdin);
    // reuse standard in to read from "mixmilk.in"
     freopen("mixmilk.out","w",stdout);
    // reuse standard out to write to "mixmilk.out"

     pair <int, int> mixmilk[3];

     for(int i = 0; i < 3; i++) {
     	cin >> mixmilk[i].first >> mixmilk[i].second;
     }

     for(int i = 0; i < 100; i++) {
     	int a = i % 3;
     	int b = (i+1) % 3;
     	int amountToBeGiven = mixmilk[a].second + mixmilk[b].second;
     	if(amountToBeGiven <= mixmilk[b].first) {
     		mixmilk[a].second = 0;
     		mixmilk[b].second = amountToBeGiven;
     	} else {
     		int amountLeft = amountToBeGiven - mixmilk[b].first;
     		mixmilk[a].second = amountLeft;
     		mixmilk[b].second = mixmilk[b].first;
     	}
     }

     for(int i = 0; i < 3; i++) {
        cout << mixmilk[i].second << "\n";
     }

}
