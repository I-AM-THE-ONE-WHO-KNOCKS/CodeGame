/*The Goal
Binary with 0 and 1 is good, but binary with only 0, or almost, is even better! Originally, this is a concept designed by Chuck Norris to send so called unary messages.

Write a program that takes an incoming message as input and displays as output the message encoded using Chuck Norris’ method.

Rules
Here is the encoding principle:

The input message consists of ASCII characters (7-bit)
The encoded output message consists of blocks of 0
A block is separated from another block by a space
Two consecutive blocks are used to produce a series of same value bits (only 1 or 0 values):
- First block: it is always 0 or 00. If it is 0, then the series contains 1, if not, it contains 0
- Second block: the number of 0 in this block is the number of bits in the series
 	Example
Let’s take a simple example with a message which consists of only one character: Capital C. C in binary is represented as 1000011, so with Chuck Norris’ technique this gives:

0 0 (the first series consists of only a single 1)
00 0000 (the second series consists of four 0)
0 00 (the third consists of two 1)
So C is coded as: 0 0 00 0000 0 00

 
Second example, we want to encode the message CC (i.e. the 14 bits 10000111000011) :

0 0 (one single 1)
00 0000 (four 0)
0 000 (three 1)
00 0000 (four 0)
0 00 (two 1)
So CC is coded as: 0 0 00 0000 0 000 00 0000 0 00 */

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
    string MESSAGE;
    getline(cin, MESSAGE);
    
    vector<int>binary;
    
    if(0 < MESSAGE.length() < 100)
    {
        for(int i = 0; i < MESSAGE.length(); i++)
        {
            char S = MESSAGE[i];
            string bin = "";
            if(S != ' ')
            {
                int val = int(S);
                while(val > 0)
                {
                    (val % 2)?bin.push_back('1'):bin.push_back('0');
                    
                    val /= 2;
                }
                reverse(bin.begin(), bin.end());
            }
            if(bin.length()< 7)
            {
                for(int k = 0; k <7 - bin.length(); k++)
                binary.push_back(0);
            }
            for(int j = 0; j < bin.length(); j++)
                binary.push_back(int(bin[j])-48);
        }
    }
   int j = 0;
   for(int a = 0; a < binary.size(); a++)
    {
        if(a == 0)
        {
            if(binary[a] == 1)
            {
                cout<<"0 0";
            }
            else if(binary[a] == 0)
            {
                cout<<"00 0";
            }
        }
        else
        {
            if(binary[a] == binary[j])
            {
                cout<<"0";
            }
            else if((binary[a] != binary[j]) && (binary[a] == 1))
            {
                cout<<" 0 0";
            }
            else if((binary[a] != binary[j]) && (binary[a] == 0))
            {
                cout<<" 00 0";
            }
            j +=1;
        }
    }
}
