#ifndef ASSIGNMENT2_STRING_H
#define ASSIGNMENT2_STRING_H

/* Assignment: 2
Author: Roey Salah ID: 206115438
Author: Priel Hoffman ID: 318277308
*/

#include <iostream>
#include <string.h>
#include <vector>


using namespace std;

class String {
private:
    char *name;

    // Internal helpers
    char* remove_spaces(char *new_name);// remove spaces function
    int to_alloc(char* new_name); //allocating number of chars


public:
    String();         // Default Constructor
    String(char *new_name);   //constructor
    String(const String& str); //copy constructor
    ~String();  //destructor

    //methods
    String &operator=(const String & str); //The assignment operator
    //Comparison with objects
    bool operator==(const String & str);
    bool operator!=(const String& str);
    // Input/Output Operators Overloading
    friend ostream& operator<<(ostream& op, const String& str);
    friend istream& operator>>(istream& in, String& str);
    //getter function
    char* getRef();

};

#endif //ASSIGNMENT2_STRING_H
