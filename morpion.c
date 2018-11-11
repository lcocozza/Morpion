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

	}

	return 0;
}
