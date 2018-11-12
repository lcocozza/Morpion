#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

int	main()
{
	char *P1 = NULL;
	char *P2 = NULL;
	char tab[3][3];
	int jeu = 1;
	int V1 = 0;
	int V2 = 0;
	int tour = 0;
	int *x = 0;
	int *y = 0;
	int erreur = 0;
	int reload = 1;

	P1 = malloc(15 * sizeof(char));
	P2 = malloc(15 * sizeof(char));

	if (P1 == NULL || P2 == NULL)
		exit(0);

	init_tab(tab);
	system(CLRSCR);
	name(P1, P2);

	while (jeu)
	{	
		while (reload)
		{
			system(CLRSCR);
			display_head(P1, P2, V1, V2);
			display_tab(tab);
			if (erreur == 1)
				printf("la case contient deja %c !\n", tab[x][y]);
			else if (erreur == 2)
				printf("La case selectionner ne fait pas partie de la grille !");
			else if (tour)
				printf("%s, a vous de jouer !\n", P2);
			else
				printf("%s, a vous de jouer !\n", P1);
			select_case(x, y);
			erreur = check_case(tab, x, y);
		}
		return 0;
	}
	free(P1);
	free(P2);

	return 0;
}
