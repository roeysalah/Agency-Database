executable_2: main.o String.o Client.o MatchMakingAgency.o Menu.o
	g++ main.o String.o Client.o MatchMakingAgency.o Menu.o -o executable_2

main.o: main.cpp
	g++ -c main.cpp

String.o: String.cpp
	g++ -c String.cpp

Client.o: Client.cpp
	g++ -c Client.cpp

MatchMakingAgency.o: MatchMakingAgency.cpp
	g++ -c MatchMakingAgency.cpp

Menu.o: Menu.cpp
	g++ -c Menu.cpp

clean:
	rm *.o executable_2
