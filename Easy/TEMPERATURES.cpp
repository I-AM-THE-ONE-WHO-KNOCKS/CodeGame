/*The Goal
In this exercise, you have to analyze records of temperature to find the closest to zero.

Rules
Write a program that prints the temperature closest to 0 among input data. If two numbers are equally close to zero, positive integer has to be considered closest to zero (for instance, if the temperatures are -5 and 5, then display 5).*/

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
    vector<int>inpute;
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        inpute.push_back(t);
    }
    
    int output = 0;
    if(inpute.size() != 0)
    {
        auto sort_rule = [](int &a, int &b)->bool{
            if((a < 0 ) || (b < 0))
            {
                return(a > b);
            }
            else
            {
                return(a<b);
            }
        };
        
        sort(inpute.begin(), inpute.end(), sort_rule);   
        output = inpute[0];
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << output << endl;
}
