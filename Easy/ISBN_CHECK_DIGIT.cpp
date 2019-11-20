/*Goal
International Standard Book Number (ISBN) is a unique numeric commercial book identifier.

Before year 2007 ISBNs were 10-digit long. After that year ISBNs extended to 13 digits. In both ISBN-10 and ISBN-13 standards, the last digit is the check digit, for error detection.

ISBN-10 check digit is calculated by Modulus 11 with decreasing weights on the first 9 digits.
Example: 030640615?
0×10 + 3×9 + 0×8 + 6×7 + 4×6 + 0×5 + 6×4 + 1×3 + 5×2 = 130.
130 / 11 = 11 remainder 9.
Check digit is the value needed to add to the sum to make it dividable by 11. In this case it is 2.
So the valid ISBN is 0306406152.
In case 10 being the value needed to add to the sum, we use X as the check digit instead of 10.

ISBN-13 check digit is calculated by Modulus 10 with alternate weights of 1 and 3 on the first 12 digits.
Example: 978030640615?
9×1 + 7×3 + 8×1 + 0×3 + 3×1 + 0×3 + 6×1 + 4×3 + 0×1 + 6×3 + 1×1 + 5×3 = 93.
93 / 10 = 9 remainder 3.
Check digit is the value needed to add to the sum to make it dividable by 10. So the check digit is 7. The valid ISBN is 9780306406157.

Your task is to validate a list of ISBNs.

A valid ISBN should contain the digits 0 to 9 only, except for the check digit which is determined as explained above. X or other improper characters appearing in the wrong place will render an ISBN invalid.*/

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
    vector<string> ID;
    for (int i = 0; i < N; i++) {
        string ISBN;
        getline(cin, ISBN);
        ID.push_back(ISBN);
    }
    
    int invalid = 0;
    vector<int>index;
    for(int i = 0; i< N; i++)
    {
        if(ID[i].length() == 10)
        {
            int sum = 0;
            string s = ID[i];
            for(int j = 0; j < s.length()-1; j++)
            {
                sum = sum + ((10-j)*(int(s[j])-48));
            }
            int rem = sum % 11;
            if(rem !=0)
            rem = 11 - rem;
            
            if(rem != 10 && rem != (int(s[9])-48))
            {
               // cerr<<rem<<" "<<(int(s[9])-48)<<endl;
               // cerr<<i<<endl;
                index.push_back(i);
                invalid++;
            }
            if(rem == 10 && s[9] != 'X')
            {
                index.push_back(i);
                invalid++;
            }
        }
        else if(ID[i].length() == 13)
        {
            string s = ID[i];
            int sum  = 1 * (int(s[0]) - 48) + 3 * (int(s[1]) - 48) + 1 * (int(s[2]) - 48) + 3 * (int(s[3]) - 48) + 1 * (int(s[4]) - 48) + 3 * (int(s[5]) - 48) + 1 * (int(s[6]) - 48) + 3 * (int(s[7]) - 48) + 1 * (int(s[8]) - 48) + 3 * (int(s[9]) - 48) + 1 * (int(s[10]) - 48) + 3 * (int(s[11]) - 48);
            int rem = sum % 10;
            if(rem !=0)
            rem = 10 - rem;
            if(rem != 10 && rem != (int(s[12]) - 48))
            {
                index.push_back(i);
                invalid++;
            }
            if(rem == 10 && (int(s[12])) != 120)
            {
                index.push_back(i);
                invalid++;
            }
        }
        else
        {
            index.push_back(i);
            invalid++;
        }
    }
    cout <<invalid<<" invalid:" << endl;
    for(auto i : index)
    {
        cout<<ID[i]<<endl;
    }
}
