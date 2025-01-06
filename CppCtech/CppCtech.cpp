#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <limits>
#include <string>
#include <cstdlib>
#include "Header.h"

//travel speed The user is assumed to be traveling at in Kilometers per hour
int TravelSpeed = 635266;

//Map storing the distance from Earth in Kilometers(as of Oct 2024)
std::map<std::string, double> planetDistances = {
{"Sun", 148840032},
{"Mercury", 201248137},
{"Venus", 182192482},
{"Earth", 0},
{"Mars", 159544408},
{"Jupiter", 649511459},
{"Saturn", 1340030466},
{"Uranus", 2790120262},
{"Neptune", 4348646927},
{"Pluto", 5258671930}
};



int main() {
	srand(time(NULL));
	int ran = rand() % 10;
	int tries = 200;
	int trie;
	int randig;
	int check = 69;
	int card1 = 0;
	int card2 = 0;
	int card3 = 0;//this is just poor management
	int card4 = 0;
	int dealer = 0;
	int dealer2 = 0;
	int dealer3 = 0;
	int dealer4 = 0;
	double n1;
	double n2;
	std::string word;//for palindrome and math quiz thing
	std::string HS;//hit or stand
	std::cout << "cheeeezee\n";
	system("cls");//shits and giggles why not type shit
	
	//random word gen 
	std::cout << "How many words would you like to generate?\n";
	std::cin >> tries;
	for (int i = tries; i > 0; i--) {
		std::cout << Common_words[rand() % Common_words.size()] << "\n";//allows for words to be added to the list withou need to change any of the code
	}//may add the same check as name gen to see if there are doubled words
	if (tries != 1) {
		std::cout << "Here are " << tries << " random words\n";
	}//using tries as its a varible i had already set
	else { std::cout << "Here is one random word\n"; }//fixes grammer when asked for one word
	tries = 200;//rest for later in code so i can safely use it without worry of what it may be set to
	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero



	//user ask math code
	std::cout << "Hello User\n";
	std::cout << "Please type your name.\n";

	std::cin >> word; //used for the users name

	std::cout << "Welcome " << word << ". It is a pleasure to meet you.\n";
	std::cout << "Let us begin with the challenge, shall we?\n";
	std::cout << "Would you like to proceed? (y/n)\n";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();//for some reason seems to fail at getting user input sometimes when using std::cin here
	std::getline(std::cin, HS);//this makes sure it will work

	// Check if the user wants to proceed
	if (First_letter(HS, "y") || First_letter(HS, "Y")) {
		std::cout << "Most excellent!\n";
	}
	else if (First_letter(HS, "n") || First_letter(HS, "N")) {
		std::cout << "That is sad to hear. Goodbye.";
		return 0; //ends program if the user does not want to continue
	}
	else {
		std::cout << "Answering basic questions is a difficult task for you apparently!\n";
		return 0; //exit the program if the user fails to answer with something beganing with a N or Y
	}
	std::cout << "You are brave " << word << ".\nLet us begin.\n";

	//vector to store math operators for generating and checking answer later
	std::vector<std::string> mathproblems = { "+", "-", "*" };

	//randomly select an operator to use for the problem
	int math = rand() % mathproblems.size();

	//generate two random numbers for the math problem
	int mathproblemNum1 = rand() % 11;
	int mathproblemNum2 = rand() % 11;


	//variable to store the user's answer for later reference
	double mathanswer{};

	
	std::cout << "Please answer the following math question, " << word << ":\n";
	
	std::cout << mathproblemNum1 << " " << mathproblems[math] << " " << mathproblemNum2 << " = ";

	//read the user's answer
	std::cin >> mathanswer;

	//check if the user's answer is correct
	bool isCorrect = false;
	if (mathproblems[math] == "+") {
		//check addition
		isCorrect = (mathanswer == mathproblemNum1 + mathproblemNum2);
		
	}
	else if (mathproblems[math] == "-") {
		//check subtraction
		isCorrect = (mathanswer == mathproblemNum1 - mathproblemNum2);
	}
	else if (mathproblems[math] == "*") {
		//check multiplication
		isCorrect = (mathanswer == mathproblemNum1 * mathproblemNum2);
	}

	//tell user if theyre dum or nor
	if (isCorrect) {
		//users not dum
		std::cout << "Correct! Well done, " << word << "!\n";
	}
	else {
		//user is dum :(
		std::cout << "Incorrect. The correct answer was ";
		//flex on user for being smarter
		if (mathproblems[math] == "+") {
			std::cout << mathproblemNum1 + mathproblemNum2;
		}
		else if (mathproblems[math] == "-") {
			std::cout << mathproblemNum1 - mathproblemNum2;
		}
		else if (mathproblems[math] == "*") {
			std::cout << mathproblemNum1 * mathproblemNum2;
		}
		std::cout << ".\n";
	}

	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero

	//interplanetary travel guide
	std::string name;//users name
	std::string again = "Eggs";//used to see if the user wants to run the code again
	bool againb = true;//same as the string again just as a bool value 

	//ask and store users name
	std::cout << "Welcome to the interplanetary travel guide! What's your name, User?\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	std::getline(std::cin, name);

	//loop for running more than once
	while (againb) {
		//display all the planets in the map 
		std::cout << "Glad to have you, " << name << "! Which planet will you be traveling to? (Type 'exit' to end the program)\n";
		std::cout << "- Sun\n- Mercury\n- Venus\n- Earth\n- Mars\n- Jupiter\n- Saturn\n- Uranus\n- Neptune\n- Pluto\n";

		std::string Planet;
		std::cin >> Planet;

		//check if user is a quitter
		if (Planet == "exit" || Planet == "Exit") {
			std::cout << "Sorry to hear that. Goodbye!\n";

		}
		//checks if user can spell and if they're dum spits out all the data if they aren't either
		auto check = planetDistances.find(Planet);
		if (check != planetDistances.end()) {
			double distance = planetDistances[Planet];
			std::cout << Planet << " is " << distance << " Kilometers away and will take about " << (distance / TravelSpeed) / 24 << " days to travel to at " << TravelSpeed << "km/h.\n";
			std::cout << "Would you like to travel to another planet? (yes/no)\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();//same thing as earlier sometimes skips asking when using just std::cin
			std::getline(std::cin, again);
			if (First_letter(again, "y") || First_letter(again, "Y")) { system("cls"); againb = true; }
			else { againb = false; std::cout << "Sorry to hear that Goodbye\n"; }
		}
		//runs if the user enters a planet that isn't included in the map
		else {
			system("cls");
			std::cout << "Error Planet not found press enter to restart" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//lets user just any button without any text or whatever
			std::cin.get();
			system("cls");
			againb = true;
		}
	}
	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero

	//Black jack
	dealer = rand() % 9 + 2;
	card1 = rand() % 9 + 2;
	card2 = rand() % 9 + 2;
	//not even going to try to comment it right now dont feel like it shoulda commented as i wrote it
	std::cout << dealer << "\n";
	if ((card1 + card2) > 21) {
		std::cout << card1 << "  " << card2 << "\n";
		std::cout << "Bust\n";
	}
	else {
		std::cout << card1 << "  " << card2 << "\nHit or Stand?\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
		std::getline(std::cin, HS);
		if (First_letter(HS, "h") || First_letter(HS, "H")) {
			card3 = rand() % 9 + 2;
			if ((card1 + card2 + card3) > 21) {
				std::cout << card1 << "  " << card2 << "  " << card3 << "\n";
				std::cout << "Bust\n";
			}
			else {
				std::cout << card1 << "  " << card2 << "  " << card3 << "\nHit or Stand?\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.clear();
				std::getline(std::cin, HS);
			}
			if (First_letter(HS, "h") || First_letter(HS, "H")) {
				card4 = rand() % 9 + 2;
				if ((card1 + card2 + card3 + card4) > 21) {
					std::cout << card1 << "  " << card2 << "  " << card3 << "  " << card4 << "\n";
					std::cout << "Bust\n";
				}
				else {
					std::cout << card1 << "  " << card2 << "  " << card3 << "  " << card4 << "\nHit or Stand?\n";
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin.clear();
					std::getline(std::cin, HS);
				}
			}
		}
		else if (is_same(HS, "Cheat")) {
			std::cout << "Enter your First card:";
			std::cin >> card1;
			std::cout << "\nEnter your Second card:";
			std::cin >> card2;
			std::cout << "\nEnter your Third card:";
			std::cin >> card3;
			std::cout << "\nEnter your Forth card:";
			std::cin >> card4;
			std::cout << "\n";
		}
		dealer2 = rand() % 9 + 2;
		if ((dealer + dealer2) < 17) {
			dealer3 = rand() % 9 + 2;
		}
		else {
			std::cout << dealer << "  " << dealer2 << "\n";
		}
		if ((dealer + dealer2 + dealer3) < 17) {
			dealer4 = rand() % 9 + 2;
		}
		else {
			std::cout << dealer << "  " << dealer2 << "  " << dealer3 << "\n";
		}
		if ((dealer + dealer2 + dealer3 + dealer4) > 17 && dealer4 != 0) {

			std::cout << dealer << "  " << dealer2 << "  " << dealer3 << "  " << dealer4 << "\n";

		}
		if ((card1 + card2 + card3 + card4) == 21) {
			std::cout << "Black Jack!\n";
			std::cout << card1 << "  " << card2 << "  " << card3 << "  " << card4 << "\n";
		}
		else {
			if ((card1 + card2 + card3 + card4) > (dealer + dealer2 + dealer3 + dealer4) && (card1 + card2 + card3 + card4) < 22) {
				std::cout << "You win!\n";
				std::cout << card1 << "  " << card2 << "  " << card3 << "  " << card4 << "\n";
			}
			else if ((card1 + card2 + card3 + card4) == (dealer + dealer2 + dealer3 + dealer4) && (card1 + card2 + card3 + card4) < 22) {
				std::cout << "its a tie! nobody wins\n";
				std::cout << card1 << "  " << card2 << "  " << card3 << "  " << card4 << "\n";
			}
			else {
				std::cout << "You lose\n";
				std::cout << card1 << "  " << card2 << "  " << card3 << "  " << card4 << "\n";
			}
		}
	}

	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen when user wants
	if (check == 2) { return 0; }//returns zero


	//miles to kilometers translator 
	double Miles = 0;//the distance the user inputs
	double Kilometers = 0;// the distance that will be returned
	std::string confirm;
	//loop asking the user to enter and confirm the distance until they say yes
	while (!First_letter(confirm, "y") && !First_letter(confirm, "Y") && confirm != "1") {
		std::cout << "Please enter your distance in Miles:";
		std::cin >> Miles;
		std::cout << "is " << Miles << " the correct distance?(yes/no)\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();//got upset with it skipping asking the user for input not even trying rlly
		std::getline(std::cin, confirm);
	}
	Kilometers = Miles * 1.609;//so close
	std::cout << Miles << " Miles converted to kilometers is " << Kilometers << " Kilometers\n";
	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero

	//user random number gen
	std::cout << "how many random numbers would you like:";
	std::cin >> tries;
	std::cout << "what is the maximum for the numbers:";
	std::cin >> trie;
	trie += 1;//the random wont spit out the max number so go one more
	while (tries > 0) {
		ran = rand() % trie;
		std::cout << ran << "\n";
		tries--;
	}
	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero


	//# of random names = # of tries set// I used the variable tries as i already had it for something later in the code 
	std::cout << "how many random names would you like?\n";
	std::cin >> tries;
	trie = tries;//I want to tell the user the number of names they asked for but the og variable gets set to zero during the loop from bad future proofing
	if (trie == 1) {
		std::cout << "here is one random name\n";//for grammer when asking for one
	}
	else {
		std::cout << "here are " << trie << " random names\n";
	}
	while (tries > 0) {
		//Firstnames and Lastnames are both declared in "testheaders.h"
		ran = rand() % Firstnames.size();
		std::cout << Firstnames[ran];
		ran = rand() % Lastnames.size();
		std::cout << Lastnames[ran] << "\n";
		tries--;
	}
	tries = 0;//double checking since i dont trust i wrote a simple loop right i guess
	//checking if any vectors have repeat names
	//just usefull for when i add more names
	for (double t1 = 0; t1 < Firstnames.size(); t1++) {

		for (int t2 = t1 + 1; t2 < Firstnames.size(); t2++) {
			if (is_same(Firstnames[t1], Firstnames[t2])) {
				std::cout << "Vector index " << t1 << " and " << t2 << " have the same value: "
					<< Firstnames[t1] << "\n";
			}
		}
	}
	for (int t1 = 0; t1 < Lastnames.size(); t1++) {

		for (int t2 = t1 + 1; t2 < Lastnames.size(); t2++) {
			if (is_same(Lastnames[t1], Lastnames[t2])) {
				std::cout << "Vector index " << t1 << " and " << t2 << " have the same value: "
					<< Lastnames[t1] << "\n";
			}
		}
	}
	if (trie == 1) {
		std::cout << "here is one random name\n";
	}
	else {
		std::cout << "here are " << trie << " random names\n";
	}
	//so I know the total number of names it picks from and i have the maturity of a 6yo while im at it
	if (trie == 69) {
		std::cout << Firstnames.size() << " " << Lastnames.size() << "\n";
	}
	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero


	//Powwaaa
	std::cout << "Please enter your base number: ";
	std::cin >> n1;
	std::cout << "What number would you like as the exponent: ";
	std::cin >> n2;
	std::cout << n1 << " raised to the power of " << n2 << " is " << power(n1, n2) << " \n";
	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero

	//this is stupid and unneeded
	/*
	//get smallest
	std::cout << "This code will tell you what number is smaller out of two\nPlease enter you first number: ";
	std::cin >> n1;
	std::cout << "What is your second number: ";
	std::cin >> n2;
	std::cout << get_smallest(n1, n2) << "\n";
	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero

	*/

	//also stupid and unneeded
	//is_palindrome test
	std::cout << "please enter a word: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	std::getline(std::cin, word);
	if (is_palindrome(word)) {
		std::cout << word << " is a palindrome (same forwards as backwards ex. racecar)\n \n";
	}
	else {
		std::cout << word << " is not a palindrome (same forwards as backwards ex. racecar)\n \n";
	}
	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero


	//average (inline header test)
	std::cout << "please enter the first number you would like to average: ";
	std::cin >> n1;
	std::cout << "\nplease enter the second number you would like to average: ";
	std::cin >> n2;
	std::cout << "the average of " << n1 << " and " << n2 << " is " << average(n1, n2) << "\n";
	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero


	//random single digit code
	std::cout << "Please enter your random single digit: ";
	//just for numbers use std::string for text
	ran = rand() % 10;
	std::cin >> randig;
	tries++;
	while (randig != ran && tries < 30) {
		std::cout << "The code wrong please try again:     (" << ran << ") \n";
		std::cin >> randig;
		tries++;
	}
	system("CLS");

	//space weight code
	double Weight;
	std::cout << "Please enter base earth weight\n";
	std::cin >> Weight;
	std::cout << "is " << Weight << " the right Weight? (y=1 n=2)\n";
	std::cin >> check;
	while (check != 1) {

		std::cout << "Please enter base earth weight\n";
		std::cin >> Weight;
		std::cout << "is " << Weight << " the right Weight? (y=1 n=2)\n";
		std::cin >> check;

	}
	std::cout << "what planet would you like to be translated to?\n 1 Mercury\n 2 Venus\n 3 Mars\n 4 Jupiter\n 5 Saturn\n 6 Uranus\n 7 Neptune\n";
	int planet;
	std::cin >> planet;
	std::cout << "you selected planet " << planet << " your weight would be\n";
	double Tweight;
	if (planet == 1) {

		Tweight = (Weight * 0.38);
		std::cout << Tweight << " on Mercury\n";
	}
	else if (planet == 2) {
		Tweight = (Weight * 0.91);
		std::cout << Tweight << " on Venus\n";
	}
	else if (planet == 3) {
		Tweight = (Weight * 0.38);
		std::cout << Tweight << " on Mars\n";
	}
	else if (planet == 4) {
		Tweight = (Weight * 2.34);
		std::cout << Tweight << " on Jupiter\n";
	}
	else if (planet == 5) {
		Tweight = (Weight * 1.06);
		std::cout << Tweight << " on Saturn\n";
	}
	else if (planet == 6) {
		Tweight = (Weight * 0.92);
		std::cout << Tweight << " on Uranus\n";
	}
	else if (planet == 7) {
		Tweight = (Weight * 1.19);
		std::cout << Tweight << " on Neptune\n";
	}
	else {
		std::cout << "\nError Planet not found\n Shutdown in 25 seconds";
		system("shutdown /s /t 25");//that 6 year old maturity showing again
	}

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
