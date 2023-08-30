#include <iostream>
#include <string>
#include <sstream>
#pragma warning( push )
#pragma warning( disable : 4101)
using namespace std;
std::ostringstream oss;
/*Hello there! THis is part 1 of the third task where i will be demonstrating an example of stacks. This is a battle log system in a RPG game (Role Playing Game), which involves a battle scene with your 4 party members who will fighting against monsters. Each party member has 4 options : FIGHT, USE MAGIC, USE ITEM, FLEE. You will be sending commands to each party member when it is your turn. Just to make things more simpler, i will be using terminology from a game called Final Fantasy 7 where there are 3 controllable characters, Cloud, Tifa and Aerith. This is a turn based combat system where you will give commands and at the end of your turn the players will obey them and attack. Then the enemy would have its turn and attack and so on until one of them dies. Have Fun!! */

class Node {
	public:
		Node *next;
		string data;

		Node(){
			data = "";
			next = NULL;

		}

		Node(string data) {
		this->data = data;
		this->next = NULL;
		}
};

class stack {
	Node *top;
	public:
		stack() {top = NULL;}

		int IsEmpty(){
			if (top == NULL){
				printf("The stack is empty\n");
				return 1;
			}
			printf("The stack is not empty\n");
			return 0;
		}

		void push(string data){
			Node *new_node = new Node(data);
			if (new_node == NULL) {cout << "Stack is full\n";}
			if (top == NULL){
				top = new_node;
				return;
			}
			Node *temp = top;
			top = new_node;
			top->next = temp;
			return;

		}

		void printstack() {
			Node *curr = top;

			if (top == NULL) {
				cout << "Stack is empty\n";
				return;
			}
			while (curr != NULL) {
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << "\n";
		}

		void pop(){
			if (top == NULL) {cout << "The stack is empty\n"; return;}
			Node *temp = top;
			top = top->next;
			delete temp;
			return;
		}
};

int main(void){
    stack log;
	int input;
    string players[3] = {"CLOUD", "TIFA", "AERITH"};
    int turn = 1;
    int player_turn = 0;
	cout << "An Enemy has appeared!! What will you do?? \n";
	while (input != 7){
        cout << players[player_turn] << "\n";
		cout << "Press 1 to Attack\n";
		cout << "Press 2 to Use Magic\n";
		cout << "Press 3 to Use Item \n";
		cout << "Press 4 to FLEE\n";
        cout << "Press 5 to view Battle Log\n";
        cout << "Press 6 to go back\n";
        cout << "Press 7 to exit the program\n";
		cin >> input;

		switch (input){
			case 1:
                log.push(players[player_turn] +" attacked\n");
                player_turn = (player_turn + 1)%3;
				break;
			case 2:
                int magic;
                cout << "Press 1 to Use Fire Blitz\n";
                cout << "Press 2 to Use Hydro Pump\n";
                cout << "Press 3 to Use Blizzard \n";
                cout << "Press 4 to Use Discharge\n";
                cout << "Press 5 to Use Recover\n";
                cout << "Press 6 to Use Paralysis\n";
                cout << "Press 7 to go back\n";
                cin >> magic;
                switch (magic){
                    case 1:
                        log.push(players[player_turn] +" used Fire Blitz\n");
                        player_turn = (player_turn + 1)%3;
                        break;
                    case 2:
                        log.push(players[player_turn] +" used Hydro Pump\n");
                        player_turn = (player_turn + 1)%3;
                        break;
                    case 3:
                        log.push(players[player_turn] +" used Blizzard\n");
                        player_turn = (player_turn + 1)%3;
                        break;
                    case 4:
                        log.push(players[player_turn] +" used Discharge\n");
                        player_turn = (player_turn + 1)%3;
                        break;
                    case 5:
                        log.push(players[player_turn] +" used Recover\n");
                        player_turn = (player_turn + 1)%3;
                        break;
                    case 6:
                        log.push(players[player_turn] +" used Paralysis\n");
                        player_turn = (player_turn + 1)%3;
                        break;
                    case 7:
                        break;
                }
                break;
			case 3:
				int item;
                cout << "Press 1 to Use Potion\n";
                cout << "Press 2 to Use Antidote\n";
                cout << "Press 3 to Use Grenade \n";
                cout << "Press 4 to Use Medicine\n";
                cout << "Press 5 to go back\n";
                cin >> item;
                switch (magic){
                    case 1:
                        log.push(players[player_turn] +" used Potion\n");
                        player_turn = (player_turn + 1)%3;
                        break;
                    case 2:
                        log.push(players[player_turn] +" used Antidote\n");
                        player_turn = (player_turn + 1)%3;
                        break;
                    case 3:
                        log.push(players[player_turn] +" used Grenade\n");
                        player_turn = (player_turn + 1)%3;
                        break;
                    case 4:
                        log.push(players[player_turn] +" used Medicine\n");
                        player_turn = (player_turn + 1)%3;
                        break;
                    case 5:
                        break;
                }
				break;
            case 4:
                log.push(players[player_turn] +" ran away\n");
                cout << "Battle is lost\n";
                player_turn = (player_turn + 1)%3;
                break;
            case 5:
                log.printstack();
                break;
            case 6:
                if (log.IsEmpty() == 1){
                    cout << "Nothing to go back to\n";
                    break;
                }
                log.pop();
                player_turn = (player_turn - 1)%3;
                break;
            case 7:
                return 0;

	}

    }
}

#pragma warning( pop )
