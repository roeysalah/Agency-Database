


#include "Client.h"



//getter function
String Client:: getFullname(){
    return this->Fullname;
}
String Client::getId(){
    return this->ID;
}

char Client::getGender(){
    return this->gender;
}

double Client::getAge(){
    return this->age;
}

int Client::getHobbies()
{
    return this->hobbies;
}

char** Client::getListOfHobbies()
{
    return this->listOfHobbies;
}

//input oprartor for the menu
istream& operator>>(istream& in,Client& newClient){
    //The cin.clear() clears the error flag
    cout << "Please Enter an id: ";
    in >> newClient.ID;
    in.clear();
    cout<<"Please enter a full name: ";
    in >> newClient.Fullname;
    in.clear();
    cout<<"Please enter 'f' for female or 'm' for male: ";
    in >> newClient.gender;
    in.clear();
    do{
        cout << "Please enter an age (the minimum age is 18): ";
        in >> newClient.age;
        in.clear();
    }while (newClient.age<18);
    cout << "Please enter The number of hobbies: ";
    in >> newClient.hobbies;
    in.clear();
    newClient.listOfHobbies = newClient.recieveHobbies(newClient.hobbies);
    return in;
}
//this function recieve the hobbies from the user
char** Client::recieveHobbies(int amount)
{
    String temp;
    char** hobbiesLst;
    //dynamic allocation for the list of hobbies;
    hobbiesLst = new char* [amount];
    for (int i = 0; i < amount; i++)
    {
        cout << "Hobby - " << i << ": ";
        cin >> temp;
        //dynamic allocation for the hobbies
        hobbiesLst[i] = new char[strlen(temp.getRef()) + 1];
        strcpy(hobbiesLst[i], temp.getRef());//make a copy of the hobby by get the refrence
    }

    return hobbiesLst;
}
//check if the the hobby already exist in the list
int Client::findHobby(char* hobby)
{
    int index = -1;
    bool found = false;

    for (int i = 0; i < this->hobbies && !found; i++) {
        if (!strcmp(hobby, this->listOfHobbies[i])) { //compare between two hobbies
            index = i;
            found = true;
        }
    }

    return index;
}

// this function make the list of the hobbbies of the client
char**Client::list_of_hobbies(char** list, int num){
    // dynamic allocation for the hobbies (copy)
    char** list_of_hobbies = new char* [num];
    for (int i = 0; i < num; i++) {
        list_of_hobbies[i] = new char[strlen(list[i]) + 1];
        strcpy(list_of_hobbies[i], list[i]);
    }
    return list_of_hobbies;
}
// Default Constructor
Client::Client(){
    this->gender = '\0';
    this->age = 0;
    this->hobbies = 0;
    this->listOfHobbies = nullptr;
}
// Constructor
Client::Client(String ID, String Fullname, char gender, double age, int hobbies, char** listOfHobbies) {

    this->ID=ID;
    this->Fullname=Fullname;
    this->gender=gender;
    this->age=age;
    this->hobbies=hobbies;
    this->listOfHobbies = listOfHobbies;
}
//copy Constructor
Client::Client(const Client& cl)
{
    //for not making a double of code
    *this = cl;
}
//The assignment operator for the objects
Client &Client::operator=(const Client& cl) {
    if (this != &cl) {//check if the client is not the same
        this->ID = cl.ID;
        this->Fullname = cl.Fullname;
        this->gender = cl.gender;
        this->age = cl.age;
        this->hobbies = cl.hobbies;
        this->listOfHobbies = list_of_hobbies(cl.listOfHobbies, hobbies);
    }
    return *this;
}

//Comparison by 3 attributes:Gender,Age,and one hobby or more the same
bool Client::operator==(const Client& cl) const
{
    bool res = true;
    //mutual for the check of the hobbies
    bool mutual = false;

    res &= this->gender != cl.gender; //check if the gender the same or not
    res &= (this->age - cl.age) * (this->age - cl.age) <= 25; // Age difference less than 5

    for (int i = 0; res && i < this->hobbies && !mutual; i++)
    {
        for (int j = 0; j < cl.hobbies && !mutual; j++)
        {
            //check if there is one hobby the same between the clients
            if (!strcmp(this->listOfHobbies[i], cl.listOfHobbies[j]))
            {
                mutual = true; //the objects have at least one hobby the same
            }
        }
    }
    res &= mutual;

    return res;
}

//destructor
Client::~Client(){
    //removing all the dynamic allocations
    for (int i = 0; i < this->hobbies; i++) {
        delete[]this->listOfHobbies[i];
    }
    delete[]this->listOfHobbies;
}