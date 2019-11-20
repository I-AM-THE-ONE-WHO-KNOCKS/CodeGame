/*The Goal
Your program must allow Thor to reach the light of power.
Rules
Thor moves on a map which is 40 wide by 18 high. Note that the coordinates (X and Y) start at the top left! This means the most top left cell has the coordinates "X=0,Y=0" and the most bottom right one has the coordinates "X=39,Y=17".

Once the program starts you are given:
the variable lightX: the X position of the light of power that Thor must reach.
the variable lightY: the Y position of the light of power that Thor must reach.
the variable initialTX: the starting X position of Thor.
the variable initialTY: the starting Y position of Thor.
At the end of the game turn, you must output the direction in which you want Thor to go among:
	
N (North)
NE (North-East)
E (East)
SE (South-East)
S (South)
SW (South-West)
W (West)
NW (North-West)
Each movement makes Thor move by 1 cell in the chosen direction.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
    char* X;
    char* Y;
    int start_y = initialTY;
    int start_x = initialTX;

    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        X ="";
        Y ="";

        if(start_y < lightY)
        {
            Y = "S";
            start_y += 1;
        }
        else if(start_y > lightY)
        {
            Y = "N";
            start_y -= 1;
        }
        if(start_x < lightX)
        {
            X = "E";
            start_x += 1;
        }
        else if(start_x > lightX)
        {
            X = "W";
            start_x -= 1;
        }


        // A single line providing the move to be made: N NE E SE S SW W or NW
        cout <<Y<<X<< endl;
    }
}
