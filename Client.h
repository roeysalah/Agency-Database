#ifndef ASSIGNMENT2_CLIENT_H
#define ASSIGNMENT2_CLIENT_H
#include "String.h"







class Client {
private:
    String ID;
    String Fullname;
    char gender;
    double age;
    int hobbies;
    char** listOfHobbies;

    //helper functions
    char** list_of_hobbies(char**list,int num);//make the list of the hobbbies
    char** recieveHobbies(int amount);//recieve the number of Hobbies
    int findHobby(char* hobby);

public:
    Client(String ID, String Fullname, char gender, double age, int hobbies, char** listOfHobbies); //constructor
    Client(const Client& cl);//copy constractor
    Client();// Default Constructor
    ~Client();//destructor

    // Operators overloading
    Client &operator=(const Client &cl); //The assignment operator
    bool operator==(const Client& cl) const;//Comparison with objects
    //getter functions
    String getFullname();
    String getId();
    char getGender();
    double getAge();
    int getHobbies();
    char** getListOfHobbies();
    // Input Operator Overloading
    friend istream& operator>>(istream& op,Client& str);

};


#endif //ASSIGNMENT2_CLIENT_H
