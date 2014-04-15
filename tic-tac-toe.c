/*
 * Tic Tac Toe Game
 * 2 Players
 */
#include <stdio.h>

int main() {

	char sqr[9] = "123456789";
	char turn = 'x';
	int opt;
	int end = 0;
	int k;
	
	while (end != 1) {
		
		// draw game
		printf("\n");
		for (k = 0; k < 3; k++) {
			printf("\t     |     |   \n");
			printf("\t  %c  |  %c  |  %c\n", sqr[k * 3], sqr[k * 3 + 1], sqr[k * 3 + 2]);
			printf("\t     |     |   \n");
			if (k != 2) {
				printf("\t-----------------\n");
			}
		}
		printf("\n\n");
		
		if (turn == 'x') {
			printf("Player 1 - Choose a number: ");
		} else {
			printf("Player 2 - Choose a number: ");
		}
		scanf("%d", &opt);
		
		switch (opt) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				if ((sqr[opt-1] == 'x') || (sqr[opt-1] == 'o')) {
				} else {
					sqr[opt-1] = turn;
					// check for filled rows or columns - win
					if ((sqr[0] == turn) && (sqr[1] == turn) && (sqr[2] == turn)
							|| (sqr[3] == turn) && (sqr[4] == turn) && (sqr[5] == turn)
							|| (sqr[6] == turn) && (sqr[7] == turn) && (sqr[8] == turn)
							|| (sqr[0] == turn) && (sqr[3] == turn) && (sqr[6] == turn)
							|| (sqr[1] == turn) && (sqr[4] == turn) && (sqr[7] == turn)
							|| (sqr[2] == turn) && (sqr[5] == turn) && (sqr[8] == turn)
							|| (sqr[0] == turn) && (sqr[4] == turn) && (sqr[8] == turn)
							|| (sqr[2] == turn) && (sqr[4] == turn) && (sqr[6] == turn)) {
						system("cls");
						if (turn == 'x') {
							printf("Congratulations Player 1 (%c)! You Won.\n", turn);
						} else {
							printf("Congratulations Player 2 (%c)! You Won.\n", turn);
						}
						end = 1;
						break;
					} else {
						// check for draw
						if ((sqr[0] != '1') && (sqr[1] != '2') && (sqr[2] != '3')
								&& (sqr[3] != '4') && (sqr[4] != '5') && (sqr[5] != '6')
								&& (sqr[6] != '7') && (sqr[7] != '8') && (sqr[8] != '9')) {
							system("cls");
							printf("it's a Draw!\n", turn);
							end = 1;
							break;
						} else {
							if (turn == 'x') {
								turn = 'o';
							} else {
								turn = 'x';
							}
							system("cls");
							break;
						}
					}
				}
			default:
				system("cls");
				printf("The number you chose is not an option!\n");
				break;
		}
	}
	
	// game result redraw
	printf("\n");
	for (k = 0; k < 3; k++) {
		printf("\t     |     |   \n");
		printf("\t  %c  |  %c  |  %c\n", sqr[k * 3], sqr[k * 3 + 1], sqr[k * 3 + 2]);
		printf("\t     |     |   \n");
		if (k != 2) {
			printf("\t-----------------\n");
		}
	}
	printf("\n\n");
	
	system("pause");
	return 0;
}