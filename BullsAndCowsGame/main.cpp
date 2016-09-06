/* main.cpp : Defines the entry point for the console application.
Uses the BullCow class
Acts as the view in a MVC pattern
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string; //create alias , FText is immutable

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // create the instance

int main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

void PrintIntro() {
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n"; // << endl instead is OK
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "You have " << MaxTries << " tries in total\n";

	// TODO change from for to while loop
	for (int32 i = 1; i <= MaxTries; i++) {
		FText Guess = GetGuess();//TODO make loop check for valid guess

		// Sumbit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
	//TODO add a game summary
}

FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Please enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}


