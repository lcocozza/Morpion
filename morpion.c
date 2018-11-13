#include "morpion.h"

int	main()
{
	char *P1 = NULL;
	char *P2 = NULL;
	char tab[3][3];
	int jeu = 1;
	int V1 = 0;
	int V2 = 0;
	int tour = 1;
	int *pos = NULL;
	int erreur = 0;
	int reload = 1;

	P1 = malloc(sizeof(char) * 15);
	P2 = malloc(sizeof(char) * 15);
	pos = malloc(sizeof(int) * 3);

	if (P1 == NULL || P2 == NULL)
		exit(0);

	while (jeu)
	{
		init_tab(tab);
		system(CLRSCR);
		name(P1, P2);

		while (reload)
		{
			system(CLRSCR);
			display_head(P1, P2, V1, V2);
			display_tab(tab);
			if (test_win(tab) != 0)
				reload = 0;
			else
			{
				if (tour == 1 && erreur == 0)
					tour = 0;
				else if (erreur == 0)
					tour = 1;
				if (erreur == 2)
					printf("la case contient deja %c !\n", tab[pos[0]][pos[1]]);
				else if (erreur == 1)
					printf("La case selectionner ne fait pas\npartie de la grille !\n");
				else if (tour)
					printf("%s, a vous de jouer !\n", P2);
				else
					printf("%s, a vous de jouer !\n", P1);
				select_case(pos);
				erreur = check_case(tab, pos);
				if (erreur == 0)
					if (tour)
						tab[pos[0]][pos[1]] = 'O';
					else
						tab[pos[0]][pos[1]] = 'X';
			}
		}
		printf("Gagner\n");
		return 0;
	}
	free(P1);
	free(P2);
	free(pos);

	return 0;
}
