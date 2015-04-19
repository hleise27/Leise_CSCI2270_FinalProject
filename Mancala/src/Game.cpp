#include "Game.h"
#include "Board.h"
#include "Utilities.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

Game::Game(int numPlayers)
{
    playerID = 1;
    board = new Board();

    if (numPlayers == 1) {
        this->solo();
    } else if (numPlayers == 2) {
        this->twoPlayer();
    } else {
        cout << "Something went wrong!" << endl;
        exit(0);
    }
}

Game::~Game()
{
    delete board;
}

void Game::solo()
{

}

void Game::twoPlayer()
{
    while (!board->gameOver()) {
        Utilities::clearScreen();
        board->drawBoard();
        player(playerID);
        playerID = setNextPlayer();
    }

    board->collect();

    Utilities::clearScreen();
    board->drawBoard();
    cout << endl;

    if (board->getP1Store() > board->getP2Store()) {
        cout << "Player 1 Won!!!" << endl;
        cout << "***************" << endl;
        cout << "Player 1: " << board->getP1Store() << endl;
        cout << "Player 2: " << board->getP2Store() << endl;
    } else if (board->getP2Store() > board->getP1Store()) {
        cout << "Player 2 Won!!!" << endl;
        cout << "***************" << endl;
        cout << "Player 1: " << board->getP1Store() << endl;
        cout << "Player 2: " << board->getP2Store() << endl;
    } else {
        cout << "Tie Game!!!" << endl;
        cout << "***************" << endl;
        cout << "Player 1: " << board->getP1Store() << endl;
        cout << "Player 2: " << board->getP2Store() << endl;
    }

    // waits for user to press Enter
    cout << endl;
    cout << "Press Enter to return to the menu" << endl;
    string input;
    cin.clear();
    getline(cin, input);

    // clears screen
    Utilities::clearScreen();

    // return to menu
    Utilities::menu();
}

// set playerID to the next player
int Game::setNextPlayer()
{
    if (playerID == 1) {
        return 2;
    } else if (playerID == 2) {
        return 1;
    }
}

void Game::player(int id)
{
    string choice;
    bool again;

    // print player name
    cout << endl;
    if (id == 1) {
        cout << "Player 1: " << endl;
    } else if (id == 2) {
        cout << "Player 2: " << endl;
    } else {
        cout << "Something went wrong!" << endl;
        exit(0);
    }

    // get player choice & convert to lower-case
    cin.clear();
    getline(cin, choice);
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    // logic on their choice
    if (choice == "q") {
        cout << "Goodbye!" << endl;
        exit(0);
    } else if (choice == "m") {
        Utilities::quitGame();
    } else if ((choice == "a") || (choice == "b") || (choice == "c") || (choice == "d") || (choice == "e") || (choice == "f")) {
        if (id == 1) {
            if ((choice == "a") && (board->getP1Holes()[0] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "b") && (board->getP1Holes()[1] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "c") && (board->getP1Holes()[2] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "d") && (board->getP1Holes()[3] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "e") && (board->getP1Holes()[4] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "f") && (board->getP1Holes()[5] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else {
                if (choice == "a") {
                    again = board->playerMove(id, 0);
                } else if (choice == "b") {
                    again = board->playerMove(id, 1);
                } else if (choice == "c") {
                    again = board->playerMove(id, 2);
                } else if (choice == "d") {
                    again = board->playerMove(id, 3);
                } else if (choice == "e") {
                    again = board->playerMove(id, 4);
                } else if (choice == "f") {
                    again = board->playerMove(id, 5);
                } else {
                    cout << "Something went wrong" << endl;
                    exit(0);
                }

                if ((again == true) && (!board->gameOver())) {
                    Utilities::clearScreen();
                    board->drawBoard();
                    player(id);
                }
            }
        } else if (id == 2) {
            if ((choice == "f") && (board->getP2Holes()[0] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "e") && (board->getP2Holes()[1] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "d") && (board->getP2Holes()[2] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "c") && (board->getP2Holes()[3] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "b") && (board->getP2Holes()[4] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "a") && (board->getP2Holes()[5] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else {
                if (choice == "f") {
                    again = board->playerMove(id, 0);
                } else if (choice == "e") {
                    again = board->playerMove(id, 1);
                } else if (choice == "d") {
                    again = board->playerMove(id, 2);
                } else if (choice == "c") {
                    again = board->playerMove(id, 3);
                } else if (choice == "b") {
                    again = board->playerMove(id, 4);
                } else if (choice == "a") {
                    again = board->playerMove(id, 5);
                } else {
                    cout << "Something went wrong" << endl;
                    exit(0);
                }

                if ((again == true) && (!board->gameOver())) {
                    Utilities::clearScreen();
                    board->drawBoard();
                    player(id);
                }
            }
        } else {
            cout << "Something went wrong" << endl;
            exit(0);
        }
    } else {
        cout << "Choices are A, B, C, D, E, or F, try again!" << endl;
        player(id);
    }
}
