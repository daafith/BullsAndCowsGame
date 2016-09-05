// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

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
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n"; // << endl instead is OK
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}


void PlayGame() {
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	std::cout << "You have " << MaxTries << " attempts in total" << std::endl;

	for (int i = 1; i <= MaxTries; i++) {
		std::string Guess = GetGuess();
		std::cout << "You typed: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Please enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');

}


