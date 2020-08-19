#include <bits/stdc++.h>
using namespace std;

// Declaring constants:
const char A = 'A', B = 'B', NEUTRAL = '-';

struct Vote {
    int a, b, neutral;
    Vote(): a(0), b(0), neutral(0) {}

    void updateVotes(bool &rightA, bool &leftB, int &votes) {
        //Case 1: left of A and no B:
        if (rightA && !leftB) a += votes;

        //Case 2: right of B and no A:
        else if (leftB && !rightA) b += votes;

        //Case 3: A on left and B on right:
        else if (!rightA && !leftB) neutral += votes;

        //Case 4: Between A and B
        else if (rightA && leftB) {
            int part = (int)(votes / 2);
            a += part;
            b += part;
            neutral += votes % 2;
        }

        //Resetting the votes and flags:
        rightA = leftB = false;
        votes = 0;
    }

    string declareWinner() {
        if (a > b) return "A";
        if (b > a) return "B";
        return "Coalition government";
    }

    void flush() {
        a = 0; b = 0; neutral = 0;
    }

} votebank;

//Queue for votes:
string q;

string decideTheFate() {
    bool rightA = false, leftB = false, neutralEncountered = false;
    int votes = 0;
    const int length = q.length();

    //Traverse the whole string:
    //Update the votes and the flag when A or B comes.
    //Keep traversing if neutral.
    //Break and update the votes if neutral is encountered

    for (int i = 0; i < length; i++) {
        //If neutral is encountered then keep traversing
        //and increasing the votes
        if (q[i] == NEUTRAL) {
            neutralEncountered = true;
            votes++;
        }
        // if A is encountered
        else if (q[i] == A) {
            // if neutral is already encountered 
            if (neutralEncountered == true) {
                rightA = true;
                // have to update the votebank:
                votebank.updateVotes(rightA, leftB, votes);

                //Marking the neutral encountered again as false.
                neutralEncountered = false;
            } else {
                //Votes is 0 in this case
                rightA = false;
                votes = 0;
            }

            votebank.a++;
        }
        // B is encountered
        else if (q[i] == B) {
            // if neutral is already 
            if (neutralEncountered == true) {
                leftB = false;
                // have to update the votebank:
                votebank.updateVotes(rightA, leftB, votes);

                //Marking the neutral encountered again as false.
                neutralEncountered = false;
            } else {
                //Votes is 0 in this case
                leftB = true;
                votes = 0;
            }

            votebank.b++;
        }
    }

    //Checking if neutral lies in the end of the queue:
    if (q[length - 1] ==  NEUTRAL) votebank.updateVotes(rightA, leftB, votes);

    //Checking for the winner:
    return votebank.declareWinner();
}

void test() {
    //A, B, Coalition government

    //TC1
    q = "--AB--AB---A--"; votebank.flush();
    assert(decideTheFate() == "A");
    cout << "TC1 cleared\n";

    //TC2
    q = "A---"; votebank.flush();
    assert(decideTheFate() == "A");
    cout << "TC2 cleared\n";

    //TC1
    q = "A---B"; votebank.flush();
    assert(decideTheFate() == "Coalition government");
    cout << "TC3 cleared\n";
}



int main(int argc, char const *argv[]) {
    //Taking input
    long unsigned int stringSize; cin >> stringSize;
    
    if (stringSize < 1) throw invalid_argument("String size should be greater than 1.");

    cin >> q;

    if (q.length() != stringSize) throw invalid_argument("String length and string size are not equal.");

    string result = decideTheFate();
    cout << result;

    return 0;
}
