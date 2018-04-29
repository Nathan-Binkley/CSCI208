// menu example

#include "rps.h"
#include "card.h"
#include "deck.h"
#include "marble.h"
#include "monte.h"
#include "stack.h"
#include "node.h"
#include "list.h"
#include "Adventure.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;


// Function Prototypes
void showMenu();  // menue
void invalidInputReset();  // resets console after invalid input
// GAMES
void doWar(); // Declares war game
void doMonte(); // Declares Monte Game
void doBlackJack(); // Declares doBlackJack
void doRPS(); // Declares Rock-Paper-scissors
void doAdventure(); // Declares Adventure Game
void doCEight(); // Declares Crazy Eight
//void doBankruptsy(); // Declares Bankruptsy

//*****************************************************
// Start of main routine
//*****************************************************

int main()
{

int choice=0; // init to ensure while executes once

while (choice!=99){
	showMenu();
	cin >> choice;
		if (cin.fail())  // Input validation error
		{
			choice = 0; // reset choice to indicate invalid choice
			invalidInputReset(); // reset cin to valid state
		}
	switch (choice) {

		case 1 : // Play War
		  doWar();
		  break;
		case 2 : // Play Monte
			doMonte();
			break;
		case 3 : // Play Blackjack
		 	doBlackJack();
		 	break;
		case 4 : // Play rock paper scissors
			doRPS();
			break;
		case 5 : // Play Adventure
			doAdventure();
			break;
		case 6 : // Play Crazy Eights
			doCEight();
			break;
		case 99 :  // end game
			cout << "Thanks for playing " << endl << endl;
			break;
		default :  // not a valid choice
			cout << "Error: not a valid selection " << endl;
			break;

		} // end of switch statement

} // end of while loop

return 0;
}

//***************************************
// Function : doWar
// Input: N/A
// output: entire do war
// Description: Does War
//*****************************************
	void doWar()
	{
		//system("clear");
		int plays = 0;
		Card player1;
		Card player2;
		int player1score = 0, player2score = 0;


		Deck dek;


		cout << "War has been declared across the lands.\nYour ability as a general is terrible\nBut that doesn't stop you." << endl;

		do {
			dek.shuffle();
			cout << "Shuffle" << endl;
			player1 = dek.deal();
			dek.pop();
			player2 = dek.deal();
			dek.pop();

			if(player1.toString() > player2.toString())
			{
				cout << "Player 1 " << player1.toString() << endl;
				cout << "Player 2 " << player2.toString() << endl;
				cout << "Player 1 wins \n";
				player1score ++;
				cout << "Player 1: " << player1score << " Player 2: " << player2score << endl;
			}
			else if(player1.toString() < player2.toString())
			{
				cout << "Player 1 " << player1.toString() << endl;
				cout << "Player 2 " << player2.toString() << endl;
				cout << "Player 2 wins \n";
				player2score ++;
				cout << "Player 1: " << player1score << " Player 2: " << player2score << endl;
			}

			plays ++;
		} while(plays < 10);
		char x;
		if(player2score>player1score){
			cout << "Player2 wins the entire game" << endl << "Press any button to return to menu\n";
			cin >> x;
			cin.ignore();
		}
		if(player1score>player2score){
			cout << "Player 1 wins the entire game" << endl << "Press any button to return to menu\n";
			cin >> x;
			cin.ignore();
		}
	}

//***************************************
// Function : doMonte
// Input: none
// output: none
// Description: This function plays the monte game.
//*****************************************
void doMonte(){
	srand(time(0));

	Monte<Card> card;
	Monte<Marble> marble;

	int choice, actual, typePick = 0;
	do{
	cout << "Would you like to play with Marbles or Cards? (1 = Marbles 2 = Cards) ";
	cin >> typePick;
	}	while(typePick > 3 || typePick < 0);

	if(typePick == 1){
		Marble player("blue");
		Marble m;
		Marble j;
		marble.setOne(player);
		marble.setTwo(m);
		marble.setThree(j);
	}

	else if(typePick == 2){
		Card player(12,Hearts);
	 	Card m;
		Card j;
		card.setOne(player);
		card.setTwo(m);
		card.setThree(j);
	}
	else{
		cout << "Something went wrong, Try again";
	}
	if(typePick == 2){
		for(int i = 0; i < 3; i++)
		{
			cout << "Object " << i+1 << " is: " << card.pick(i).toString() << endl;
		}
		card.shuffle();
	}
	else if(typePick == 1)
	{
		for(int i = 0; i < 3; i++)
		{
			cout << "Object " << i+1 << " is: " << marble.pick(i).toString() << endl;
		}
		marble.shuffle();
	}

	do{
	cout << "The objects have been shuffled. Take your guess. 1, 2, or 3." << endl;
	cin >> choice;
	}while(choice > 3 && choice < 1);

	if(typePick == 1)
	{
		if(marble.pick(choice-1).toString() == "blue")
		{
			cout << "You got it right! Congratulations\n";
		}
		else
			cout << "You suck. Try again!\n";
	}
	if(typePick == 2)
	{
		if(card.pick(choice-1).toString() == "blue")
		{
			cout << "You got it right! Congratulations\n";
		}
		else
			cout << "You suck. Try again!\n";
	}
	if(typePick == 2){
		for(int i = 0; i < 3; i++)
		{
			cout << "Object " << i+1 << " is: " << card.pick(i).toString() << endl;
		}
	}
	else if(typePick == 1)
	{
		for(int i = 0; i < 3; i++)
		{
			cout << "Object " << i+1 << " is: " << marble.pick(i).toString() << endl;
		}
	}
	char x;
	cout << "Press any letter/number and press enter to go back to the menu\n";
	cin >> x;
	cin.ignore();

}
//***************************************
// Function : doBlackJack
// Input: none
// output: none
// Description: This function plays the blackjack game.
//*****************************************
void doBlackJack(){
	Deck gamedeck;
	//gamedeck.print();
	//cout << endl;

	//Shuffle 100 times
	for(int i = 0; i < 100; i ++)
		gamedeck.shuffle();

	cout << endl << endl;
	//gamedeck.print();

	char another = 'y';
	bool done = false, broke = false, dBroke = false;//check if user is done or if player or dealer busted
	int playerS, dealerS, playerS1, playerS2, dealerS1, dealerS2, tempRank = 0;
	Card player1, player2, dealer1, dealer2;

	//Pick Dealer Cards
	dealer1 = gamedeck.pop();
	dealer2 = gamedeck.pop();
	//Pick Player Cards
	player1 = gamedeck.pop();
	player2 = gamedeck.pop();

	//display cards
	Card tempCard;
	cout << "The dealer has " << dealer1.toString() << " and " << dealer2.toString() << endl;
	cout << "The player has " << player1.toString() << " and " << player2.toString() << endl;

	//get player initial score
	playerS1 = player1.getRank();
	playerS2 = player2.getRank();
	//get dealer initial score
	dealerS1 = dealer1.getRank();
	dealerS2 = dealer2.getRank();

	int ranks[] = {playerS1, playerS2, dealerS1, dealerS2};//initial card storage

	//calculate rank for everything above 10 (for face cards)
	for(int i = 0; i < 4; i++)
	{
		//cout << ranks[i] << endl //for debugging ranks over 10
		if(ranks[i] > 10)
				ranks[i] = 10;
	}
	/*
	for(int i = 0; i < 4; i++)
	{
		cout << ranks[i] << endl;
	}
*/ //for debugging rank over 10


	//add up initial scores from card 1 and card 2
	dealerS = ranks[2] + ranks[3];
	playerS = ranks[0] + ranks[1];


	//Begin initial setup for instant wins
	if(playerS == 21 && dealerS != 21){//check if player has blackjack but not dealer
		cout << "Player Wins!!!" << endl;
		done = true;
	}
	else if (playerS == 21 && dealerS == 21) //check if both have blackjack
	{
		cout << "It is a tie" << endl;
		done = true;
	}
	else if(dealerS == 21 && playerS !=21) //check if dealer has blackjack but not player
	{
		cout << "The dealer wins" << endl;
		done = true;
	} //basic commands to say if instant win //SHOULD NEVER HAPPEN BECAUSE NOTHING IS 11 OR HIGHER! -- per directions

		while(another == 'y' || another == 'Y')
		{
			do{
				cout << "The player has " << playerS << " and the dealer has " << dealerS << endl << "Would you like another card? (Y/N)" << endl;
				cin >> another;
			} while(another != 'y' && another != 'n' && another != 'Y' && another != 'N'	); // do while to ask the user if they want another card complete with validation of yes or no

			if(another == 'y' || another == 'Y')
			{ // input validation of whether or not the user wants another card.
				tempCard = gamedeck.pop(); //get top card to add to player's score
				cout << "The card is " << tempCard.toString() << endl;//display player card
				tempRank = tempCard.getRank(); //get new score of new card
				//cout << "Assigned tempRank" <<endl; //debugging
				if(tempRank > 10)
				{
					tempRank = 10;
				}
				//cout << "TempRank added" <<endl; //debugging
				playerS += tempRank;
				//cout << "Temprank added to playerS" <<endl; //debugging
				if(playerS > 21) // check if busted
				{
					//cout << "Player has more than 21" <<endl; //debugging
					done = true;
					//cout << "done set to true" << endl; //debugging
					broke = true;
					//cout << "Broke set to true" << endl; //debugging
					break;
				}
			}

			else if(another == 'n' || another == 'N')
				{
					//cout << "inside another ==n" << endl; //debugging
					done = true;
					//cout << "Done = true" <<endl; //debugging
					break;
				}

		}
		//cout << "Broken out of while another loop " <<endl;
		while(!dBroke){
			//cout << "Inside dBroke while" <<endl;
			if((dealerS < playerS && !dBroke) && playerS < 21)
			{
				//cout <<"inside dealerS drawing" << endl; //debugging
				tempCard = gamedeck.pop(); //get top card for dealer to draw
				cout << "The dealer drew " << tempCard.toString() << endl; //display dealer card
				tempRank += tempCard.getRank(); // add new card to dealer score
				if(tempRank > 10)
				{
					tempRank = 10;
				}
				dealerS += tempRank;
				cout << "The dealer has " << dealerS << endl;
				if(dealerS > 21)
				{
					dBroke = true;
					done = true;
					break;
				} // check if busted

			}//end if
		}//end dbroke while

		cout << "Player scored:" << playerS << " and the dealer scored:" << dealerS << endl;

		if((dealerS > playerS && dealerS < 22) || (broke == true && dealerS < 21)){
			cout << "Dealer Wins!" << endl; //declare winner
			done = true;
		}

		else if(playerS == 21 || (playerS < 22 && dealerS > 21) || (playerS > dealerS && playerS < 22) || (dBroke == true && playerS < 22)){
			cout << "Player Wins!" << endl;
			done = true;
		}
		else
		{
			cout << "Something went wrong. Contact system admin or someone who knows C++" << endl;
		}

		cout << "Type a single character and press enter to proceed" << endl; // allow the user to see the end prior to refreshing with the menu.
		cin >> another; // dummy stuff
		cin.ignore();
		gamedeck.~stack();//deconstruct the stack object gamedeck
		gamedeck.print(); //debugging to be sure it is empty
}

//***************************************
// Function : doRPS
// Input: none
// output: none
// Description: This function plays Rock-Paper-Scissors
//*****************************************
void doRPS()
{
	//Random
	srand(time(0));
	//Variables
	int AIc;
	int pChoice;
	int pScore = 0, cScore = 0;
	int plays = 0;
	int winner;
	char another;
	// AI choice initialization
	rock r1;
	paper p1;
	scissors s1;
	// Player choice initialization
	rock r2;
	paper p2;
	scissors s2;

	// Initialize base tools for player and AI
	tool* AI;
	tool* player;

	// AI gets assigned action inside do loop
	do{

		AIc = (rand() % 3) + 1;

		if(AIc == 1)
			AI = &r1;
		else if(AIc == 2)
			AI = &p1;
		else if(AIc == 3)
			AI = &s1;

			// Player chooses action
		do{
		cout << "What is your choice? (1 = Rock, 2 = Paper, 3 = Scissors)" << endl;
		cin >> pChoice;
	  }while(pChoice != 1 && pChoice != 2 && pChoice != 3);


		if(pChoice == 1)
			player = &r2;
		else if(pChoice == 2)
			player = &p2;
		else if(pChoice == 3)
			player = &s2;

		winner = player->fight(AI);

		if(winner == 1)
		{
			pScore += 1;
			cout << "The Player wins! Player: " << player->getType() << " Computer: " << AI->getType() << endl << endl;;
		}
		else if (winner == 2)
		{
			cScore += 1;
			cout << "The Computer wins! Player: " << player->getType() << " Computer: " << AI->getType() << endl << endl;
		}
		else
			cout << "It was a tie. Player: " << player->getType() << " Computer: " << AI->getType() << endl << endl;

		plays += 1;

	}while(plays < 3); // For 3 plays

	if(pScore > cScore) // for player win
		cout << "Player wins with " << pScore << " Computer had " << cScore << endl;
	if(cScore > pScore) // for computer win
		cout << "Computer wins with " << pScore << " Player had " << cScore << endl;
	if(cScore == pScore) // for unlikely tie
		cout << "That was sad. It was a tie at " << pScore << endl;

	cout << "Type a single character and press enter to proceed" << endl; // allow the user to see the end prior to refreshing with the menu.
	cin >> another; // dummy stuff
	cin.ignore();
}

//***************************************
// Function : doAdventure
// Input: none
// output: none
// Description: This function starts an adventure
//*****************************************
#include <unistd.h>
void doAdventure()
{

	// seed the time for random
	srand(time(0));

	// cout << "Adventure game start" << endl; // show start of game

	// Initializing all of the base variables for each enemy and player
	hero h1;
	dragon d1;
	troll t1;
	nightKing n1;
	newell g1;

	// set Interactable classes here
	player* player1 = &h1;
	player* dragon1 = &d1;
	player* troll1 = &t1;
	player* nightKing1 = &n1;
	player* gabe1 = & g1;


	char fight; // dummy variable for character inputs

	int pRoll, eRoll; // Initialize player and enemy die roll

	// Initialize Damage + Health Variables
	// Player
	int pDamage = player1->getStrength();
	int pHealth = player1->getHealth();
	// Troll
	int tDamage = troll1->getStrength();
	int tHealth = troll1->getHealth();
	//Dragon
	int dDamage = dragon1->getStrength();
	int dHealth = dragon1->getHealth();
	//Night King
	int nDamage = nightKing1->getStrength();
	int nHealth = nightKing1->getHealth();
	// Gabe Newell
	int gabeDamage = gabe1->getStrength();
	int gabeHealth = gabe1->getHealth();

	int results = 0; // dummy for getting the final result of the battle in the
	//											adult player class

	int net; // health - damage to be set after every battle

	// Initialize 2 dice
	dice die1;
	dice die2;

	// Initialize Life or Death
	bool aliveDragon = true;
	bool aliveTroll = true;
	bool aliveNK = true;
	bool alivePlayer = true;
	bool aliveNewell = false;

	// Random Spawns
	int newellSpawn = (rand() % 100) + 1;
	if(newellSpawn <=15)
		aliveNewell = true;

	// Inventory/shops -- to do

	// Start Game
do{ //(While atleast 1 enemy is alive and player is live)
	if(aliveDragon==true && alivePlayer == true)
	{
		// Prompt Dragon
		cout << "You come across a dragon" << endl << "Do you wish to fight? (Y/N)" << endl;

		do{
			cin >> fight;
		}while(fight != 'y' && fight != 'n' && fight != 'Y' && fight != 'N'); // Input Validation

		if(fight == 'y' || fight == 'Y') // Check if fight
		{
			// role die (1/100) -- ACCURACY
			eRoll = die1.roll();
			pRoll = die2.roll();

			results = player::battle(player1, dragon1, pRoll, eRoll); // determine results of battle

			if(results == 1) // player win
			{
				cout << "You have fought the Dragon and defeated it from the lands without a scratch. You have " << player1->getHealth() << " health." << endl;

				net = dHealth - pDamage; // Calculate new dragon health
				dragon1->setHealth(net);
			}
			else if(results == 2) // enemy win
			{
				cout << "You have been singed by the dragon's mighty fire. You lose " << dragon1->getStrength() << " health. You have " << player1->getHealth() << " health." << endl;

				net = pHealth - dDamage; // calculate new player health
				player1->setHealth(net);
			}
			else if(results == 3) // tie win
			{
				cout << "You fought the dragon and defeated it this time, but not without taking a few scorches from the king of the skies. You have " << player1->getHealth() << " health." << endl;

				net = dHealth - pDamage; // calculate new dragon health
				dragon1->setHealth(net);

				net = pHealth - dDamage; // Calculate new player health
				player1->setHealth(net);
			}
			else if (results == 4) // tie loss
			{
				cout << "Neither of you hit eachother. You are both run away in terror." << endl;
			}
			else // error
			{
				cout << "Something went wrong. Contact a programmer" << endl;
				return;
			}

			pHealth = player1->getHealth(); // get new health

			if(player1->getHealth() <= 0) // Check player health
			{
				cout<<"You have taken so much damage you have died" << endl;
				alivePlayer = false; // dead player
			}

			if(dragon1->getHealth() <= 0) // check dragon health
			{
				aliveDragon = false; // dead dragon

				cout << "The mighty dragon has fallen. You take it's head back with you to town to show the villagers they have no need to worry " << endl;
				cout << "Would you like to equip the head of the Dragon? (y/n)" << endl;

				cin >> fight; // dummy variable

				if(fight == 'y' || fight =='Y')
				{

					player1->setWeapon("Dragon Head");
					player1->setStrength(dragon1->getHeadDmg());
					cout << "You now have equipped the " << player1->getWeapon() << " that does " << player1->getStrength() << " damage." << endl;
				}
				else if(fight == 'n' || fight == 'N')
				{
					cout << "You have gained " << dragon1->getGold() << " gold for selling it's head. " << endl;
					player1->setGold(player1->getGold() + dragon1->getGold());
					cout << "You now have " << player1->getGold() << " gold from killing the dragon. " << endl;
				}
				else
				{
					cout << "That's an invalid action" << endl;
				}

			} // end dragon death

		}//END FIGHT

		else{
			cout << "You run away from the Dragon" << endl;
		}//RAN AWAY

		pHealth = player1->getHealth();
		dHealth = dragon1->getHealth(); // update variables for health

		//cout <<"Player" << endl << pHealth << endl << "Dragon" << endl << dHealth << endl << "Dragon Alive" << endl << aliveDragon <<endl; // debugging

		cout << endl << endl << endl; // make space
	}// END DRAGON

	this_thread::sleep_for(chrono::seconds(2)); // sleep for a few seconds

	if(aliveTroll==true && alivePlayer == true) // Troll Fight
	{
		// Prompt user input
		cout << "You come across a troll" << endl << "Do you wish to fight? (Y/N)" << endl;

		do{
			cin >> fight;
		}while(fight != 'y' && fight != 'n' && fight != 'Y' && fight != 'N'); // input validation for fight or no fight

		if(fight == 'y' || fight == 'Y') // yes fight
		{
			// role die for accuracy
			eRoll = die1.roll();
			pRoll = die2.roll();

			results = player::battle(player1, troll1, pRoll, eRoll); // determine who won the battle

			if(results == 1) // player win
			{
				cout << "You have fought the Troll and defeated it from the lands without a scratch. You have " << player1->getHealth() << " health." << endl;

				net = tHealth - pDamage; // Calculate new Troll health
				troll1->setHealth(net);
			}
			else if(results == 2) // enemy win
			{
				cout << "You have been bruised by the Trolls huge swings. You lose " << troll1->getStrength() << " health. " << endl;

				net = pHealth - tDamage; // calculate new player health
				player1->setHealth(net);
				cout << "You have " << player1->getHealth() << " health." << endl;

			}
			else if(results == 3) // both hit
			{
				cout << "You fought the Troll and defeated it this time, but not without taking a few beatings from the troll of the swamp." << endl;

				net = tHealth - pDamage; // calculate new Troll health
				troll1->setHealth(net);

				net = pHealth - tDamage; // Calculate new player health
				player1->setHealth(net);
				cout << " You have " << player1->getHealth() << " health." << endl;
			}
			else if (results == 4) // neither hit
			{
				cout << "Neither of you hit eachother. You are both run away in terror." << endl;
			}
			else // error
			{
				cout << "Something went wrong. Contact a programmer" << endl;
				return;
			}

			if(troll1->getHealth() <= 0) // CHECK TROLL HEALTH
			{
				aliveTroll = false; // dead troll

				cout << "The mighty troll has fallen. You take it's head back with you to town as proof " << endl; // equip something
				cout << "Would you like to equipt the head or the troll's " << troll1->getWeapon() << "?" << endl;

				cin >> fight; // dummy input

				if(fight == 'y' || fight =='Y')
				{
					cout << "Would you like to equip the head?" << endl;
					cin >> fight;
					if(fight == 'y' || fight =='Y')
					{
						player1->setWeapon("Troll Head"); // equip head
						player1->setStrength(troll1->getHeadDmg()); // change damage values
						cout << "You now have equipped the " << player1->getWeapon() << " that does " << player1->getStrength() << " damage." << endl;
					}
					else if(fight == 'n' || fight == 'N')
					{
						player1->setWeapon(troll1->getWeapon()); // equip troll weapon
						player1->setStrength(troll1->getStrength()); // change damage values
						cout << "You now have equipped the " << player1->getWeapon() << " that does " << player1->getStrength() << " damage." << endl;

						cout << "You have gained " << troll1->getGold() << " gold for selling it's head. " << endl; // get gold for troll
						player1->setGold(player1->getGold() + troll1->getGold());
						cout << "You now have " << player1->getGold() << " gold from killing the Troll. " << endl;
					}
					else
					{
						cout << "That's an invalid action" << endl;
					}
				}
			} // end troll death

			if(player1->getHealth() <= 0) // Check player health
			{
				cout<<"You have taken so much damage you have died" << endl;
				alivePlayer = false; // dead player
			}

		}// END TROLL FIGHT
		else{
			cout << "You run away from the troll" << endl;
		}
		pHealth = player1->getHealth();
		tHealth = troll1->getHealth();
		cout << endl << endl << endl; // make space
	} // END TROLL

	this_thread::sleep_for(chrono::seconds(2)); // sleep for a few seconds

	if(aliveNK == true && alivePlayer == true)
	{

		cout << "You come across a Night King" << endl << "Do you wish to fight? (Y/N)" << endl;

		do{
			cin >> fight;
		}while(fight != 'y' && fight != 'n' && fight != 'Y' && fight != 'N');

		if(fight == 'y' || fight == 'Y')
		{
			//ROLL DIE
			eRoll = die1.roll();
			pRoll = die2.roll();

			results = player::battle(player1, nightKing1, pRoll, eRoll);
			if(results == 1) // player win
			{
				cout << "You have fought the Night King and defeated it from the lands without a scratch" << endl;

				net = nHealth - pDamage; // Calculate new Night King health
				nightKing1->setHealth(net);
			}
			else if(results == 2) // nightKing win
			{
				cout << "You have been beaten and battered by the Night King's mighty swings. You lose " << nightKing1->getStrength() << " health. You have " << player1->getHealth() << " health." << endl;

				net = pHealth - nDamage; // calculate new player health
				player1->setHealth(net);
			}
			else if(results == 3) // both hit
			{
				cout << "You fought the Night King and defeated it this time, but not without taking a few beatings from the king of darkness. You take " << nightKing1->getStrength()<< " damage. You have " << player1->getHealth() << " health." << endl;

				net = nHealth - pDamage; // calculate new Night King health
				nightKing1->setHealth(net);

				net = pHealth - nDamage; // Calculate new player health
				player1->setHealth(net);
			}
			else if (results == 4) //neither hit
			{
				cout << "Neither of you hit eachother. You are both run away in terror." << endl;
			}
			else
			{
				cout << "Something went wrong. Contact a programmer" << endl;
				return;
			}

			if(nightKing1->getHealth() <= 0) // CHECK NIGHT KING HEALTH
			{
				aliveNK = false; // dead night king

				cout << "The mighty Night King has fallen. You take it's head back with you to town to sell" << endl << endl; // sell head or not
				cout << "Would you like to equipt the head or the Night King's " << nightKing1->getWeapon() << "?" << endl;

				cin >> fight;

				if(fight == 'y' || fight =='Y')
				{
					cout << "Would you like to equip the head?" << endl;
					cin >> fight;

					if(fight == 'y' || fight =='Y')
					{
						player1->setWeapon("Night King Head"); // equip night king head
						player1->setStrength(nightKing1->getHeadDmg());
						cout << "You now have equipped the " << player1->getWeapon() << " that does " << player1->getStrength() << " damage." << endl;
					}
					else if(fight == 'n' || fight == 'N')
					{
						player1->setWeapon(nightKing1->getWeapon()); // get night king weapon
						player1->setStrength(nightKing1->getStrength());
						cout << "You now have equipped the " << player1->getWeapon() << " that does " << player1->getStrength() << " damage." << endl;

						cout << "You have gained " << nightKing1->getGold() << " gold for selling it's head. " << endl; // get gold
						player1->setGold(player1->getGold() + nightKing1->getGold());
						cout << "You now have " << player1->getGold() << " gold from killing the Night King. " << endl;
					}
					else
					{
						cout << "That's an invalid action" << endl;
					}
				}
			} // end night king death

			if(player1->getHealth() <= 0) // Check player health
			{
				cout<<"You have taken so much damage you have died" << endl;
				alivePlayer = false; // dead player
			}

		}// END NIGHT KING FIGHT
		else{
			cout << "You run away from the Night King" << endl;
		}
		pHealth = player1->getHealth(); // reset variables for health
		nHealth = nightKing1->getHealth();
		cout << endl << endl; // make space
	} // END NIGHT KING

	this_thread::sleep_for(chrono::seconds(2));

	if(aliveNewell==true && alivePlayer == true)
	{
		// Prompt Newell
			cout << "You come across a legendary monster, Gabe Newell. You cannot run from this fight or you will die." << endl;
			this_thread::sleep_for(chrono::seconds(5));

			// role die
			eRoll = die1.roll();
			pRoll = die2.roll();

			results = player::battle(player1, gabe1, pRoll, eRoll); // determine results of fight

			if(results == 1) // player win
			{
				cout << "You have fought the Dragon and defeated it from the lands without a scratch" << endl;

				net = gabeHealth - pDamage; // Calculate new Night King health
				gabe1->setHealth(net);
			}
			else if(results == 2) // gabe win
			{
				cout << "You have been singed by the Gabe's lowsey prices. You lose " << gabe1->getStrength() << " health" << endl;

				net = pHealth - dDamage; // calculate new player health
				player1->setHealth(net);
			}
			else if(results == 3) // both hit
			{
				cout << "You fought the gabe and defeated it this time, but not without taking a few beatings from the king of the internet " << endl;

				net = gabeHealth - pDamage; // calculate new Night King health
				gabe1->setHealth(net);

				net = pHealth - gabeDamage; // Calculate new player health
				player1->setHealth(net);
			}
			else if (results == 4) // neither hit
			{
				cout << "Neither of you hit eachother. You are both run away in terror." << endl;
			}
			else
			{
				cout << "Something went wrong. Contact a programmer" << endl;
				return;
			}
			pHealth = player1->getHealth();

			if(player1->getHealth() <= 0) // Check player health
			{
				cout<<"You have taken so much damage you have died" << endl;
				alivePlayer = false; // dead player
			}

			if(gabe1->getHealth() <= 0) // check newell health
			{
				aliveNewell = false; // dead newell

				cout << "The mighty Gabe has fallen. You take it's head back with you to town to show the villagers they have no need to worry " << endl;
				cout << "Would you like to equipt the head or Gabe's " << gabe1->getWeapon() << "?" << endl;

				cin >> fight; // dummy variable

				if(fight == 'y' || fight =='Y')
				{
					cout << "Would you like to equip the head?" << endl;
					cin >> fight; // dummy variable

					if(fight == 'y' || fight =='Y')
					{
						player1->setWeapon("Gabe Newell's Head"); // exchange weapons with head

						player1->setStrength(gabe1->getHeadDmg()); // set new strength

						cout << "You now have equipped the " << player1->getWeapon() << " that does " << player1->getStrength() << " damage." << endl;
					}
					else if(fight == 'n' || fight == 'N')
					{
						player1->setWeapon(gabe1->getWeapon()); // exchange weapons

						player1->setStrength(gabe1->getStrength()); // set new strength

						cout << "You now have equipped the " << player1->getWeapon() << " that does " << player1->getStrength() << " damage." << endl;

						cout << "You have gained " << gabe1->getGold() << " gold for selling it's head. " << endl; // add gold

						player1->setGold(player1->getGold() + gabe1->getGold());

						cout << "You now have " << player1->getGold() << " gold from killing Mr. Newell. " << endl;
					}
					else
					{
						cout << "That's an invalid action" << endl;
					}
				}
			}

		pHealth = player1->getHealth();
		gabeHealth = gabe1->getHealth(); // reset variables for health
		//cout <<"Player" << endl << pHealth << endl << "Dragon" << endl << dHealth << endl << "Dragon Alive" << endl << aliveDragon <<endl; // debugging
		cout << endl << endl << endl; // make space
	}// END gNewell


}while((aliveDragon || aliveTroll || aliveNK) && alivePlayer); // CHECK IF PLAYER AND OTHERS ARE ALIVE

if(alivePlayer == false) // check for dead player
{
	cout<<"The village mourns your death, just as they did in life" << endl;
}
else if(!(aliveDragon && aliveTroll && aliveNK) && alivePlayer) // check if nothing but player is alive
{
	cout << "You killed all of the village threats! Congratulations! You're the new ruler of the lands" << endl;
	cout << "You ended your adventure with: " << player1->getWeapon() << endl << " " << player1->getStrength() << " damage " << endl << player1->getGold() << " gold" << endl;
}
else{ // SHOULD NEVER HAPPEN
	cout << "Something went wrong " << endl;
	cout << "Dragon " << aliveDragon << " Troll " << aliveTroll << " Night King " << aliveNK << endl;
}
cout << "Press any key + enter to return to the menu, or CTRL + C to leave everything behind " << endl;
cin >> fight;
cin.ignore();



/* TESTING VARIABLES AND SUCH
	//Rolling die
	pRoll = die1.roll();
	cout << pRoll << endl;
	eRoll = die2.roll();
	cout << eRoll << endl;

	// Battle Cry
	h1.battleCry();
	d1.battleCry();
	t1.battleCry();
	n1.battleCry();

	player1->battleCry();
	dragon1->battleCry();
	troll1->battleCry();
	nightKing1->battleCry();

	// setters and getters
		cout << h1.getWeapon();
		cout << d1.getWeapon();
		cout << t1.getWeapon();
		cout << n1.getWeapon();

		cout << player1->getWeapon();
		cout << dragon1->getWeapon();
		cout << troll1->getWeapon();
		cout << nightKing1->getWeapon();

		cout << h1.getStrength();
		cout << d1.getStrength();
		cout << t1.getStrength();
		cout << 	cout << n1.getStrength();

		cout << player1->getStrength();
		cout << dragon1->getStrength();
		cout << troll1->getStrength();
		cout << nightKing1->getStrength();

	cout << h1.sayName();
	cout << 	player1->sayName();

	cout << h1.motto();

		cout << h1.getHealth();
		cout << d1.getHealth();
		cout << t1.getHealth();
		cout << n1.getHealth();

		cout << player1->getHealth();
		cout << dragon1->getHealth();
		cout << troll1->getHealth();
		cout << nightKing1->getHealth();

	h1.setWeapon("Jaguar");
	d1.setWeapon("Jaguar");
	t1.setWeapon("Jaguar");
	n1.setWeapon("Jaguar");

	player1->setWeapon("Jaguar");
	dragon1->setWeapon("Jaguar");
	troll1->setWeapon("Jaguar");
	nightKing1->setWeapon("Jaguar");

		cout << h1.getWeapon();
		cout << d1.getWeapon();
		cout << t1.getWeapon();
		cout << n1.getWeapon();

		cout << player1->getWeapon();
		cout << dragon1->getWeapon();
		cout << troll1->getWeapon();
		cout << nightKing1->getWeapon();

	h1.setStrength(15);
	d1.setStrength(15);
	t1.setStrength(15);
	n1.setStrength(15);

	player1->setStrength(15);
	dragon1->setStrength(15);
	troll1->setStrength(15);
	nightKing1->setStrength(15);

		cout << h1.getStrength();
		cout << d1.getStrength();
		cout << t1.getStrength();
		cout << n1.getStrength();

		cout << player1->getStrength();
		cout << dragon1->getStrength();
		cout << troll1->getStrength();
		cout << nightKing1->getStrength();


*/
}

void doCEight()
{
	int i = 1; // debugging

  cout << "Started Crazy Eights" << endl;

	list<Card> playerHand;
	list<Card> compHand;
	list<Card> discard;

	Deck deck;

	for(int i = 0; i < 100; i ++)
		deck.shuffle();


	while(i < 8 && !deck.isEmpty())
	{
		//cout << "Beginning of pushing to hands" << endl; // debugging
		if(playerHand.size() <= 8)
			playerHand.push_front(deck.pop());
		//cout << "Pushed " << i + 1 << " cards to player" << endl; // debugging
		if(compHand.size() <= 8)
			compHand.push_front(deck.pop());
		//cout << "Pushed " << i + 1 << " cards to hands" << endl; // debugging
		i++;
	}
	// cout << "Put everything in hands" << endl; // debugging
	cout << "Player's hand has " << playerHand.size() << " cards" << endl << endl;
	cout << "Computer's hand has " << compHand.size() << " cards" << endl << endl;
	cout << "Player's hand: " << endl;
	playerHand.printList();
	cout << endl;
	cout << "Computer's hand: " << endl;
	compHand.printList();







}
//***************************************
// Function : showMenu
// Input: none
// output: none
// Description: This function presents the menu
//    options on the screen.
//*****************************************
void showMenu()
{
  //system("clear");  // clear the screen /////////////////////////////////////////////
   cout<<endl << endl << endl << endl;
	 cout<< "                         " << endl;
	 cout<< "           _~            " << endl;
	 cout<< "        _~)_)_~          " << endl;
	 cout<< "       )_))_))_)         " << endl;
	 cout<< "       _!__!__!_         " << endl;
	 cout<< "       \\------t/         " << endl;
	 cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	 cout << "****  GAME MENU   ******" << endl << endl;
	 cout<<" Please type a choice:"<<endl;
     cout<<"  1  First game: Game of War"<<endl;
		 cout<<"  2  Second game: Game of Monte"<<endl;
		 cout<<"  3  Third Game: Blackjack"<<endl;
		 cout<<"  4  Fourth Game: Rock-Paper-Scissors"<<endl;
		 cout<<"  5  Fifth Game: Adventure"<<endl;
		 cout<<"  6  Sixth Game: Hand dealing linked list"<<endl;
     cout<<" 99  Exit the program"<<endl;
}

//***************************************
// Function : invalidInputReset
// Input: none
// output: none
// Description: This function resets the cin stream object
//      after in invalid input is detected. It clears the error flags
//      and reads any other 'garbage' on the input line past the last '\n'
//*****************************************
void invalidInputReset()
{
		cin.clear(); // clear the error flags
		cin.ignore(); // skip anything else on the line
}

ostream& operator<<(ostream& os, const Card& card)
{
	os << card.myRank << " of " << card.suitString[card.mySuit];

	return os;
}
