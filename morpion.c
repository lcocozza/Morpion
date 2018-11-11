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

	P1 = malloc(15 * sizeof(char));
	P2 = malloc(15 * sizeof(char));

	if (P1 == NULL || P2 == NULL)
		exit(0);

	init_tab(tab);
	system("clear");
	name(P1, P2);

	while (jeu)
	{
		system("clear");
		display_head(P1, P2, V1, V2);
		display_tab(tab);
		if (tour)
			printf("%s, a vous de jouer !\n", P2);
		else
			printf("%s, a vous de jouer !\n", P1);

		return 0;
	}

	return 0;
}
