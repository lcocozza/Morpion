#include "morpion.h"

void	name(char *P1, char *P2)
{	
	printf("Quel est le nom du joueur 1 (X) ?: ");
	scanf("%s", P1);
	printf("Quel est le nom du joueur 2 (O) ?: ");
	scanf("%s", P2);
}

void	display_tab(char tab[3][3])
{
	printf("\n============================================\n");
	printf( "\n\n\t\t   0 1 2\n\n"
		"\t\t0 |%c|%c|%c|\n"
		"\t\t  -------\n"
		"\t\t1 |%c|%c|%c|\n"
		"\t\t  -------\n"
		"\t\t2 |%c|%c|%c|\n\n\n", tab[0][0], tab[0][1], tab[0][2], tab[1][0], tab[1][1], tab[1][2], tab[2][0], tab[2][1], tab[2][2]);
	printf("\n============================================\n\n");
}

void	init_tab(char tab[3][3])
{
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			tab[x][y] = ' ';
}

void	display_head(char *P1, char *P2, int V1, int V2)
{
	printf(	"Partie en cours: %s VS %s.\n\n"
		"Score: \n"
		"%s = %d.\n"
		"%s = %d.\n", P1, P2, P1, V1, P2, V2);
}

int	check_case(char tab[3][3], int *pos)
{
	if ((pos[0] < 0 || pos[0] > 2) && (pos[1] < 0 || pos[1] > 2))
		return 1;
	if (tab[pos[0]][pos[1]] != ' ')
		return 2;
	return 0;
}

void	select_case(int *pos)
{
	printf("ligne: ");
	scanf("%d", &pos[0]);
	printf("Colonne: ");
	scanf("%d", &pos[1]);
}

int	test_win(char tab[3][3])
{
	//lignes
	if ((tab[0][0] == tab[0][1] && tab[0][1] == tab[0][2]) && tab[0][1] != ' ')
		return 1; printf("tab[0][1] = %c\n", tab[0][1]);
	if ((tab[1][0] == tab[1][1] && tab[1][1] == tab[1][2]) != ' ')
		return 1;
	if ((tab[2][0] == tab[2][1] && tab[2][1] == tab[2][2]) != ' ')
		return 1;
	//colonnes
	if ((tab[0][0] == tab[1][0] && tab[1][0] == tab[2][0]) != ' ')
		return 1;
	if ((tab[0][1] == tab[1][1] && tab[1][1] == tab[2][1]) != ' ')
		return 1;
	if ((tab[0][2] == tab[1][2] && tab[1][2] == tab[2][2]) != ' ')
		return 1;
	//diagonal
	if ((tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) != ' ')
		return 1;
	if ((tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) != ' ')
		return 1;
	return 0;
}
