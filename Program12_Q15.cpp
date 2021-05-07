#include<iostream>
#include<fstream>//allows file access
#include<cctype>//allows isupper, islower, and isdigit functions
using namespace std;
//function prototypes
void error_message(ifstream&);
void find_values(ifstream&, int&, int&, int&);
void display_results(int, int, int);
//main function
int main()
{
    //int variables to hold totals, initialized to 0
    int upperCaseTotal = 0,
        lowerCaseTotal = 0,
        digitsTotal = 0;
    ifstream inFile;//create ifstream object to read data from a file
    inFile.open("text.txt");//open file
    //function calls
    error_message(inFile);
    find_values(inFile, upperCaseTotal, lowerCaseTotal, digitsTotal);
    display_results(upperCaseTotal, lowerCaseTotal, digitsTotal);
    inFile.close();//close file when done
    return 0;
}
//function to display error message if file won't open properly
void error_message(ifstream& file)
{
    if(file.fail())
    {
        cout << "Error opening file." << endl;
        exit(1);//exit program if file won't open
    }
}
//function to total up the values being searched for
void find_values(ifstream& file, int& upTotal, int&lowTotal, int&digTotal)
{
    char character;//char variable to read each character from file
    while(!file.eof())//repeat until end of file is reached
    {
        file >> character;//reading from file and storing in character variable
        //if uppercase character is found, add 1 to uppercase total
        if(isupper(character))
        {
            upTotal ++;
        }
        //if lowercase character is found, add to lowercase total
        if(islower(character))
        {
            lowTotal ++;
        }
        //if digit is found, add to digit total
        if(isdigit(character))
        {
            digTotal ++;
        }
    }   
}
//function to display how many of each thing has been found
void display_results(int upTotal, int lowTotal, int digTotal)
{
    cout << "The total number of uppercase letters in the file is " << upTotal << "." << endl;
    cout << "The total number of lowercase letters in the file is " << lowTotal << "." << endl;
    cout << "The total number of digits in the file is " << digTotal << "." << endl << endl;
}