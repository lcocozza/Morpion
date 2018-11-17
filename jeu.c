void	name(char *P1, char *P2)
{	
	printf("Quel est le nom du joueur 1 (X) ?: ");
	scanf("%s", P1);
	printf("Quel est le nom du joueur 2 (O) ?: ");
	scanf("%s", P2);
}

void	select_case(int *pos)
{
	printf("ligne: ");
	scanf("%d", &pos[0]);
	printf("Colonne: ");
	scanf("%d", &pos[1]);
}
