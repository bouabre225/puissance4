#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

typedef struct Matrice;
struct Matrice
{
    char Mat [6][7];
};

typedef struct Joueurs;
struct Joueurs
{
    char nom [100];
    char symbole;
};

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
    
}

int main ()
{
    return 0;
}