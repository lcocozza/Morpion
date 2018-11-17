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
	int egal = 0;
	int win = 0;

	P1 = malloc(sizeof(char) * 15);
	P2 = malloc(sizeof(char) * 15);
	pos = malloc(sizeof(int) * 3);

	if (P1 == NULL || P2 == NULL)
		exit(0);
	system(CLRSCR);
	name(P1, P2);

	while (jeu)
	{
		init_tab(tab);
		system(CLRSCR);

		while (reload)
		{
			system(CLRSCR);
			display_head(P1, P2, V1, V2);
			display_tab(tab);
			if (tour == 1 && erreur == 0)
				tour = 0;
			else if (erreur == 0)
				tour = 1;
			if (erreur == 2)
				printf("la case contient deja %c !\n", tab[pos[0]][pos[1]]);
			else if (erreur == 1)
				printf("La case selectionner ne fait pas\npartie de la grille !\n");
			else if (tour)
				printf("%s, a vous de jouer (O) !\n", P2);
			else
				printf("%s, a vous de jouer (X) !\n", P1);
			select_case(pos);
			erreur = check_case(tab, pos);
			if (erreur == 0)
				if (tour)
					tab[pos[0]][pos[1]] = 'O';
				else
					tab[pos[0]][pos[1]] = 'X';
			win = test_win(tab);
			egal = check_egal(tab, win);
			if (win == 1 || egal == 1)
				reload = 0;
		}
		system(CLRSCR);

		if (tour == 1 && egal == 0)
			V2++;
		else if (egal == 0)
			V1++;
		display_head(P1, P2, V1, V2);
		display_tab(tab);

		if (egal == 1)
			printf("Personne n'a gagner, c'est une egalitee !\n");
		else if (tour)
			printf("%s a gagner la partie !\n", P2);
		else
			printf("%s a gagner la patie !\n", P1);
		printf(	"voulez vous rejouer ?\n"
				"1. Oui\n"
				"0. Non\n");
		scanf("%d", &jeu);
		if (jeu)
			reload = 1;
	}
	system(CLRSCR);
	free(P1);
	free(P2);
	free(pos);

	return 0;
}
