

/* Assignment: 2
Author: Roey Salah ID: 206115438
Author: Priel Hoffman ID: 318277308
*/



#ifndef ASSIGNMENT2_MATCHMAKINGAGENCY_H
#define ASSIGNMENT2_MATCHMAKINGAGENCY_H

#include "Client.h"

class MatchMakingAgency {
private:
    int numOfClients;
    vector<Client>clients;
    void addClient();


public:
    MatchMakingAgency();// Default Constructor
    ~MatchMakingAgency();//destructor

    // methods
    void findAMatch(String id);
    // Getters
    Client* getClient(String id);
    vector<Client> getAlist();
    int getNumberOfClients();

    // Operator overloading
    MatchMakingAgency &operator=(const MatchMakingAgency &mma);//The assignment operator
    //Output Operators Overloading
    friend ostream& operator<<(ostream& op, const MatchMakingAgency& mma);
    MatchMakingAgency& operator+=(Client& cl);//add oprator for the clients
    MatchMakingAgency& operator-=(Client& cl);//sub oprator for the clients

};


#endif //ASSIGNMENT2_MATCHMAKINGAGENCY_H

