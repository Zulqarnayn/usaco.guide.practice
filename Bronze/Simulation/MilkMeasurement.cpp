// USACO 2017 December Contest, Bronze
// Problem 3. Milk Measurement

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

struct Measurement {
    int day;
    string cowName;
    char sign;
    int changeInOutput;
    static bool comp(const Measurement& a, const Measurement& b) { return a.day < b.day; }
};

map<string, int> cows;

vector<string> getMaxCandidate() {
    int mxCount = 0, currMax = -1001;
    for(map<string, int>:: iterator it = cows.begin(); it != cows.end(); it++) {
        currMax = max(currMax, (*it).second);
    }

    vector <string> displayCandidate;

    for(map<string, int>:: iterator it = cows.begin(); it != cows.end(); it++) {
        if((*it).second == currMax) 
            displayCandidate.push_back((*it).first);
    }
    sort(displayCandidate.begin(), displayCandidate.end());
    return displayCandidate;
}

int main()
{
    freopen("measurement.in","r",stdin);
    // reuse standard in to read from "measurement.in"
    freopen("measurement.out","w",stdout);
    // reuse standard out to write to "measurement.out"
    
    int n;
    cin >> n;

    Measurement mes[n];

    for(int i = 0; i < n; i++) {
        cin >> mes[i].day >> mes[i].cowName >> mes[i].sign >> mes[i].changeInOutput;
    }

    sort(mes, mes + n, Measurement::comp);

    int prevMax = 7, prevMaxCount = 3, noOfDisplayChange = 0;
    
    cows["Bessie"] = 7;
    cows["Elsie"] = 7;
    cows["Mildred"] = 7;

    vector<string> displayCandidate;
    displayCandidate.push_back("Bessie");
    displayCandidate.push_back("Elsie");
    displayCandidate.push_back("Mildred");
    sort(displayCandidate.begin(), displayCandidate.end());

    for(int i = 0; i < n; i++) {
        if(mes[i].sign == '+') {
            cows[mes[i].cowName] += mes[i].changeInOutput;
        } else {
            cows[mes[i].cowName] -= mes[i].changeInOutput;
        }

        vector<string> maxCounterCandidate = getMaxCandidate();

        if(displayCandidate.size() != maxCounterCandidate.size()) {
            noOfDisplayChange++;
            displayCandidate = maxCounterCandidate;
        } else {
            bool are_equal = true;
            for (int i = 0; i < maxCounterCandidate.size(); i++) {
                if (maxCounterCandidate[i] != displayCandidate[i]) {
                    are_equal = false;
                    break;
                }
            }
            if(!are_equal) {
                noOfDisplayChange++;
                displayCandidate = maxCounterCandidate;
            }
        }

    }
    cout << noOfDisplayChange << "\n";

}
