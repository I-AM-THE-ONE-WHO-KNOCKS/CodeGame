/*The Goal
Casablanca’s hippodrome is organizing a new type of horse racing: duals. During a dual, only two horses will participate in the race. In order for the race to be interesting, it is necessary to try to select two horses with similar strength.

Write a program which, using a given number of strengths, identifies the two closest strengths and shows their difference with an integer (≥ 0).*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<int> inpute;
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        inpute.push_back(Pi);
    }
    
    auto sort_rule = [](int& a, int& b)->bool{
        return(a > b);
    };
    
    sort(inpute.begin(), inpute.end(), sort_rule);
    
    int diff = 1000000;
    for (int i = 1; i < N; i++) {
        int temp = inpute[i-1] - inpute[i];
        if(temp < diff)
            diff = temp;
    }

    cout << diff << endl;
}
