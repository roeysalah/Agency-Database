

/* Assignment: 2
Author: Roey Salah ID: 206115438
Author: Priel Hoffman ID: 318277308
*/

#include "Menu.h"
Menu::Menu(){

}

void Menu::mainMenu() {
    int answer;
    do {
        cout << "\nPlease choose one of the following options:\n "
                "==========================================================\n"
                "1) Add a new client to the database.\n"
                "2) Remove an existing client from the database.\n"
                "3) Print all clients.\n"
                "4) Print all matches for a client.\n"
                "5) Quit the program.\n"
                "==========================================================" << endl;
        cin >> answer;
        switch (answer) {
            case 1:
            {
                //add new client to the database
                Client newClient;
                cin >> newClient;
                dataBase+=newClient;
                break;
            }
            case 2:
            {
                String id;
                Client* remove;
                cout<<"Please Enter an id: ";
                cin>>id;
                remove = dataBase.getClient(id);
                if(dataBase.getClient(id)== nullptr){
                    cout<<"Client doesnt exist in the database!";
                }
                else {
                    dataBase -= *remove;
                }
                break;
            }
            case 3:
                cout << dataBase;
                break;
            case 4:
            {
                String id;
                cout<<"Please Enter an id: ";
                cin>>id;
                dataBase.findAMatch(id);
                break;
            }
            case 5:
                cout << "Goodbye" << endl;
                exit(answer = 5);
            default:
                cout << "Bad choice! Please try again." << endl;
        }
    }while (answer != 5);
}