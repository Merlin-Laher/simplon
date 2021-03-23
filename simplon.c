#include <stdio.h>
#include <stdlib.h>

int main()
{
//creation de la salle
	int rows = 8, seats = 9, keep_going = 1, tickets = 0, desired_row = 0, count = 0, i = 0;
	int room[8][9] = {{0}};

/*initialisation de toutes les valeurs des sièges à 0, si l'on veut initialiser room avec les variables rows et seats
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < seats; ++j)
		{
			room[i][j] = 0;
		}
	}
*/

	printf("Bienvenue dans le programme de reservation de places de SimplonTheater\n");
	printf("Pour quitter ce programme, repondez a n'importe laquelle des questions par un nombre superieur ou egal a 10.\n\n");

	while(keep_going)
	{
//récuperation du nombre de places à attribuer
		printf("Combien de place desirez-vous ?\n");
		scanf("%d", &tickets);

		printf("A quelle rangee souhaitez-vous vous asseoir ?\n");
		scanf("%d", &desired_row);

		if(tickets > 0 && tickets <= seats && desired_row > 0 && desired_row <= rows)
		{
			desired_row--;

//le programme détermine le nombre de places restantes dans la rangée
			for (int i = 0; i < 9; ++i)
			{
				if(room[desired_row][i] == 0)
					count++;
			}

//Si le nombre de places réservées rentre dans la rangée, elles y sont ajoutées
			if(count >= tickets)
			{
				for (int i = 0; i < 9; ++i)
				{
					if(tickets == 0)
						break;
					if(room[desired_row][i] == 0)
					{
						room[desired_row][i] = 1;
						tickets--;
					}
				}
//impression de la salle
				for (int i = rows-1; i >= 0; --i)
				{
					printf("%d ", i+1);
					for (int j = 0; j < seats; ++j)
					{
						if(room[i][j])
							printf("[X] ");
						else
							printf("[ ] ");
					}
					printf("\n");
				}

				for (int i = 0; i < 9; ++i)
				{
					printf("   %d", i+1);
				}

				printf("\n");
			}else
			{
				printf("Desole, cette rangee ne contient pas suffisament de places.\nVeuillez recommencer\n\n");
			}
			count = 0;
		}else
		{
				printf("Desole, nous n'avons pas compris vos instructions\nDesirez-vous quitter ? OUI = 0 NON = 1\n\n");
				scanf("%d", &keep_going);
//ce système d'arrêt de programme n'est pas optimal, mais il n'encombre pas le fonctionnement requis du programme et serait facilement regle avec un interface graphique
		}

	}

}