#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

typedef struct Matrice Matrice;
struct Matrice
{
    char Mat[6][7];
};

typedef struct Joueurs Joueurs;
struct Joueurs
{
    char nom [100];
    char symbole;
};

Joueurs jou1, jou2;
Matrice m;
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    fflush(stdout);
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void clrscr()
{
  system("cls");
}

// Fonction pour dessiner la grille
void grille4puissance ()
{
    int a=0; int b=0; int newx=0; int colonne=0; int compt=0; int col=7; int lon=49; int ligne=0; int l=0; int j=1; int newy=0; int i; int x=8; int y=8; int haut=2;

    gotoxy(x,y); printf("%c",218);
    gotoxy(x+lon,y); printf("%c",191);
    if (ligne == 0)
    {
        for (i = 1; i < lon; i++)
        {
            gotoxy(x+i,y); printf("%c",196);
            gotoxy(x+i,y+haut); printf("%c",196); 
            compt++;
            if (col == compt)
            {
                l += col;
                gotoxy(x+l,y-1); printf("%d", colonne);
                gotoxy(x+i,y); printf("%c",194);
                gotoxy(x+i,y+haut); printf("%c",197);
                compt = 0;
                colonne++;
                compt = 0;
            }
        }
        l += col;
        gotoxy(x+l,y-1); printf("6"); 
        gotoxy(x,y+haut); printf("%c", 179);
        gotoxy(x+lon,y+haut); printf("%c", 179);

        newx=col;
        compt=0;

        do 
        {
            for (i = 1; i < haut; i++)
            {
                gotoxy(x,y+i); printf("%c", 179);
                gotoxy(x+newx,y+i); printf("%c", 179);
            }
            newx += col;
            compt++;
        } while (compt < col);
    }
    do 
    {
        if (ligne > 0 && ligne < 5)
        {
            newx = col;
            compt = 0;
            newy=b*haut+y;
            for (compt = 0; compt < col; compt++)
            {
                for (i = 1; i < haut; i++)
                {
                    gotoxy(x,newy+i); printf("%c",179);
                    gotoxy(x+newx,newy+i); printf("%c",179);
                }
                newx += col;
            }
            do 
            {
                gotoxy(x+j,newy+haut); printf("%c",196);a++;
                if (col == a)
                {
                    gotoxy(x+j,newy+haut); printf("%c",197);
                    a = 0;
                }  
                j++;
            } while (j < lon);
            j = 1;
            a = 0;
            gotoxy(x,newy+haut); printf("%c",179);
            gotoxy(x+lon,newy+haut); printf("%c",179);
        }
        if (ligne < 5) printf ("%d", ligne);
        ligne++;
        b++;
    } while (ligne < 7); 
    newy=5*haut+y;
    if (ligne == 7)
    {
        compt = 0;
        gotoxy(x, newy+haut); printf("%c",192);
        gotoxy(x+lon, newy+haut); printf("%c",217);printf("5");

        for (i = 1; i < lon; i++)
        {
            gotoxy(x+i,newy+haut); printf("%c",196);
            compt++;
            if (col == compt)
            {
                gotoxy(x+i,newy+haut); printf("%c",193);
                compt = 0;
            }
        }
        newx = col;
        compt = 0;

        do 
        {
            for (i = 1; i < haut; i++)
            {
                gotoxy(x,newy+i); printf("%c",179);
                gotoxy(x+newx,newy+i); printf("%c",179);
            }
            newx += col;
            compt++;
        } while (compt < col);
    }
}

void init_jeu()
{
    char p1; char p2; int verif = 0; int taille; int tour; int victoire = 0;

    gotoxy(8,22);printf("Nom Joueur 1:");
    gotoxy(8,23);printf("Nom Joueur 2:");
    gotoxy(22,22);scanf("%s", &jou1.nom);
    gotoxy(22,22);scanf("%s", &jou2.nom);
    srand(time(NULL));
    int random = 1 + rand() % 2;

    do 
    {
        if (random == 1)
        {
            gotoxy(8,25);printf("%s choisis ton symbole (X/O):", jou1.nom);
            taille = strlen(jou1.nom);
            gotoxy(37+taille,25);scanf(" %c", &jou1.symbole);
        } else 
        {
            gotoxy(8,25);printf("%s choisi ton symbole (X/O):", jou2.nom); 
            taille = strlen(jou2.nom);
            gotoxy(37+taille,25);scanf(" %c", &jou2.symbole);
        }

        if (jou1.symbole!= 'X' && jou1.symbole!= 'O' && jou2.symbole!= 'X' && jou2.symbole!= 'O')
        {
            gotoxy(8,26);printf("Erreur veillez choisir entre (X/O)");
        } else 
        {
            verif = 1;
            if (jou1.symbole == 'X') jou2.symbole == 'O';
            if (jou1.symbole == 'O') jou2.symbole == 'X';
            if (jou2.symbole == 'X') jou1.symbole == 'O';
            if (jou1.symbole == 'O') jou2.symbole == 'X';
        }
    } while (verif == 0);
    clrscr();
    grille4puissance();

    gotoxy(80,8);printf("JEU DE PUISSANCE 4");
    gotoxy(80,12);printf("Symbole de %s : %c" , jou1.nom, jou1.symbole);
    gotoxy(80,12);printf("Symbole de %s : %c" , jou2.nom, jou2.symbole);

    if ( random == 1)
    {
        gotoxy(80,17);printf("C'est %s qui commence.", jou1.nom);
    } else 
    {
        gotoxy(80,17);printf("C'est %s qui commence.", jou2.nom);

    }

    tour = random;
    int position1,position2;
    do 
    {
        if (tour == 1 && victoire != 1)
        {
            do 
            {
                gotoxy(8,27);printf(" %s Entre un numero de colonne valide: ", jou1.nom);
                gotoxy(38+taille,27);scanf("%d", &position1);
            } while(position1 < 0 || position1 > 6);
        }

        if (tour == 2 && victoire != 1)
        {
            do 
            {
                gotoxy(8,27);printf(" %s Entre un numero de colonne valide: ", jou2.nom);
                gotoxy(38+taille,27);scanf("%d", &position1);
            } while(position1 < 0 || position1 > 6);
        }
    } while( victoire != 1);
}

void jouer_colonne (int tour, int position)
{
    int l,col = 0; int newy = 7; int newx = 13; int a = position+1 ; int y = 0; int c = 4;
    char t; int b=0;
    
}

int main ()
{
    grille4puissance();
    return 0;
}