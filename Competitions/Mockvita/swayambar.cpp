#include <bits/stdc++.h>
using namespace std;

//Declaring constants
char MOJITO = 'm';
char RUM = 'r';

struct Preference{
    int rum, mojito;

    Preference() {
        this->rum = 0;
        this->mojito = 0;
    }

    void updatePreferences(char choice) {
        if (choice == MOJITO) this->mojito++;
        else this->rum++;
    }
};

int getUnmatchedPairs(const int pairs, const string brides, const string grooms) {
    int unmatchedPairs = 0;
    Preference bridePreference, groomPreference;

    for (int i = 0; i < pairs; i++) {
        bridePreference.updatePreferences(brides[i]);
        groomPreference.updatePreferences(grooms[i]);
    }

    unmatchedPairs = abs(bridePreference.mojito - groomPreference.mojito) +
        abs(bridePreference.rum - groomPreference.rum);

    return unmatchedPairs;
}

int main() {
    //pairs
    int pairs;
    cin >> pairs;
    //brides
    string brides;
    cin >> brides;
    //grooms
    string grooms;
    cin >> grooms;

    cout << getUnmatchedPairs(pairs, brides, grooms);

    return 0;
}