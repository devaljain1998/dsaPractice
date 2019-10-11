#include<bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/gold-mine-problem/
Correct Answer.... Yeah!!!!
    My first DP problem solved (except for fibonacci)

My Approach:
Use the values from the previous columns to fill get the optimal value in the next.. (i.e maximum of llc, lc and ulc)
*/

struct Point{
    int x, y;//Matrix Points
    int m, n; //Matrix Dimensions

    Point(int x, int y, int n, int m) : x(x), y(y), n(n), m(m) {}

    long int upperLeftValue(vector <vector <int> > &matrix, vector <vector <int> > &optimalGoldValue){
        if(this->x && this->y){ //x and y are not zero
            return optimalGoldValue[this->x-1][this->y-1] + matrix[this->x][this->y];
        } 
        return -1;
    }

    long int LeftValue(vector <vector <int> > &matrix, vector <vector <int> > &optimalGoldValue){
        if(this->y){ //y is not zero
            return optimalGoldValue[this->x][this->y-1] + matrix[this->x][this->y];
        } 
        return -1;
    }

    long int lowerLeftValue(vector <vector <int> > &matrix, vector <vector <int> > &optimalGoldValue){
        if(this->x <= this->n-2 && this->y){ //y is not zero
            return optimalGoldValue[this->x+1][this->y-1] + matrix[this->x][this->y];
        } 
        return -1;
    }
};

void inputFunc(vector <vector <int> > &matrix, vector <vector <int> > &optimalGoldValue){
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cin >> matrix[i][j];
            }
            
        }

        for(int i=0; i<matrix.size(); i++){ optimalGoldValue[i][0] = matrix[i][0]; }
}

void displayVector(vector <vector <int> > &matrix){
    cout << "displaying vector\n";
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;    
        }
        cout << endl;
}

long int getMaximumGoldValue(vector<vector<int>> &matrix, vector<vector<int>> &optimalGoldValue, int n, int m)
{
    int maxELement = -1;
    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            Point p(i, j, n, m);
            optimalGoldValue[i][j] = max(max(p.upperLeftValue(matrix, optimalGoldValue), p.LeftValue(matrix, optimalGoldValue)), p.lowerLeftValue(matrix, optimalGoldValue));
        }
    }

    for (int i = 0; i < n; i++)
    {
        maxELement = max(optimalGoldValue[i][m - 1], maxELement);
    }
    return maxELement;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m ;

        vector <vector <int> > matrix( n , vector<int> (m, 0));
        vector <vector <int> > optimalGoldValues( n , vector<int> (m, -1));

        inputFunc(matrix, optimalGoldValues);
        cout << getMaximumGoldValue(matrix, optimalGoldValues, n, m) << endl;
    }
    return 0;
}