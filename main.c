#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

void clrscr()
{
  system("cls");
}
void Color(int t,int f)
{
	HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H,f*16+t);
}
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
void grille4puissance()
{
    int a=0; int b=0; int newx=0;int collone=0;int compt=0; int col=7;int lon=49; int ligne=0;int l=0;int j=1;int newy=0; int i;int x=8; int y=8; int haut=2;
     gotoxy(x,y); printf("%c",218);
     gotoxy(x+lon,y); printf("%c",191);
   if(ligne==0){
     for (i=1; i<lon;i++)
     {
         gotoxy(x+i,y); printf("%c",196);
         gotoxy(x+i,y+haut); printf("%c",196); compt++;
         if(col==compt)
            {l=l+col;
            gotoxy(x+l-3,y-1);printf(" %d", collone);
            gotoxy(x+i,y); printf("%c",194);
            gotoxy(x+i,y+haut); printf("%c",197);compt=0;     collone++;
            }
     }         l=l+col;
      gotoxy(x+l-3,y-1);printf("6"); gotoxy(x,y+haut); printf("%c",179);   gotoxy(x+lon,y+haut); printf("%c",179);
      newx=col;compt=0;
         do{
             for (i=1; i<haut;i++){
         gotoxy(x,y+i); printf("%c",179);
         gotoxy(x+newx,y+i); printf("%c",179);
     }
     newx=newx+col;compt++;
          }while  (compt<col) ;}
        do{
            if(ligne>0 && ligne<5){
                newx=col;compt=0;newy=b*haut+y;
         for(compt=0;compt<col;compt++){
             for (i=1; i<haut;i++)
     {
         gotoxy(x,newy+i); printf("%c",179);
         gotoxy(x+newx,newy+i); printf("%c",179);

     }
        newx=newx+col;
          }
        do{
         gotoxy(x+j,newy+haut); printf("%c",196);a++;
                  if(col==a){
                gotoxy(x+j,newy+haut); printf("%c",197); a=0;
         }
         j++;
        }while(j<lon);j=1;a=0;
               gotoxy(x,newy+haut); printf("%c",179); gotoxy(x+lon,newy+haut); printf("%c",179);
        }
        if(ligne<5){printf("%d", ligne);}
        ligne++;b++;
        }while(ligne<7);     newy=5*haut+y;
        if(ligne==7){ compt=0;
        gotoxy(x, newy+haut); printf("%c",192);
        gotoxy(x+lon, newy+haut); printf("%c",217);printf("5");
        for (i=1; i<lon;i++)
     {
         gotoxy(x+i,newy+haut); printf("%c",196); compt++;
         if(col==compt){
            gotoxy(x+i,newy+haut); printf("%c",193);
            compt=0;
         }
     }
     newx=col;compt=0;
         do{
             for (i=1; i<haut;i++)
     {
         gotoxy(x,newy+i); printf("%c",179);
         gotoxy(x+newx,newy+i); printf("%c",179);
     }
     newx=newx+col;
     compt++;
          }while  (compt<col) ;
     }
}



typedef struct Matrice Matrice ;

    struct Matrice {

    char mat[6][7];

    };

typedef struct Joueur Joueur ;

    struct Joueur {

    char joueur[100];
    char symbole;

    };
Joueur j1, j2;Matrice m;
void jouer_colonne(int tour, int position){

    int l,col=0;int newy=7;int newx=13;int a=position+1;int y=0;int c=4;
       char t;   int b=0;

   if(tour==1){Color(2,0);
   while(col!=position){
                newx=newx+7;
                col++;}
                  if(m.mat[5][position]!='x' && m.mat[5][position]!='o' ){b=0;

              for(l=0;l<6;l++){

                if(m.mat[l][position]!='x' && m.mat[l][position]!='o' ){
                    newy=newy+2;

                }
                 if( l==5){

                        m.mat[5][position]=j1.symbole; gotoxy(newx-1,newy);printf("%c",m.mat[l][position]);}

                }
                }else{ if(m.mat[0][position]!='x' && m.mat[0][position]!='o'){
                     for(l=0;l<6;l++){

                if(m.mat[l][position]!='x' && m.mat[l][position]!='o' ){
                    newy=newy+2;

                }
                 if(m.mat[l][position]=='x' || m.mat[l][position]=='o'  ){
         if(m.mat[l-1][position]!='x' && m.mat[l-1][position]!='o'  ){  m.mat[l-1][position]=j1.symbole; gotoxy(newx-1,newy);printf("%c",m.mat[l-1][position]);gotoxy(8,23);/*printf("cesr%c",m.mat[0][position]);*/}}
                   }
}  }

                }


   if(tour==2){Color(6,0);
            while(col!=position){newx=newx+7;col++;}
                 if(m.mat[5][position]!='x' && m.mat[5][position]!='o' ){

           for(l=0;l<6;l++){
                if(m.mat[l][position]!='x' && m.mat[l][position]!='o' ){
                    newy=newy+2;

                }
                   if( l==5 ){

                        m.mat[5][position]=j2.symbole;gotoxy(newx-1,newy);printf("%c",m.mat[l][position]);
                }}}
                    else{ if(m.mat[0][position]!='x' && m.mat[0][position]!='o'){
                              for(l=0;l<6;l++){

                if(m.mat[l][position]!='x' && m.mat[l][position]!='o' ){
                    newy=newy+2;

                }
                   if(m.mat[l][position]=='x' || m.mat[l][position]=='o'  ){  if(m.mat[l-1][position]!='x' && m.mat[l-1][position]!='o'  ){
                        m.mat[l-1][position]=j2.symbole;gotoxy(newx-1,newy);printf("%c",m.mat[l-1][position]);

                    }}

            }



   }   }

   }
}

   int verif_gain(char symbole , int position){
Color(7,0);
   int l; int compt=0; int x=38; int y=22; int x2=55; int c=0;int p=0; int d=position;
//Verticale
   for(l=0;l<6;l++){

    if(m.mat[l][position]==symbole ){
        compt++;


    }           if(m.mat[l][position]!=symbole){compt=0;}
                if(compt==4 && j1.symbole==symbole){gotoxy(8,27);printf("Victoire sur la Verticale de %s " , j1.joueur);return 1 ;break;}
                if(compt==4 && j2.symbole==symbole){gotoxy(8,27);printf("Victoire sur la Verticale de %s " , j2.joueur);return 1 ;break;}


   }
   //Horizontale
compt=0;
        for(l=0;l<6;l++){

        for(c=0;c<7;c++){
            if(m.mat[l][c]==symbole ){
                compt++;

    }           if(m.mat[l][c]!=symbole){compt=0;}
                if(compt>=4 && j1.symbole==symbole){gotoxy(8,27);printf("Victoire sur l'Horizontale de %s " , j1.joueur);return 1 ;break;}
                if(compt>=4 && j2.symbole==symbole){gotoxy(8,27);printf("Victoire sur l'Horizontale de %s " , j2.joueur);return 1 ;break;}

        }}
// Diagonale Bas gauche
        compt=0;

         for(l=0;l<6;l++){

    if(m.mat[l][position]==symbole ){
            p=l;c=position;gotoxy(8,22);if(m.mat[p-1][position+1]==symbole ){compt++;if(p-1<0 || position+1 >6){compt=0;}} break; }  }
        for(l=p;l<6;l++){

        for(c=position;c>=0;c--){
            if(m.mat[l][c]==symbole ){
                compt++;position=position-1;  break;

    } if(m.mat[l][c]!=symbole){compt=0;position=position-1;  break;}


        }
        if(compt>=4 && j1.symbole==symbole){gotoxy(8,27);printf("Victoire sur la Diagonale Gauche Vers le Bas de %s " , j1.joueur);return 1 ;break;}
                if(compt>=4 && j2.symbole==symbole){gotoxy(8,27);printf("Victoire sur la Diagonale Gauche vers le Bas de %s " , j2.joueur);return 1 ;break;}
        }
//Diagonale Bas Droite
          compt=0;position=d;

         for(l=0;l<6;l++){

    if(m.mat[l][position]==symbole ){
            p=l;c=position;gotoxy(8,22);  if(m.mat[p-1][position-1]==symbole ){compt++;if(p-1<0 || position-1<0){compt=0;}} break; }  }
        for(l=p;l<6;l++){

        for(c=position;c<7;c++){
            if(m.mat[l][c]==symbole ){
                compt++;position=position+1;           break;

    }if(m.mat[l][c]!=symbole){compt=0;position=position+1;break;}


        }
        if(compt>=4 && j1.symbole==symbole){gotoxy(8,27);printf("Victoire sur la Diagonale Droite Vers le Bas de %s " , j1.joueur);return 1 ;break;}
                if(compt>=4 && j2.symbole==symbole){gotoxy(8,27);printf("Victoire sur la Diagonale Droite Vers le Bas de %s " , j2.joueur);return 1 ;break;}
        }
//Diagonale haut Droite
            compt=0;position=d;

         for(l=0;l<6;l++){

    if(m.mat[l][position]==symbole ){
            p=l;c=position;gotoxy(8,22); if(m.mat[p+1][position-1]==symbole ){compt++;if(p+1>5 || position-1 <0){compt=0;}} break; }  }
        for(l=p;l>=0;l--){

        for(c=position;c<7;c++){
            if(m.mat[l][c]==symbole ){
                compt++;position=position+1; break;
    }if(m.mat[l][c]!=symbole){compt=0;position=position+1; break;}


        }
        if(compt>=4 && j1.symbole==symbole){gotoxy(8,27);printf("Victoire sur la Diagonale Droite Vers le Haut de %s " , j1.joueur);return 1 ; break;}
                if(compt>=4 && j2.symbole==symbole){gotoxy(8,27);printf("Victoire sur la Diagonale Droite Vers le Haut  de %s " , j2.joueur);return 1 ;break;}
        }

//Diagonale haut Gauche
            compt=0;position=d;

         for(l=0;l<6;l++){

    if(m.mat[l][position]==symbole ){
            p=l;c=position;gotoxy(8,22);if(m.mat[p+1][position+1]==symbole ){compt++;if(p+1>5 || position+1 >6){compt=0;}} break; }  }
        for(l=p;l>=0;l--){

        for(c=position;c>=0;c--){
            if(m.mat[l][c]==symbole ){
                compt++;position=position-1; break;
                }if(m.mat[l][c]!=symbole){compt=0;position=position-1;break;}


        }
        if(compt>=4 && j1.symbole==symbole){gotoxy(8,27);printf("Victoire sur la Diagonale Gauche Vers le Haut de %s " , j1.joueur);return 1;break;}
                if(compt>=4 && j2.symbole==symbole){gotoxy(8,27);printf("Victoire sur la Diagonale Gauche Vers le Haut de %s " , j2.joueur);return 1 ;break;}
        }
        compt=0;
for(c=0;c<7;c++){
    if(m.mat[0][c]=='x' || m.mat[0][c]=='o' ){compt++;} if(compt==7){gotoxy(8,27);printf("Matche Null entre %s et %s " , j1.joueur , j2.joueur);return 1;}

}


return 0;
   }

void init_jeu(){
     char p1 ; char p2;int verif=0; int taille; int tour;int victoire=0;

        gotoxy(8,22);printf("Nom Joueur 1:");
        gotoxy(8,23);printf("Nom Joueur 2:");
        gotoxy(22,22); scanf("%s", j1.joueur);
        gotoxy(22,23);scanf("%s", j2.joueur);
                    srand(time(NULL)); int random = 1 + rand() % 2;
        do{

        if(random==1){
                 gotoxy(8,24);printf("C'est  %s qui commence.", j1.joueur);
        gotoxy(8,25);printf("%s choisi ton symbole (x/o):", j1.joueur);taille = strlen(j1.joueur);
        gotoxy(37+taille,25);scanf(" %c", &j1.symbole);
        } else{
                             gotoxy(8,24);printf("C'est  %s qui commence.", j2.joueur);
         gotoxy(8,25);printf("%s choisi ton symbole (x/o):", j2.joueur);taille = strlen(j2.joueur);
        gotoxy(37+taille,25);scanf(" %c", &j2.symbole);
        }

        if(j1.symbole!='x' && j1.symbole!='o'&& j2.symbole!='x' && j2.symbole!='o'){
            gotoxy(8,26);printf("Erreur choisi ton symbole (x/o)");
        }else{verif=1;if(j1.symbole=='x'){j2.symbole='o';}if(j1.symbole=='o'){j2.symbole='x';}if(j2.symbole=='x'){j1.symbole='o';}if(j2.symbole=='o'){j1.symbole='x';}}
        }while(verif==0);
        clrscr();grille4puissance();

        gotoxy(80,8);printf("JEU DE PUISSANCE 4");
        gotoxy(80,12);printf("Symbole de %s  : %c" , j1.joueur, j1.symbole);
        gotoxy(80,13);printf("Symbole de %s  : %c" , j2.joueur , j2.symbole);


             tour=random;int position1 ,position2;
            do{
               if(tour==1 && victoire!=1){Color(7,0); gotoxy(80,17);printf("C'est  %s qui joue.", j1.joueur);
               do{ gotoxy(8,27);printf("  %s Entre une position valide:", j1.joueur); gotoxy(38+taille,27);scanf("%d", &position1);    while(getchar() != '\n');
               if(position1>6){gotoxy(80,27);printf("  %s %d est une position invalide", j1.joueur ,position1); }
                if(m.mat[0][position1]=='x' ||  m.mat[0][position1]=='o'){gotoxy(80,25);printf(" La collonne  %d est pleine ", position1);  }
               }while(position1<0 ||position1>6 || m.mat[0][position1]=='x' ||  m.mat[0][position1]=='o');
               jouer_colonne(tour,position1);victoire=verif_gain(j1.symbole,position1);tour=2;Color(7,0);}

                if(tour==2 && victoire!=1){Color(7,0); gotoxy(80,17);printf("C'est  %s qui joue.", j2.joueur);
                 do{ gotoxy(8,27);printf("  %s Entre une position valide:", j2.joueur); gotoxy(38+taille,27);scanf("%d", &position2);    while(getchar() != '\n');
                  if(position2>6){gotoxy(80,28);printf("  %s %d est une position invalide", j2.joueur ,position2); }
                if(m.mat[0][position2]=='x' ||  m.mat[0][position2]=='o'){gotoxy(80,25);printf(" La collonne  %d est pleine ", position2);  }

               }while(position2<0 ||position2>6 || m.mat[0][position2]=='x' ||  m.mat[0][position2]=='o');
                 jouer_colonne(tour,position2);victoire=verif_gain(j2.symbole,position2);tour=1;Color(7,0);}
//A modifier ajout d'une verification si position depasse 6 Ajout d'un message qui dira si la derniere case est pleine de jouer ailleur


             }while(victoire!=1 );

Color(7,0);

}



int main()
{

   grille4puissance();init_jeu();
   gotoxy(58,4);printf("FIN DU JEU\n");
  getchar();



    return 0;
}
