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
	int card3 = 0;
	int card4 = 0;
	int dealer = 0;
	int dealer2 = 0;
	int dealer3 = 0;
	int dealer4 = 0;
	double n1;
	double n2;
	std::string word;//for palindrome and math asking
	std::string HS;//hit or stand
	std::cout << "cheeeezee\n";
	system("cls");

	//random word gen 
	std::cout << "How many words would you like to generate?\n";
	std::cin >> tries;
	for (int i = tries; i > 0; i--) {
		std::cout << Common_words[rand() % Common_words.size()] << "\n";
	}
	if (tries != 1) {
		std::cout << "Here are " << tries << " random words\n";
	}
	else { std::cout << "Here is one random word\n"; }
	tries = 200;
	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero



	//user ask math code
	std::cout << "Hello User\n";
	std::cout << "Please type your name.\n";

	std::cin >> word; // Read the user's name

	std::cout << "Welcome " << word << ". It is a pleasure to meet you.\n";
	std::cout << "Let us begin with the challenge, shall we?\n";
	std::cout << "Would you like to proceed? (y/n)\n";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	std::getline(std::cin, HS); // Read the user's response

	// Check if the user wants to proceed
	if (First_letter(HS, "y") || First_letter(HS, "Y")) {
		std::cout << "Most excellent!\n";
	}
	else if (First_letter(HS, "n") || First_letter(HS, "N")) {
		std::cout << "That is sad to hear. Goodbye.";
		return 0; // Exit the program
	}
	else {
		std::cout << "Answering basic questions is a difficult task for you apparently!\n";
		return 0; // Exit the program
	}
	std::cout << "You are brave " << word << ".\nLet us begin.\n";

	// Vector to store math operators as strings
	std::vector<std::string> mathproblems = { "+", "-", "*" };

	// Randomly select an operator from the vector
	int math = rand() % mathproblems.size();

	// Generate two random numbers for the math problem
	int mathproblemNum1 = rand() % 11;
	int mathproblemNum2 = rand() % 11;


	// Variable to store the user's answer
	double mathanswer = 0;

	// Display the math problem to the user
	std::cout << "Please answer the following math question, " << word << ":\n";
	// Print the math question, adding spaces around the operator for readability
	std::cout << mathproblemNum1 << " " << mathproblems[math] << " " << mathproblemNum2 << " = ";



	// Read the user's answer
	std::cin >> mathanswer;

	// Check if the user's answer is correct
	bool isCorrect = false;
	if (mathproblems[math] == "+") {
		// Check addition
		isCorrect = (mathanswer == mathproblemNum1 + mathproblemNum2);
	}
	else if (mathproblems[math] == "-") {
		// Check subtraction
		isCorrect = (mathanswer == mathproblemNum1 - mathproblemNum2);
	}
	else if (mathproblems[math] == "*") {
		// Check multiplication
		isCorrect = (mathanswer == mathproblemNum1 * mathproblemNum2);
	}

	// Provide feedback based on whether the user's answer is correct
	if (isCorrect) {
		// The user's answer is correct
		std::cout << "Correct! Well done, " << word << "!\n";
	}
	else {
		// The user's answer is incorrect
		std::cout << "Incorrect. The correct answer was ";
		// Display the correct answer based on the operation
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

	//point where the user will return to if they choose to run it again
	while (againb) {
		//display all the planets in the map Currently 
		std::cout << "Glad to have you, " << name << "! Which planet will you be traveling to? (Type 'exit' to end the program)\n";
		std::cout << "- Sun\n- Mercury\n- Venus\n- Earth\n- Mars\n- Jupiter\n- Saturn\n- Uranus\n- Neptune\n- Pluto\n";

		std::string Planet;
		std::cin >> Planet;
		//lets user exit the code
		if (Planet == "exit" || Planet == "Exit") {
			std::cout << "Sorry to hear that. Goodbye!\n";

		}
		//Checks if the planet is valid
		auto check = planetDistances.find(Planet);
		if (check != planetDistances.end()) {
			double distance = planetDistances[Planet];
			std::cout << Planet << " is " << distance << " Kilometers away and will take about " << (distance / TravelSpeed) / 24 << " days to travel to at " << TravelSpeed << "km/h.\n";
			std::cout << "Would you like to travel to another planet? (yes/no)\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			std::getline(std::cin, again);
			if (First_letter(again, "y") || First_letter(again, "Y")) { system("cls"); againb = true; }
			else { againb = false; std::cout << "Sorry to hear that Goodbye\n"; }
		}
		//runs if the user enters a planet that isn't included in the map
		else {
			system("cls");
			std::cout << "Error Planet not found press enter to restart" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		std::cin.clear();
		std::getline(std::cin, confirm);
	}
	Kilometers = Miles * 1.609;
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
	trie += 1;
	while (tries > 0) {
		ran = rand() % trie;
		std::cout << ran << "\n";
		tries--;
	}
	std::cout << "Enter 1 to clear the screen or 2 to end the program...\n";
	std::cin >> check; // Wait for user input
	if (check == 1) { system("CLS"); }  // Clear the screen
	if (check == 2) { return 0; }//returns zero


	//random names = # of tries set// I used the variable name tries as i already had it for something later in the code and it was easy to use instead of making a new one
	std::cout << "how many random names would you like?\n";
	std::cin >> tries;
	trie = tries;
	if (trie == 1) {
		std::cout << "here is one random name\n";
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
	tries = 0;
	//checking if any vectors have repeat names
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
	//so I know the total number of names it picks from
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


	//average inline header test
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
		system("shutdown /s /t 25");
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
