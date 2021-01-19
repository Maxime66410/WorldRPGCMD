#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>

#define PROGRESS_BAR_SIZE 40
#define INT_SIZE sizeof(int) *8

//Game Manager
int nbrs_tours = 0, selectedClass =-1, selectedGameMenu = -1, selectedAttackPlayer = -1, blockAttackValue = -1, saveHealthClass = -1;
bool win_Player = false, win_Enemy = false, egal_win = false;

//Item Manager
int selectedItems = -1, healthItem = -1, powerItem = -1, elexirItem = -1, healthPotionValue = 0, powerPotionValue = 0;
bool powerIsEnabled = false;

//Player Manager
int player_Health = 0, player_MaxHealth = 0, player_Attack = 0;
bool player_block = false, gameOver = false;

//Enemy Manager
int enemy_Health = 0, enemy_MaxHealth = 0, enemy_Attack = 0;
bool enemy_Block = false, isDead = false;


int main()
{
	/*
	int p;
	for (p = 0; p <= 100; ++p) {
		display_progress_bar(p);
		Sleep(100);
	}
	system("cls");
	for (p = 0; p <= 100; ++p) {
		display_progress_bar(p);
		Sleep(30);
	}
	system("cls");
	*/
	Menu();
}

void print_n_chars(int n, int c) {
    while (n-- > 0) putchar(c);
}

void display_progress_bar(int p) {
    putchar('\r');
    putchar('[');
    print_n_chars(PROGRESS_BAR_SIZE * p / 100, '|');
    print_n_chars(PROGRESS_BAR_SIZE - PROGRESS_BAR_SIZE * p / 100, ' ');
    putchar(']');
}

void Menu()
{
	int entree;
	printf("#####################################  Menu  ######################################");
	printf("\n#                                                                                 #");
	printf("\n#                                                                                 #");
	printf("\n#                    Voulez vous jouer a une nouvelle partie ?                    #");
	printf("\n#                                                                                 #");
	printf("\n#                                                                                 #");
	printf("\n#              Oui : 0                                      Non : 1               #");
	printf("\n#                                                                                 #");
	printf("\n#                                                                                 #");
	printf("\n###################################################################################");
	printf("\n=> ");
	scanf("%d", &entree);

	if(entree <= 0)
	{
		system("cls");
		characterSelected();
	}
	if(entree >= 1)
	{
		return 0;
	}
}

void characterSelected()
{
	printf("######################### Selectionner une classe #########################");
	printf("\n");
	printf("\n");
	printf("Classe Hero : 0");
	printf("\n");
	printf("\n");
	printf("Classe Tank : 1");
	printf("\n");
	printf("\n");
	printf("Classe Archer : 2");
	printf("\n");
	printf("\n");
	printf("###########################################################################");
	printf("\n=> ");
	scanf("%d", &selectedClass);

	if(selectedClass == 0)
	{
		printf("\n=> Classe Hero selectionner <=");
		sleep(5);
		initialisationpartie();
	}

	if(selectedClass == 1)
	{
		printf("\n=> Classe Tank selectionner <=");
		sleep(5);
		initialisationpartie();
	}

	if(selectedClass == 2)
	{
		printf("\n=> Classe Archer selectionner <=");
		sleep(5);
		initialisationpartie();
	}

	if(selectedClass >= 3)
	{
		system("cls");
		characterSelected();
	}
}

int Game()
{
	if(player_Health <= 0)
	{
		gameOver = true;
		win_Enemy = true;
	}

	if(enemy_Health <= 0)
	{
		isDead = true;
		win_Player = true;
	}

	if(!gameOver && !isDead && !win_Enemy && !win_Player && !egal_win)
	{
		system("cls");
		selectedGameMenu = -1;
		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                             Que voulez vous faire ?                             #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#        Attaquer : 0        Defendre : 1        Objet : 2        Fuir : 3        #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		printf("\n=> ");
		scanf("%d", &selectedGameMenu);
	}

	if(gameOver && win_Enemy)
	{
		system("cls");
		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                                  Tu as perdu !                                  #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(10);
		resetAll();
	}

	if(isDead && win_Player)
	{
		system("cls");
		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                                  Tu as gagner !                                 #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(10);
		resetAll();
	}

	if(selectedGameMenu == 0)
	{
		Attaquer();
	}

	if(selectedGameMenu == 1)
	{
		player_block = true;
		Defendre();
	}

	if(selectedGameMenu == 2)
	{
		Objet();
	}

	if(selectedGameMenu == 3)
	{
		Fuir();
	}

	if(selectedGameMenu >= 4 || selectedGameMenu <=-1)
	{
		Game();
	}
}

int Attaquer()
{
	system("cls");
	srand(time(NULL));
	selectedAttackPlayer = -1;
	player_Attack = 0;
	enemy_Attack = 0;
	printf("###################################################################################");
	printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
	printf("\n###################################################################################");
	printf("\n#                                                                                 #");
	printf("\n#                             Que voulez vous faire ?                             #");
	printf("\n#                                                                                 #");
	printf("\n###################################################################################");
	printf("\n#                                                                                 #");
	printf("\n#        Attaquer Normal : 0        Attaquer Charger : 1        Smash : 2         #");
	printf("\n#                                                                                 #");
	printf("\n###################################################################################");
	printf("\n=> ");
	scanf("%d", &selectedAttackPlayer);

	if(selectedAttackPlayer == 0) // Attaque normal du joueurs.
	{
		if(!powerIsEnabled)
		{
			player_Attack = (rand() % (80 - 15 + 1) + 15);
		}
		else
		{
			player_Attack = (rand() % (250 - 60 + 1) + 60);
		}

		powerIsEnabled = false;

		enemy_Attack = (rand() % (75 - 15 + 1) + 15);
		system("cls");

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                             Vous attaquer l'enemie !                            #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		if(player_Attack >= 65)
		{
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                   Vous avez fait une attaque critique !                         #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			system("cls");
		}

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                           Vous avez fait %d degats !                            #", player_Attack);
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		enemy_Health = enemy_Health - player_Attack;

		if(enemy_Health <= 0)
		{
			isDead = true;
			win_Player = true;
			Game();
		}

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                            L'enemie vous attaque !                              #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		if(enemy_Attack >= 55)
		{
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                 L'enemie vous a fait une attaque critique !                     #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			system("cls");
		}

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                           Il vous a fait %d degats !                            #", enemy_Attack);
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);

		system("cls");

		player_Health = player_Health - enemy_Attack;

		Game();
	}

	if(selectedAttackPlayer == 1)
	{
		if(!powerIsEnabled)
		{
			player_Attack = (rand() % (150 - 15 + 1) + 15);
		}
		else
		{
			player_Attack = (rand() % (350 - 100 + 1) + 100);
		}

		enemy_Attack = (rand() % (125 - 15 + 1) + 15);

		powerIsEnabled = false;

		system("cls");

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                             Vous attaquer l'enemie !                            #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		if(player_Attack >= 130)
		{
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                   Vous avez fait une attaque critique !                         #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			system("cls");
		}

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                           Vous avez fait %d degats !                            #", player_Attack);
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		enemy_Health = enemy_Health - player_Attack;

		if(enemy_Health <= 0)
		{
			isDead = true;
			win_Player = true;
			Game();
		}

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                            L'enemie vous attaque !                              #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		if(enemy_Attack >= 100)
		{
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                 L'enemie vous a fait une attaque critique !                     #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			system("cls");
		}

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                           Il vous a fait %d degats !                            #", enemy_Attack);
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		player_Health = player_Health - enemy_Attack;

		Game();
	}

	if(selectedAttackPlayer == 2)
	{
		if(!powerIsEnabled)
		{
			player_Attack = (rand() % (250 - 15 + 1) + 15);
		}
		else
		{
			player_Attack = (rand() % (500 - 250 + 1) + 250);
		}

		powerIsEnabled = false;

		enemy_Attack = (rand() % (210 - 15 + 1) + 15);
		system("cls");

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                             Vous attaquer l'enemie !                            #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		if(player_Attack >= 230)
		{
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                   Vous avez fait une attaque critique !                         #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			system("cls");
		}

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                           Vous avez fait %d degats !                            #", player_Attack);
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		enemy_Health = enemy_Health - player_Attack;

		if(enemy_Health <= 0)
		{
			isDead = true;
			win_Player = true;
			Game();
		}

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                            L'enemie vous attaque !                              #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		if(enemy_Attack >= 185)
		{
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                 L'enemie vous a fait une attaque critique !                     #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			system("cls");
		}

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                           Il vous a fait %d degats !                            #", enemy_Attack);
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		player_Health = player_Health - enemy_Attack;

		Game();
	}

	if(selectedAttackPlayer <= -1 || selectedAttackPlayer >= 3)
	{
		Attaquer();
	}

}

int Defendre()  // Action ou le joueur se défend
{
	srand(time(NULL));
	blockAttackValue = rand() % 2 ;
	enemy_Attack = (rand() % (150 - 15 + 1) + 15);
	system("cls");

	if(blockAttackValue == 0)
	{
		player_block = true;
	}

	if(blockAttackValue == 1)
	{
		player_block = false;
	}

	if(player_block) 	// Si le joueur veux ce defendre il peux.
	{
		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                         Vous avez bloquer l'attaque !                           #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		player_block = false;
		enemy_Attack = 0;
		blockAttackValue = -1;
		Game();
	}
	else 	// Si non le joueur n'a pas peux ce protéger.
	{
		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#               Vous avez pas reussi a bloquer l'attaque !                        #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                          L'enemie vous attaquer !                               #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");

		player_Health = player_Health - enemy_Attack;

		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                         Vous avez pris %d degats !                              #", enemy_Attack);
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(5);
		system("cls");
		enemy_Attack = 0;
		blockAttackValue = -1;
		Game();
	}
}

int Objet() // L'inventaire du joueur
{
	srand(time(NULL));
	system("cls");
	selectedItems = -1;
	healthPotionValue = 0;
	printf("###################################################################################");
	printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
	printf("\n###################################################################################");
	printf("\n#                                                                                 #");
	printf("\n#                             Que voulez vous faire ?                             #");
	printf("\n#                                                                                 #");
	printf("\n###################################################################################");
	printf("\n#                                                                                 #");
	printf("\n#          Health Potion : 0        Power Potion : 1        Elexir : 2            #");
	printf("\n#                                                                                 #");
	printf("\n#            En Stock : %d             En Stock : %d         En Stock : %d           #", healthItem, powerItem, elexirItem);
	printf("\n#                                                                                 #");
	printf("\n#                                                           Retour autre que 0 1 2#");
	printf("\n###################################################################################");
	printf("\n=> ");
	scanf("%d", &selectedItems);

	if(selectedItems == 0)
	{
		if(healthItem >= 1 && player_Health != player_MaxHealth)
		{
			system("cls");
			healthItem = healthItem - 1;
			healthPotionValue = (rand() % (80 - 15 + 1) + 15);
			player_Health = player_Health + healthPotionValue;

			if(player_Health >= player_MaxHealth)
			{
				player_Health = saveHealthClass;
			}

			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                        Vous avez utiliser une potion !                          #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			system("cls");
			Game();
		}

		if(player_Health == player_MaxHealth)
		{
			system("cls");
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                          Votre jauge vie sont au max                            #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			Objet();
		}

		if(healthItem <= 1)
		{
			system("cls");
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                     Vous n'avez plus de potion en stock                         #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			Objet();
		}
	}

	if(selectedItems == 1)
	{
		if(powerItem >= 1 && !powerIsEnabled)
		{
			system("cls");
			powerItem = powerItem - 1;

			powerIsEnabled = true;

			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                      Vous avez utiliser une potion Power !                      #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			system("cls");
			Game();
		}

		if(powerIsEnabled)
		{
			system("cls");
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                Potion de Power deja activer veuillez attaquer !                 #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			Objet();
		}

		if(powerItem <= 1)
		{
			system("cls");
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                     Vous n'avez plus de potion en stock                         #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			Objet();
		}
	}

	if(selectedItems == 2)
	{
		if(elexirItem >= 1 && player_Health != player_MaxHealth)
		{
			system("cls");
			elexirItem = elexirItem - 1;
			player_Health = player_Health + saveHealthClass;

			if(player_Health >= player_MaxHealth)
			{
				player_Health = saveHealthClass;
			}

			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                        Vous avez utiliser une elexir !                          #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			system("cls");
			Game();
		}

		if(player_Health == player_MaxHealth)
		{
			system("cls");
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                          Votre jauge vie sont au max                            #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			Objet();
		}

		if(elexirItem <= 1)
		{
			system("cls");
			printf("###################################################################################");
			printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
			printf("\n###################################################################################");
			printf("\n#                                                                                 #");
			printf("\n#                     Vous n'avez plus de elexir en stock                         #");
			printf("\n#                                                                                 #");
			printf("\n###################################################################################");
			sleep(5);
			Objet();
		}
	}

	if(selectedItems >= 3 || selectedItems <= -1)
	{
		Game();
	}
}

int Fuir()
{
	system("cls");

	// Si la vie du joueur ou de l'enemie n'a pas ça vie a moitier il peux fuir si non il ne peux pas !

	if(enemy_Health == enemy_Health / 2 || player_Health == player_Health / 2)
	{
		system("cls");
		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                                   Tu as fuit !                                  #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(10);
		resetAll();
	}
	else
	{
		system("cls");
		printf("###################################################################################");
		printf("\n##### Player Health : %d / %d ################ Enemy Health : %d / %d #####", player_Health, player_MaxHealth, enemy_Health, enemy_MaxHealth);
		printf("\n###################################################################################");
		printf("\n#                                                                                 #");
		printf("\n#                                Tu n'as pas fuit !                               #");
		printf("\n#                                                                                 #");
		printf("\n###################################################################################");
		sleep(10);
		Game();
	}
}

int initialisationpartie()
{
	if(selectedClass == 0)
	{
		system("cls");
		enemy_Health = 5000;
		enemy_MaxHealth = 5000;
		player_Health = 3500;
		player_MaxHealth = 3500;
		saveHealthClass = player_Health;
		healthItem = 4;
		powerItem = 4;
		elexirItem = 1;
		Game();
	}

	if(selectedClass == 1)
	{
		system("cls");
		enemy_Health = 30000;
		enemy_MaxHealth = 30000;
		player_Health = 15000;
		player_MaxHealth = 15000;
		saveHealthClass = player_Health;
		healthItem = 1;
		powerItem = 8;
		elexirItem = 1;
		Game();
	}

	if(selectedClass == 2)
	{
		system("cls");
		enemy_Health = 3000;
		enemy_MaxHealth = 3000;
		player_Health = 1600;
		player_MaxHealth = 1600;
		saveHealthClass = player_Health;
		healthItem = 6;
		powerItem = 1;
		elexirItem = 3;
		Game();
	}
}

int resetAll()
{
	system("cls");
	enemy_Attack = 0;
	enemy_Block = false;
	enemy_Health = 0;
	enemy_MaxHealth = 0;

	sleep(1);

	player_Attack = 0;
	player_block = false;
	player_Health = 0;
	player_MaxHealth = 0;

	sleep(1);

	nbrs_tours = 0;
	selectedClass = -1;
	win_Enemy = false;
	win_Player = false;
	egal_win = false;
	gameOver = false;
	selectedGameMenu = -1;
	selectedAttackPlayer = -1;
	blockAttackValue = -1;
	saveHealthClass = -1;
	healthPotionValue = -1;
	powerPotionValue = -1;
	powerIsEnabled = false;

	sleep(3);

	Menu();
}
