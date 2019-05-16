#include "utils.h"

Utils::Utils()
{

}
char Utils::readChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Try again." << endl;
    }
    return character;
}
