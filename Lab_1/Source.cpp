#include <iostream>
#include <ctime>
using namespace std;

int main() {

	srand(time(NULL));
	int rand_int, pot_user, pot_comp, player = 2;
	char round, quit;
	bool roll_again;


	do{
		
		cout << "Welcome to lucky die scrambler. The first one to 50 wins." << endl;
		cout << endl;
		int user_game_pot = 0;
		int comp_game_pot = 0;

		do {

			int player_turn;
			player_turn = player % 2;
			if (player_turn == 0) {
				cout << "It is your turn (press enter to start)." << endl;
				cin.get();
			}
			else {
				cin.get();
				cout << "It is the computers turn" << endl;
				cin.get();
			}
			
			int round_pot = 0;

			if (player_turn == 0) {
				do {
					cout << endl;
					int rand_int;
					
					rand_int = rand() % 6 + 1;
					cout << "You rolled a " << rand_int ;
					if (rand_int == 1) {
						round_pot = 0;
						cout << "      pot total is " << round_pot << endl;
						break;
					}
					else {
	
						round_pot += rand_int;
						cout << "      pot total is " << round_pot << endl;
						if ((user_game_pot + round_pot) >= 50) {
							break;
						}
					
					}

					cout << endl;

					cout << "(R)oll again, or (H)old? >> ";
					cin >> round;
					round = toupper(round);

					while (!(round == 'R' || round == 'H')) {
						cout << "Incorrect input. Please enter 'R' or 'H' >> ";
						cin >> round;
						round = toupper(round);
					}

					

				} while (round == 'R');

				user_game_pot += round_pot;
				cout << endl;
				cout << "   Score   ";
				cout << "You : " << user_game_pot;
				cout << "   Computer : " << comp_game_pot << endl;
				cin.get();
			}
			else {
				int round_pot = 0;
				while (round_pot < 20) {
					
					rand_int = rand() % 6 + 1;
					if (rand_int == 1) {
						round_pot = 0;
						cout << "Computer rolled " << rand_int << "      pot total is " << round_pot << endl ;
						cin.get();
						break;
					}
					else {
						round_pot += rand_int;
						cout << "Computer rolled " << rand_int << "      pot total is " << round_pot ;
						cin.get();
						if ((comp_game_pot + round_pot) >= 50) {
							break;
						}
					}
				}
				comp_game_pot += round_pot;
				cout << endl;
				cout << "   Score   ";
				cout << "You : " << user_game_pot;
				cout << "   Computer : " << comp_game_pot << endl;
				cin.get();
			}
			
			
			player += 1;



		} while (user_game_pot < 50 && comp_game_pot < 50);

		if (player % 2 == 1) {
			cout << endl;
			cout << "Congrats you won!!!" << endl;
			cout << endl;
		}
		else {

			cout << "Sorry the computer got you!" << endl;
			cout << endl;
		}
 

		cout << "Play again, (Y)es or (N)o? >> ";
		cin >> quit;
		quit = toupper(quit);

		while ( !(quit == 'Y' || quit == 'N')) {
			cout << "Incorrect input. Please enter 'Y' or 'N' " ;
			cin >> quit;
			quit = toupper(quit);
		}
		cout << endl;
	} while (quit == 'Y');

	cout << "Thanks for playing!";

	int num;
	cin >> num;

	return 0;
}