#include <iostream> //cin, cout
#include <string> //getline, find, length, erase, append
#include <algorithm> //transform
using namespace std;

void IgpayAtinlay(string& name);

int main()
{
    string first, last, full; //declare

    cout << "Enter your first name: ";
    getline(cin, first); //fill first name string with user input

    cout << "Enter your last name: ";
    getline(cin, last); //fill last name string with user input

    IgpayAtinlay(first);
    IgpayAtinlay(last); //Does piglatin function for both strings

    transform(first.begin(), first.end(), first.begin(), tolower);
    transform(last.begin(), last.end(), last.begin(), tolower); //transforms strings to lowercase

    first[0] = toupper(first[0]);
    last[0] = toupper(last[0]); //makes first index of both capital

    full = first + " " + last; //puts first and last string together for full name
    cout << "Your name in pig latin is: " << full;

    return 0;
}

void IgpayAtinlay(string& name)
{
    char letter = name[0];

    if (string("AEIOU").find(letter) != string::npos) //finds if string starts with vowel
    {
        name += "way";
    }
    else
    {
        if (name.length() > 1) //erases and appends string so first letter is now last + ay
        {
            name.erase(0, 1);
            name.append(&letter, 1);
        }
        name += "ay";
    }

}