
# Agency-Database 

A C++ program that simulates an agency database. The system allows you to manage client profiles, perform matchmaking based on preferences, and interact through a user-friendly menu. This project demonstrates object-oriented programming, dynamic memory management, and modular design.


## Features

- Add, remove, and query clients in the database.  
- Suggest matches based on gender, age range, and shared hobbies.  
- Dynamic memory management for strings and client data.  
- Clean, modular OOP design using multiple classes.  
- Interactive menu for easy user operation.  

---

## System Overview

### Class Diagram

```
+------------------+        +-------------------+
|     String       |        |       Client      |
+------------------+        +-------------------+
| char* value      |<----+  | String ID         |
| Constructor      |     |  | String Name       |
| Copy Constructor |     |  | char Gender       |
| Destructor       |     |  | double Age        |
| = operator       |     |  | int NumHobbies    |
| == operator      |     +--| char* Hobbies     |
+------------------+        +-------------------+
                                |
                                v
                     +------------------------+
                     |   MatchMakingAgency    |
                     +------------------------+
                     | int NumClients         |
                     | vector<Client> Clients |
                     | += operator (Add)      |
                     | -= operator (Remove)   |
                     | printMatches()         |
                     +------------------------+
                                |
                                v
                          +-----------+
                          |   Menu    |
                          +-----------+
                          | display() |
                          +-----------+
```

---

## Getting Started

### Prerequisites

- C++ compiler (C++11 or higher)  
- Terminal / command-line access  

### Installation

1. Clone the repository:

```bash
git clone https://github.com/yourusername/Matchmaking-Office-System.git
```

2. Navigate to the project folder:

```bash
cd Matchmaking-Office-System
```

3. Compile the program:

```bash
g++ -o matchmaking_system main.cpp
```

---

## Usage

Run the program:

```bash
./matchmaking_system
```

### Menu Options

- **Add a New Client:** Input client details to add them to the database.  
- **Remove an Existing Client:** Remove a client using their ID.  
- **Print All Clients:** Display all clients and their details.  
- **Print All Matches for a Client:** Find suitable matches for a selected client.  
- **Quit:** Exit the program.  

---

## Example Run

```
Welcome to the Matchmaking Office!
1. Add Client
2. Remove Client
3. Print All Clients
4. Print Matches for Client
5. Quit
Enter option: 1

Enter ID: 123
Enter Name: Alice Smith
Enter Gender (M/F): F
Enter Age: 25
Enter Number of Hobbies: 3
Enter Hobbies: Reading, Hiking, Painting

Client added successfully!
```

---

## Dependencies

- Standard C++ libraries: `<vector>`, `<iostream>`, `<cstring>`  
- Works on any C++11 compatible compiler.  

---

## Notes

- Client age must be at least 18.  
- Hobbies are stored dynamically, ensuring deep copies when clients are copied or removed.  
- Comparison for matching considers gender, age difference, and common hobbies.  

---




