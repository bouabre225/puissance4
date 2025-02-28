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
    
    if (tour == 1)
    {
        while (col != position)
        {
            newx += 7;  
            col++;
        }
        if (m.Mat[5][position] != 'X' && m.Mat[5][position] != 'O')
        {
            b = 0;
            for (l = 0; l < 6; l++)
            {
                if (m.Mat[l][position] != 'X' && m.Mat[l][position] != '0')
                {
                    newy +=2;
                }
                if (l == 5)
                {
                    m.Mat[5][position]=jou1.symbole;
                    gotoxy(newx-1,newy);printf("%c",m.Mat[l][position]);
                }
            }
        } else 
        {
            if (m.Mat[0][position] != 'X' && m.Mat[0][position] != 'O')
            {
                for (l = 0; l < 6; l++)
                {
                    if (m.Mat[l][position] != 'X' && m.Mat[l][position] != 'O')
                    {
                        newy +=2;
                    }
                    if (m.Mat[l][position] == 'X' || m.Mat[l][position] == 'O')
                    {
                        if (m.Mat[l-1][position] != 'X' && m.Mat[l-1][position] != 'O')
                        {
                            m.Mat[l-1][position] = jou1.symbole;
                            gotoxy(newx-1,newy);printf("%c",m.Mat[l-1][position]);
                        }
                    }
                }
            }
        }
    }

    if (tour == 2)
    {
        while (col != position)
        {
            newx += 7;  
            col++;
        }
        if (m.Mat[5][position] != 'X' && m.Mat[5][position] != 'O')
        {
            for (l = 0; l < 6; l++)
            {
                if (m.Mat[l][position] != 'X' && m.Mat[l][position] != 'O')
                {
                    newy +=2;
                }
                if (l == 5)
                {
                    m.Mat[5][position] = jou2.symbole;
                    gotoxy(newx-1,newy);printf("%c",m.Mat[l][position]);
                }
            }
        } else 
        {
            if (m.Mat[0][position] != 'X' && m.Mat[0][position] != 'O')
            {
                for (l = 0; l < 6; l++)
                {
                    if (m.Mat[l][position] != 'X' && m.Mat[l][position] != 'O')
                    {
                        newy +=2;
                    }
                    if (m.Mat[l][position] == 'X' || m.Mat[l][position] == 'O')
                    {
                        if (m.Mat[l-1][position] != 'X' && m.Mat[l-1][position] != 'O')
                        {
                            m.Mat[l-1][position] = jou2.symbole;
                            gotoxy(newx-1,newy);printf("%c",m.Mat[l-1][position]);
                        }
                    }
                }
            }
        }
    }
}

int verif_gain(char symbole, int position)
{
   int l; int compt = 0; int x = 38; int y = 22; int x2 = 55; int c = 0;int p = 0; int d = position;

    //vericale
    for (l = 0; l < 6; l++)
    {
        if (m.Mat[l][position] == symbole)
        {
            compt++;
        }
        if (m.Mat[l][position] != symbole)
        {
            compt = 0;
        }
        if (compt == 4 && jou1.symbole == symbole)
        {
            gotoxy(8,27);printf("Victoire sur la Verticale de %s " , jou1.nom);
            return 1 ;
            break;
        }
        if (compt == 4 && jou2.symbole == symbole)
        {
            gotoxy(8,27);printf("Victoire sur la Verticale de %s ", jou2.nom);
            return 1 ;
            break;
        }
    }

    //horizontale
    compt = 0;
    for (l = 0; l < 6; l++)
    {
       for (c = 0; c < 6; c++)
       {
          compt = 0;

        if (m.Mat[l][c] != symbole) compt = 0;
        if (compt == 4 && jou1.symbole == symbole)
        {
            gotoxy(8,27);printf("Victoire sur l'Horizontale de %s " , jou1.nom);
            return 1 ;
            break;
        }
        if(compt == 4 && jou2.symbole == symbole)
        {
            gotoxy(8,27);printf("Victoire sur l'Horizontale de %s " , jou2.nom);
            return 1 ;
            break;
        }
        }
    }

    // Diagonale gauche
    compt = 0;
    for (l = 0; l < 6; l++)
    {

        if (m.Mat[l][position]==symbole )
        {
            p = l;
            c = position;gotoxy(8,22); 
            break; 
        }  
    }
        for (l = p; l < 6; l++)
        {
            for (c = position; c > 0; c--)
            {
                if (m.Mat[l][c] == symbole)
                {
                    compt++;
                    position = position-1;
                    break;
                }           
                if (m.Mat[l][c] != symbole )compt=0;    
            }
            if (compt == 4 && jou1.symbole == symbole)
            {
                gotoxy(8,27);printf("Victoire sur la Diagonale Gauche Vers le Bas de %s " , jou1.nom);
                return 1;
                break;
            }
            if (compt == 4 && jou2.symbole == symbole)
            {
                gotoxy(8,27);printf("Victoire sur la Diagonale Gauche vers le Bas de %s " , jou2.nom);
                return 1;
                break;
            }
        }

    //Diagonale Droite
    compt = 0;
    position = d;
    
    for (l = 0; l < 6; l++)
    {
        if (m.Mat[l][position] == symbole)
        {
            p = l;
            c = position;gotoxy(8,22);
            break; 
        }  
    }
        for (l = p; l < 6; l++)
        {
            for (c = position; c < 7; c++)
            {
                if (m.Mat[l][c] == symbole)
                {
                    compt++;
                    position +=1;
                    break;
                }           
                if (m.Mat[l][c] != symbole) compt=0; 
            }
            if (compt == 4 && jou1.symbole == symbole)
            {
                gotoxy(8,27);printf("Victoire sur la Diagonale Droite Vers le Bas de %s " , jou1.nom);
                return 1;
                break;
            }
            if (compt == 4 && jou2.symbole == symbole)
            {
                gotoxy(8,27);printf("Victoire sur la Diagonale Droite Vers le Bas de %s " , jou2.nom);
                return 1;
                break;
            }
        }

    //Diagonale haut Droite
    compt = 0;
    position = d;
    
    for (l = 0; l < 6; l++)
    {
        if (m.Mat[l][position] == symbole )
        {
            p = l;
            c = position;gotoxy(8,22); 
            break; 
        }  
    }
        for (l = p; l > 0; l--)
        {
            for (c = position; c < 7; c++)
            {
                if (m.Mat[l][c] == symbole)
                {
                    compt++;
                    position += 1;
                    break;
                }           
                if (m.Mat[l][c] != symbole) compt=0;
            }
            if (compt == 4 && jou1.symbole==symbole)
            {
                gotoxy(8,27);printf("Victoire sur la Diagonale Droite Vers le Haut de %s " , jou1.nom);
                return 1; 
                break;
            }
            if (compt == 4 && jou2.symbole == symbole)
            {
                gotoxy(8,27);printf("Victoire sur la Diagonale Droite Vers le Haut  de %s " , jou2.nom);
                return 1;
                break;
            }
        }
    
    //Diagonale haut Gauche
    compt = 0;
    position = d;

    for (l = 0; l < 6; l++)
    {
        if (m.Mat[l][position] == symbole)
        {
            p = l;
            c = position;gotoxy(8,22); 
            break; 
        }  
    }
        for(l = p; l > 0 ; l--)
        {
            for (c = position; c > 0; c--)
            {
                if (m.Mat[l][c] == symbole)
                {
                   compt++;
                   position -= 1;
                   break; 
                }    
            }
            if (compt == 4 && jou1.symbole==symbole)
            {
                gotoxy(8,27);printf("Victoire sur la Diagonale Gauche Vers le Haut de %s " , jou1.nom);
                return 1;
                break;
            }
            if (compt == 4 && jou2.symbole == symbole)
            {
                gotoxy(8,27);printf("Victoire sur la Diagonale Gauche Vers le Haut de %s " , jou2.nom);
                return 1;
                break;
            }
        }   
return 0;
}

int main ()
{
    grille4puissance();
    return 0;
}