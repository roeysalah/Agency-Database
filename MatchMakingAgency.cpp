




/* Assignment: 2
Author: Roey Salah ID: 206115438
Author: Priel Hoffman ID: 318277308
*/




#include "MatchMakingAgency.h"

//getter functions
vector<Client> MatchMakingAgency:: getAlist(){
    return this->clients;
}

int MatchMakingAgency :: getNumberOfClients(){
    return this ->numOfClients;
}




//this function check  if the id the same between two clients (use for removing client)
Client* MatchMakingAgency::getClient(String id)
{
    Client* cl = nullptr;
    bool found = false;

    for (int i = 0; i < this->clients.size() && !found; i++)
    {
        if (clients[i].getId() == id) //check  if the clients have the same id
        {
            cl = &clients[i];
            found = true;
        }
    };

    return cl;
}
// Default Constructor
MatchMakingAgency::MatchMakingAgency() {
    this->numOfClients=0;
    clients.clear();
}
//The assignment operator for the vector of the clients
MatchMakingAgency &MatchMakingAgency::operator=(const MatchMakingAgency& mma){
    for (Client client : mma.clients){
        *this += client; //adding the client to the new vector by deep  copy
    }
    this->numOfClients = mma.numOfClients;
    return *this;
}

//this function find a match for the client
void MatchMakingAgency::findAMatch(String id){
    Client* cl;
    cl = getClient(id);//get the id of the client
    cout << "All matching clients for " << cl->getFullname() << ":" << cl->getId() << endl;
    for (Client client : this->clients) {
        /*check if the client equal to another by the comprison function of the clients
         and check if the client is not the same */
        if (client.getId() != cl->getId() && client == *cl) {
            cout << client.getFullname() << ":" << client.getId() << endl;
        }
    }
}


//destructor
MatchMakingAgency::~MatchMakingAgency() {
    clients.clear();//clear the vector
}

// this  operator add a client to the vector
MatchMakingAgency &MatchMakingAgency::operator+=(Client& cl){

    // If client not in clients, method getClient returns nullptr
    if(getClient(cl.getId()) == nullptr){
        clients.push_back(cl);//add the client with dynamic allocating
        numOfClients++;//adding 1 for  the number of clients in the vector
    }

    return *this;
}

// this operator sub a client from the vector
MatchMakingAgency &MatchMakingAgency:: operator-=(Client& cl){

    bool found = false;

    for (int i = 0; i < clients.size() && !found; i++) {
        //check for id of the client we want to remove
        if (cl.getId() == clients[i].getId()) {
            //remove the client by his index
            clients.erase(clients.begin() + i);
            numOfClients--;//sub 1 from  the number of clients in the vector
            found = true;
        }
    }

    return *this;
}
// this operator prints each Client with all his details (print the datebase of the vector)
ostream& operator<<(ostream& op, const MatchMakingAgency& mma)
{

    for (Client client : mma.clients) {

        op << "Name: " << client.getFullname() << endl;
        op << "ID: " << client.getId() << endl;

        //check if  the gender is Female or Male
        if (client.getGender() == 'f')
            op << "Gender: Female" << endl;
        else
            op << "Gender: Male" << endl;

        op << "Age: " << client.getAge() << endl << "list of hobbies: " ;
        for (int i = 0; i < client.getHobbies(); i++)
        {
            //prints  the hobbies
            op << client.getListOfHobbies()[i];
            if (i + 1 != client.getHobbies()) {
                op << ", ";
            }
        }

        cout << endl << "*************************************************" << endl;
    }

    return op;
}
