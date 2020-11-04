#include <stdio.h>

void drawBoard(char board[3][3]);
void makeMove(char board[3][3], int loc[2], int placeX);
char gameOver(char board[3][3]);

int main (void)
{
	char board[3][3] = {0};
	int vect[2] = {0, 0};
	int vec1[2] = {1, 1};
	int vec2[2] = {2, 2};

	drawBoard(board);

	makeMove(board, vect, 1);
	makeMove(board, vec1, 1);
	makeMove(board, vec2, 1);

	drawBoard(board);

	gameOver(board);

	return (0);
}
/*
 * EEE  EEE   EOE
 * EEE  EXE   EXE
 * EEE  EEE   EEE
 *
 */
void drawBoard(char board[3][3])
{
	int idx = 0;
	int jdx = 0;
	char curr_cell;

	printf("The Board currently!!!\n");

	for(idx = 0; idx < 3; idx++)
	{
		for(jdx = 0; jdx < 3; jdx++)
		{
			curr_cell = board[idx][jdx];
			if(curr_cell == 0)
			{
				printf("e");
			} else {
				printf("%c", board[idx][jdx]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

/*
 * makeMove - Add a piece to the board
 * @board: the board we're adding the piece to
 * @loc: an array [x, y] of where to place the piece
 * @placeX: Are we placing an X if not, place a O
 */
void makeMove(char board[3][3], int loc[2], int placeX)
{
	if (placeX) {
		board[loc[1]][loc[0]] = 'X';
	} else {
		board[loc[1]][loc[0]] = 'O';
	}
}

/*
 * gameOver - Is the game over, no more possible moves or someone won
 */
char gameOver(char board[3][3])
{
	int winConditions[8][3][2] = {
		// The horizontal win conditions
		{{0, 0}, {1, 0}, {2, 0}},
		{{0, 1}, {1, 1}, {2, 1}},
		{{0, 2}, {1, 2}, {2, 2}},
		// The Vertical win conditions
		{{0, 0}, {0, 1}, {0, 2}},
		{{1, 0}, {1, 1}, {1, 2}},
		{{2, 0}, {2, 1}, {2, 2}},
		// The diagonal Win conditions
		{{0, 0}, {1, 1}, {2, 2}},
		{{0, 2}, {1, 1}, {2, 0}}
	};
	int i, j;
	char lastSpotValue;
	int *winCond;

	for(i = 0; i < 8; i++) // For each win condition
	{
		lastSpotValue = '\0';
		for(j = 0; j < 3; j++) // For each Coordinate of a win condition
		{
			winCond = winConditions[i][j];
			if(j == 0) // if we're on the first coord to check
			{
				if(board[winCond[1]][winCond[0]] == 0) // is this one empty?
				{
					// no need to continue checking
					break;
				} else {
					lastSpotValue = board[winCond[1]][winCond[0]];
				}
			} else {
				if(board[winCond[1]][winCond[0]] == lastSpotValue)
				{
					if(j == 2) // if it's the last coord to check
					{
						printf("%c Has won the game\n", lastSpotValue);
						return (lastSpotValue);
					}
				} else {
					break;
				}
			}
		}
	}
	printf("No one has won\n");
	return ('\0');
}
