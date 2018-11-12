/*
** EPITECH PROJECT, 2018
** help.c
** File description:
** help for stadalf, this boosted
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Ta fonction qui pue la mort, j'vais la modifier de telle sorte, qu'elle sera fonctionnelle.
 */

void    old_select_case(int x, int y)
{
	printf("ligne: ");
        scanf("%d", &x);
        printf("Colone: "); // Nice la faute, ça prends 2n, colonne...
	scanf("%d", &y);
}

/*
 * Merci mon Aznou, mais t'as fait quoi ?
 *
 * Alors j'ai déclaré un int* (tableau de int) que j'ai malloc de 3 cases: [0, 1, 2], comme ça, il choppe 2 values, et garde le NULL à la fin (ez)
 * 
 * Ensuite, dans le main, j'ai déclaré un tableau de int aussi, histoire de pouvoir return le tableau de select_case
 * 
 * C'que t'avais oublié de faire, c'était de return les values dans ton select_case à toi, mais ç'aurait pas marché de toutes façons comme t'avais fait.
 *
 * Voilà ;)
 */

int	*select_case()
{
	int *tbl = malloc(sizeof(int) * 3);
	printf("Ligne: ");
	scanf("%d", &tbl[0]);
	printf("Colonne: ");
	scanf("%d", &tbl[1]);
	return (tbl);
}

// On modifie également l'appel à ta fonction dans ton main, sinon, ça marche pas.

int main()
{
	int *tbl = select_case();
	printf("X: %d, Y: %d\n", tbl[0], tbl[1]);
	free(tbl);
	return 0;
}
