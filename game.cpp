#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


int askLen() {
	int len = 0;
	scanf("%d", &len);
	printf("\n");
	if (len > 10) {
		return len = 10;
	}
	else {
		return len;
	}
}

bool isIsolated(int position, int len, int* board) {
	if (position == 0) {
		if (board[1] == 1) {
			return false;
		}
		else {
			return true;
		}
	}

	else if (position == (len - 1)) {
		if (board[position - 1] == 1) {
			return false;
		}
		else {
			return true;
		}
	}
	else if (board[position - 1] == 1 || board[position + 1] == 1) {
		return false;
	}
	else {
		return true;
	}
}

bool winner(int len, int* board) {
	for (int i{}; i < len; i++) {
		if (board[i] == 1 && isIsolated(i, len, board) != true) {
			return false;
		}
	}
	return true;
}

void printBoard(int N, int* board) {
	printf("\n");
	for (int i{}; i < N; i++) {
		printf("%d", board[i]);
	}
	printf("\n");
}

bool moveOk(int move, int len, int* board) {
	if (move < 0 || move >= len) {
		return false;
	}
	else if (board[move] == 0) {
		return false;
	}
	return true;
}

void move(int len, int* board) {
	int move = -1;
	do {
		printf("Choose next move ");
		scanf("%d", &move);
		printf("\n");
	} while (moveOk(move, len, board) != true);
	board[move] = 0;
}


int main() {
	printf("Welcome to isolate game!!! \n");
	printf("Start by deciding the length of the game: ");
	int length = askLen();
	int* board = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; i++) {
		board[i] = 1;
	}
	int player = 1;
	while (winner(length, board) != true) {
		printf("Player %d turn", player);
		printBoard(length, board);
		move(length, board);
		if (player == 1) {
			player = 2;
		}
		else {
			player = 1;
		}
	}
	printf("No more possible moves\n");
	printf("Player %d wins the game", player);
	free(board);
}


/*Rules of the game are:
The game is played by 2 players
There is a length N array, where N>10 is given by user
At initial position the array is filled by 1's
In his/her turn the player sets one item, which value is 1, to value 0
Game ends when all 1's in array are isolated, both neighbours of them are 0.
Player who completed last turn loses.
Example, N=5 (indexing starts from 0)
11111, player A chooses position 0
01111, player B chooses position 2
01011, if player A chooses 4 or 5 he loses, and therefore he chooses 1
00011, player B chooses 4
00010, the only 1 is isolated, and therefore player B lose the game
Implement the game in a small, 2-3 student, group. Everyone in a group must submit the solution.

There is a limit of 6 files, and extended deadline.*/
