#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
#include <ctype.h> // for using stoi function


using namespace std;


// declaration of functions
bool isWellFormedCommandString(string command);
int single_command(string command); // validates a single command for isWellFormedCommandString
bool crossedOriginOnItsPath(string command);


int main ()

    {
        
        assert(crossedOriginOnItsPath("1n2s"));
        assert(crossedOriginOnItsPath("12w1e"));
        assert(crossedOriginOnItsPath("1nw16se"));
        assert(crossedOriginOnItsPath("771ne198sw"));
        assert(crossedOriginOnItsPath("-1w-10e"));
        assert(crossedOriginOnItsPath("-145n-1s"));
        assert(crossedOriginOnItsPath("-13nw-111se1n120s"));
        assert(crossedOriginOnItsPath("999nw998se-999n-999s"));


        
       
        assert(isWellFormedCommandString("12n123S310w"));
        assert(isWellFormedCommandString("123N-778sw900e767nw"));
        assert(isWellFormedCommandString("25n68nw89nE1s-20W+21e"));
        assert(isWellFormedCommandString("123n+12S-1e"));
        assert(isWellFormedCommandString("12n"));
        assert(isWellFormedCommandString("12n123S"));
       
        
    return 0;

    }


// definition of crossedOriginOnItsPath

bool crossedOriginOnItsPath(string command)


{
    
    int Command_start_pos = 0; // position within string while calculating directions
    int NS_count = 0; // total sum of coordinates in the north & south direction
    int WE_count  = 0; // total sum of coordinates in the west & east direction
    int Number_of_steps = 0; // amount to be added in each respective direction
    int Last_digit_position = 0; //position of last digit before assigning digits to Number_Temp
    string Number_Temp; // assigned digits from start of string to end of string
    
    
    if (isWellFormedCommandString(command) == false) // program won't run further if command
        return false;                                // not well formed
    
    // main loop of program that executes while haven't reached end of string
    while (Command_start_pos < command.size())
    {
        
        // increments loop until encouters a nondigit & identifies position of last digit
        
        for (int k = Command_start_pos; (! isalpha (command[k])); k++)
        {
            Last_digit_position = k;
        }
        
        // Number_Temp assigned the substring of digits from start of first digit to last digit
        
        Number_Temp = command.substr(Command_start_pos, Last_digit_position - Command_start_pos + 1);
        
        // converts the string of first digit to last digit to int for computation
        
        Number_of_steps = stoi (Number_Temp, nullptr, 10);
        
        
        // loop for determining in which direction coordinates go
        
        for (int k = Last_digit_position + 1; ; k++)
        {
            if (k == command.size()) // takes care of when we reach the end of command string
            {
                Command_start_pos = k; // means we have reached the end of the string
                break;
            }
            
            if  (! isalpha (command[k])) // breaks because we reach beginning of new command
            {
                Command_start_pos = k;
                break;
            }
            
            switch (tolower (command[k]))
            {
                case 'n':
                    NS_count = NS_count + Number_of_steps;
                    break;
                case 's':
                    NS_count = NS_count - Number_of_steps;
                    break;
                case 'w':
                    WE_count = WE_count + Number_of_steps;
                    break;
                case 'e':
                    WE_count = WE_count - Number_of_steps;
                    break;
            }
        }
        
        cerr << NS_count << endl;
        cerr << WE_count << endl;
        
    }
    
    
    if ((NS_count == 0) && (WE_count == 0)) // final control flow
        return true;
    else
        return false;
}





// definition of isWellFormedCommandString
bool isWellFormedCommandString(string command)

{
    string WorkString;
    int position;
    WorkString = command;
    
    for (;;) // infinite loop
    {
    position = single_command(WorkString);
        
    if (position == -1)
        return false;
    
    else if (position == 0)
        return true;
    
    else
        WorkString = WorkString.substr(position, WorkString.size() - position); // analyzes
    }                                                                   // next part of command
    
}


// definition of single_command with integer return (helper function for isWellFormed)

int single_command(string command)

{
    int first_digit; // first digit in a single command
    int last_digit; // last digit in a single command
    int first_nondigit; // first nondigit in a single command (direction)
    char command_char1; // first letter of two-letter direction command (nw, ne, sw, se)
    char command_char2; // second letter of two-letter direction command
    
    if (command.size() == 0) // ensures that empty string input is invalid
        return -1;
    
    // optional check for + or -
    if ((command[0] == '+') || (command[0] == '-'))
    {
        
        if (command.size() == 1) // cannot have a string with just + or -
            return -1;
        
        first_digit = 1; // position of first digit will be 1 since 0 taken by sign
        last_digit = 3; // position of third digit will be 3
    }
    
    else // if there is not an option + or - at start of comamand
    {
        first_digit = 0; // position of first digit will be 0
        last_digit = 2; // position of first digit will be 2
    }
    
    // checks for digit in the first position after optional + or -
    if (isdigit (command[first_digit]))
        
    {
        if (command[first_digit] == '0') // first digit must not be 0
            return -1;
        if ((command.size() == first_digit + 1))
            return -1;
    }
    
    else // cannot have a command without digits
        return -1;
    
    // skips optional digits
    for (int k = first_digit + 1; k <= last_digit; k++)
    {
        if (k == command.size()) // cannot have a command with just digits
            return -1;
        
        first_nondigit = k;
        if (! isdigit (command[k])) // breaks out of loop if we covered all the digits
        {
            break;
        }
        if (k == last_digit)
            first_nondigit = k + 1; // if 3 digits are given, we move to the next character
        
    }
    
    if (isalpha (command[first_nondigit])) // control for direction part of command
        
    {
        command_char1 = tolower (command[first_nondigit]); // converts all to lower case
        
        if (! ((command_char1 == 'n') || (command_char1 == 's') || (command_char1 == 'w') || (command_char1 == 'e')))
            return -1; // commands can only contain the following charcters
    }
    else // returns false if you do not hit letters after digits
        return -1;
    
    if ((command.size () == first_nondigit + 1)) // reached end of command
        return 0;
    
    if (isalpha (command[first_nondigit + 1])) // tests for second letter of command
        
    {
        command_char2 = tolower (command[first_nondigit + 1]); // converts second letter of command to lowercase
        
        if ((command_char1 == 'n') || (command_char1 == 's')) // first character of command can only be n or s
        {
            if ((command_char2 == 'w') || (command_char2 == 'e')) // second character of command can only be w or e
            {
                if (command.size() == first_nondigit + 2) // if second letter is last character in string
                    return 0;
                else
                    return first_nondigit + 2; // index of first character after the 2nd letter
                
            }
            else // move onto next character after 'n' or 's'
                return first_nondigit + 1;
        }
        
        else // moves onto next character if first command letter is not 'n' or 's'
        {
            return first_nondigit + 1;
            
        }
    }
    
    else // moves onto next command if there is not another letter after single direction char
        {
            return first_nondigit +1;
        }
        
        return -1;
    }