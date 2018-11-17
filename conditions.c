void	init_tab(char tab[3][3])
{
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			tab[x][y] = ' ';
}

int	check_case(char tab[3][3], int *pos)
{
	if ((pos[0] < 0 || pos[0] > 2) && (pos[1] < 0 || pos[1] > 2))
		return 1;
	if (tab[pos[0]][pos[1]] != ' ')
		return 2;
	return 0;
}

int	test_win(char tab[3][3])
{
	//lignes
	if ((tab[0][0] == tab[0][1] && tab[0][1] == tab[0][2]) && tab[0][1] != ' ')
		return 1;
	else if ((tab[1][0] == tab[1][1] && tab[1][1] == tab[1][2]) && tab[1][1] != ' ')
		return 1;
	if ((tab[2][0] == tab[2][1] && tab[2][1] == tab[2][2]) && tab[2][1] != ' ')
		return 1;
	//colonnes
	if ((tab[0][0] == tab[1][0] && tab[1][0] == tab[2][0]) && tab[1][0] != ' ')
		return 1;
	if ((tab[0][1] == tab[1][1] && tab[1][1] == tab[2][1]) && tab[1][1] != ' ')
		return 1;
	if ((tab[0][2] == tab[1][2] && tab[1][2] == tab[2][2]) && tab[1][2] != ' ')
		return 1;
	//diagonal
	if ((tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) && tab[1][1] != ' ')
		return 1;
	if ((tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) && tab[1][1] != ' ')
		return 1;
	return 0;
}

int	check_egal(char tab[3][3], int win)
{
	int j;
	
	if (win)
		return 0;

	printf("tab egal = %c\n", tab[0][0]);
	for (int i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (tab[i][j] == ' ')
				return 0;
	return 1;
}
