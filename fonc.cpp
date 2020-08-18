#include<iostream>
#include<fstream>
#include"fonc.h"
#include<stdlib.h>
using namespace std;
/////////////////////////////////////contructeur//////////////////////////////////
//il prond en parametre la taille du tablier
//il remplie dabord la premiere moitie apres il commence l'autre moitie
tablier::tablier(int e)
{
 int x=0;
 int i;int j;
 taille=e*4-3;//j'ai fait ça pour l'affichage je laisse une case vide l'autre j'ecris desus
 tab=new int*[(taille+1)/2];
 ////////////creation de la matrice///////////////////
 for(i=0;i<(taille+1)/2;i++)
  tab[i]=new int[taille];
  ////////////////remlissage de la premiere partie du tablier////////////////
 for(i=0;i<=taille/4;i++)
  {for(j=taille/4-x;j<(taille-taille/4+x);j=j+2)
         {tab[i][j]=-1;
           nbcases++;///conter le nombre de cases du tablier
         }        
   x++;
  }
 x=x-2;
  ////////////////remlissage de la deuxieme partie du tablier////////////////
 for(i=(taille/4)+1;i<(taille+1)/2;i++)
 {for(j=taille/4-x;j<(taille-taille/4+x);j=j+2)
      {
        tab[i][j]=-1;
        nbcases++;///conter le nombre de cases du tablier        
      }x--;
 }
}
/////////////////////////////////////affichage du teblier////////////////////////////
void tablier::affichage()
{clrscr();  //pour l'affichage en haut
 cout<<"        0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29"<<endl<<endl;
 for(int i=0;i<(taille+1)/2;i++)
 {
   if(i<10)cout<<"     "<<i<<"  ";else cout<<"    "<<i<<"  ";
  for(int j=0;j<taille;j++)
  {
    if (tab[i][j]==-1) cout<<"*"<<"  ";
    else if (tab[i][j]==j1) {cout << "\033[0;"<<j1<<"m"<<" "<<"\033[0m";;cout<<"  ";;}
    else if (tab[i][j]==j2) {cout << "\033[0;"<<j2<<"m"<<" "<<"\033[0m";;cout<<"  ";;}
    else if (tab[i][j]==j3) {cout << "\033[0;"<<j3<<"m"<<" "<<"\033[0m";;cout<<"  ";;}
    else  cout<<"   ";
  }
   cout<<"   "<<endl;cout<<"   "<<endl;cout<<"   "<<endl;
 }
}
///////////////////////jouer a deux////////////////////
void tablier::deuxj()
{
  int gagne,i,j;/////(gagne) c'est le nombre de cases deja jouer 
  affichage();
 do
 {  
   cout<<"le joueur 1 doit choisir une couleur"<<endl;
   cout<<"blanc:7"<<endl;cout<<"gris:40"<<endl;
   cout<<"rouge:41"<<endl;cout<<"vert:42"<<endl;
   cout<<"jaune:43"<<endl;cout<<"bleu:44"<<endl;
   cout<<"violet:45"<<endl;
     
     cin>>j1;
   
   if(j1!=7 && j1!=40 && j1!=41 && j1!=42 && j1!=43 && j1!=44 && j1!=45)
   cout<<"vous n'avez pas choisi le bon chiffre"<<endl;
  }while(j1!=7 && j1!=40 && j1!=41 && j1!=42 && j1!=43 && j1!=44 && j1!=45);
  
  affichage();

  do
  {
   cout<<"le joueur 2 doit choisir une couleur"<<endl;
   cout<<"blanc:7"<<endl;cout<<"gris:40"<<endl;
   cout<<"rouge:41"<<endl;cout<<"vert:42"<<endl;
   cout<<"jaune:43"<<endl;cout<<"bleu:44"<<endl;
   cout<<"violet:45"<<endl;
   
   cin>>j2;

   if(j2!=7 && j2!=40 && j2!=41 && j2!=42 && j2!=43 && j2!=44 && j2!=45)
   cout<<"vous n'avez pas choisi le bon chiffre"<<endl;
   if(j1==j2)
   cout<<"vous avez choisi la meme couleur que le joueur 1"<<endl;
  }while(j2==j1||(j2!=7 && j2!=40 && j2!=41 && j2!=42 && j2!=43 && j2!=44 && j2!=45));

  
 affichage();

  while(gagne!=-1 && gagne<=nbcases)//si personne n'a gagner et il reste des cases libre
  {do
   {
     cout<<"c'est au tour du joueur 1 donner les coordoner de la case(num de la ligne apres le numero de la colonne)"<<endl;
     cin>>i;
     cin>>j;
    }while(tab[i][j]!=-1);

    tab[i][j]=j1;///le joueur 1 a jouer

    gagne++;///incrementer le nombre de cases jouer

    affichage();
      //////////tester si le joueur 1 a gagner
    if(gagner(j1)) {cout<<"le joueur 1 a gagner"<<endl;gagne=-1;}

    if(gagne!=-1 && gagne<=nbcases)///si le joueur 1 n'a pas gagner et il reste des cases libre
    {do
     {
       cout<<"c'est au tour du joueur 2 donner les coordoner de la case(num de la ligne apres le numero de la colonne)"<<endl;
       cin>>i;
       cin>>j;
     }while(tab[i][j]!=-1);

     tab[i][j]=j2;///le joueur 2 a jouer
     
     gagne++;///incrementer le nombre de cases jouer

           //////////tester si le joueur 1 a gagner
     if(gagner(j2)) {cout<<"le joueur 2 a gagner"<<endl;gagne=-1;}
     
      affichage();
    }
    if (nbcases==gagne)///plus de cases vide et personne ne gagne
    {
      cout<<"match nulle";
    }
  }
}
//////////////////////////////////////////////////////////////////////////////////////
void tablier::troisj()
{
  int gagne,i,j;/////(gagne) c'est le nombre de cases deja jouer sur le nombre de cqses totale
  affichage();
 do
 {
   cout<<"le joueur 1 doit choisir une couleur"<<endl;
   cout<<"blanc:7"<<endl;cout<<"gris:40"<<endl;
   cout<<"rouge:41"<<endl;cout<<"vert:42"<<endl;
   cout<<"jaune:43"<<endl;cout<<"bleu:44"<<endl;
   cout<<"violet:45"<<endl;
   
   cin>>j1;

   if(j1!=7 && j1!=40 && j1!=41 && j1!=42 && j1!=43 && j1!=44 && j1!=45)
   cout<<"vous n'avez pas choisi le bon chiffre"<<endl;
  }while(j1!=7 && j1!=40 && j1!=41 && j1!=42 && j1!=43 && j1!=44 && j1!=45);
  
  affichage();
  
  do
  {
   cout<<"le joueur 2 doit choisir une couleur"<<endl;
   cout<<"blanc:7"<<endl;cout<<"gris:40"<<endl;
   cout<<"rouge:41"<<endl;cout<<"vert:42"<<endl;
   cout<<"jaune:43"<<endl;cout<<"bleu:44"<<endl;
   cout<<"violet:45"<<endl;
   
   cin>>j2;

   if(j2!=7 && j2!=40 && j2!=41 && j2!=42 && j2!=43 && j2!=44 && j2!=45)
   cout<<"vous n'avez pas choisi le bon chiffre"<<endl;
   if(j1==j2)
   cout<<"vous avez choisi la meme couleur que le joueur 1"<<endl;
  }while(j2==j1||(j2!=7 && j2!=40 && j2!=41 && j2!=42 && j2!=43 && j2!=44 && j2!=45));
  
  affichage();

   do
  {
   cout<<"le joueur 3 doit choisir une couleur"<<endl;
   cout<<"blanc:7"<<endl;cout<<"gris:40"<<endl;
   cout<<"rouge:41"<<endl;cout<<"vert:42"<<endl;
   cout<<"jaune:43"<<endl;cout<<"bleu:44"<<endl;
   cout<<"violet:45"<<endl;
   
   cin>>j3;

   if(j3!=7 && j3!=40 && j3!=41 && j3!=42 && j3!=43 && j3!=44 && j3!=45)
   cout<<"vous n'avez pas choisi le bon chiffre"<<endl;
   if(j1==j3||j2==j3)
   cout<<"la couleur a deja etait choisit"<<endl;
  }while((j3==j1)||(j3==j2)||((j2!=7)&&(j2!=40)&&(j2!=41)&&(j2!=42)&&(j2!=43)&&(j2!=44)&&(j2!=45)));
  
  affichage();
  
  while(gagne!=-1 && gagne<=nbcases)//si personne n'a gagner et il reste des cases libre
  {do
   {
     cout<<"c'est au tour du joueur 1 donner les coordoner de la case(num de la ligne apres le numero de la colonne)"<<endl;
     cin>>i;
     cin>>j;
    }while(tab[i][j]!=-1);
    tab[i][j]=j1;
    gagne++;
    affichage();
    if(gagner(j1)) {cout<<"le joueur 1 a gagner"<<endl;gagne=-1;}
    
    if(gagne!=-1 && gagne<=nbcases)
    {do
     {
       cout<<"c'est au tour du joueur 2 donner les coordoner de la case(num de la ligne apres le numero de la colonne)"<<endl;
       cin>>i;
       cin>>j;
     }while(tab[i][j]!=-1);
     tab[i][j]=j2;
     gagne++;
     if(gagner(j2)) {cout<<"le joueur 2 a gagner"<<endl;gagne=-1;}
      affichage();
    }

    if(gagne!=-1 && gagne<=nbcases)
    {do
     {
       cout<<"c'est au tour du joueur 3 donner les coordoner de la case(num de la ligne apres le numero de la colonne)"<<endl;
       cin>>i;
       cin>>j;
     }while(tab[i][j]!=-1);
     tab[i][j]=j3;
     gagne++;
     if(gagner(j3)) {cout<<"le joueur 3 a gagner"<<endl;gagne=-1;}
      affichage();
    }
    if (nbcases==gagne)
    {
      cout<<"match nulle";
    }
  }
}
//////////////////////////////////////////////////////////////////////////////////////

bool tablier::gagner(int x)
{
 if(fourche(x)) return true;///tester la fourche
 if(anneau(x)) return true;///tester l'anneau
 if(pont(x)) return true;///tester le pont
 return false;
}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////PONT///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
bool tablier::pont(int a)
{
 ///voir si il y'a au moins un coins jouer par le joueur a 
  if(tab[0][(taille-1)/4]==a)///si le coin haut gauche a ete jouer par le joueur a
   if(testerpont(0,(taille-1)/4,(taille-1)/4,a))
    return true;
 n=-1;
  if(tab[0][(taille-1)-(taille-1)/4]==a)///si le coin haut droite a ete jouer par le joueur a
   if(testerpont(0,(taille-1)-(taille-1)/4,(taille-1)-(taille-1)/4,a))
    return true;
 n=-1;
  if(tab[(taille-1)/4][0]==a)///si le coin gauche a ete jouer par le joueur a
   if(testerpont((taille-1)/4,0,100*(taille-1)/4,a))
    return true;
 n=-1;
  if(tab[(taille-1)/4][taille-1]==a)///si le coin droite a ete jouer par le joueur a
   if(testerpont(taille/4,taille-1,100*((taille-1)/4)+(taille-1),a))
    return true;
 n=-1;
  if(tab[taille/2][taille/4]==a)///si le coin bas gauche a ete jouer par le joueur a
   if(testerpont(taille/2,(taille-1)/4,100*(taille/2)+(taille-1)/4,a))
    return true;
 n=-1;
  if(tab[(taille-1)/2][(taille-1)-(taille-1)/4]==a)///si le coin bas droite a ete jouer par le joueur a
   if(testerpont((taille-1)/2,(taille-1)-(taille-1)/4,100*((taille-1)/2)+(taille-1)-(taille-1)/4,a))
    return true;
 n=-1;
    return false;
}
//////////////////////////////////////////////////////////////////////////////////////
bool tablier::testerpont(int i,int j,int p,int a)
{
 ///esce que on est arriver a un coin autre que celui envoyer en parametre
 if(((i==0 && j==(taille-1)-(taille-1)/4)||(i==taille/2 && j==(taille-1)/4)||(i==taille/2 && j==taille-1-(taille-1)/4)||(i==(taille-1)/4 && j==taille-1)||(i==(taille-1)/4 && j==0)||(i==0 && j==(taille-1)/4)) && ((i*100+j)!=p)) 
 return true;
 ///esce que on est arriver a un coin autre que celui envoyer en parametre  
 enregitrerlacase(i,j);///pour pas revinir sur elle (boucle infini)
 i--;
 j--;
 ///visiter le frere haut gauche
 if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
  if(tab[i][j]==a && !visiter(i,j))///et la case a ete jouer par le joueur a et elle n'est pas deja enregistrer
   if(testerpont(i,j,p,a))///recurtion
     return true;
 j=j+2;
 ///visiter le frere haut droit
 if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
  if(tab[i][j]==a && !visiter(i,j))///et la case a ete jouer par le joueur a et elle n'est pas deja enregistrer
   if(testerpont(i,j,p,a))///recurtion
     return true;
 i++;
 j++;
 ///visiter le frere droit 
 if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
  if(tab[i][j]==a && !visiter(i,j))///et la case a ete jouer par le joueur a et elle n'est pas deja enregistrer
   if(testerpont(i,j,p,a))///recurtion
     return true;
 j--;
 i++;
 ///visiter le frere bas droit
 if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
  if(tab[i][j]==a && !visiter(i,j))///et la case a ete jouer par le joueur a et elle n'est pas deja enregistrer
   if(testerpont(i,j,p,a))///recurtion
     return true;
 j=j-2;
 ///visiter le frere bas gauche
 if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
  if(tab[i][j]==a && !visiter(i,j))///et la case a ete jouer par le joueur a et elle n'est pas deja enregistrer
   if(testerpont(i,j,p,a))///recurtion
     return true;
 i--;
 j--;
 ///visiter le frere gauche
 if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
  if(tab[i][j]==a && !visiter(i,j))///et la case a ete jouer par le joueur a et elle n'est pas deja enregistrer
   if(testerpont(i,j,p,a))///recurtion
     return true;
 return false;

}
////////////////////////////visiter///////////////////////////////////////////////////
bool tablier::visiter(int i,int j)
{
  bool b=false;
  ///chercher dans le tableau si la case a deja ete sauvegarder
 for(int k=0;k<=n;k++)
 {
  if(visite[k]%100==j && visite[k]/100==i)
  b=true;
 }
 return b;
}
//////////////////////////////enregitrer la case//////////////////////////////////////
void tablier::enregitrerlacase(int i,int j)
{
 n++;
 visite[n]=(j+i*100);
}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////ANNEAU///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
bool tablier::anneau(int a)
{
  ///verifier toute les cases jouer pour voir si y'a un anneau
 for(int i=0;i<(taille+1)/2;i++)
 {for(int j=0;j<taille;j++)
   {
     if(tab[i][j]==a)
      if(testeranneau(i,j,i*100+j,0,a,1))
         return true;
    n=-1;
   }
 }return false;
}
//////////////////////////////////////////////////////////////////////////////////////
bool tablier::testeranneau(int i,int j,int p,int vers,int a,int tour)
{
  ///pour faire anneau il faut deux chose:
  ///six deplacement au moins
  ///revenir au point de depart
 if(tour>=7 && i*100+j==p)
 return true;
 enregitrerlacase(i,j);
 //frere haut gauche:vers=1
 //frere gauche:vers=2
 //frere bas gauche:vers=3
 //frere bas droit:vers=4
 //frere droit:vers=5
 //frere haut droit:vers=6
 if(tour==1)///au debut en commence en recherchons sur le quatre premier frere au choix
  //au debut on test 4 frere cote a cote
  //ensuite parapport au frere qu'on a choisi on continu soit tout droit ou le frere le plus pret a sa gauche ou a sa droite
 {tour++;
   j=j-2;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))///si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour 
     if(testeranneau(i,j,p,2,a,tour))//recurtion
       return true;
   j++;
   i++;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))///si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour 
     if(testeranneau(i,j,p,3,a,tour))//recurtion
       return true;
   j=j+2;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))///si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour 
     if(testeranneau(i,j,p,4,a,tour))//recurtion
       return true;
   i--;
   j++;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))///si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour 
     if(testeranneau(i,j,p,5,a,tour))//recurtion
       return true;
  return false;
 }

 if(vers==2)
 {tour++;
  i--;
  j--;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))///si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour 
     if(testeranneau(i,j,p,1,a,tour))//recurtion
       return true;
     i++;
     j--;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,2,a,tour))//recurtion
       return true;
     i++;
     j++;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,3,a,tour))//recurtion
       return true;
    return false;
 }
 if(vers==3)
 {tour++;
  j=j-2;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,2,a,tour))//recurtion
       return true;
     i++;
     j++;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,3,a,tour))//recurtion
       return true;
     j=j+2;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,4,a,tour))//recurtion
       return true;
     return false;
 }
 if(vers==4)
 {tour++;
  i++;
  j--;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,3,a,tour))//recurtion
       return true;
     j=j+2;;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,4,a,tour))//recurtion
       return true;
     i--;
     j++;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,5,a,tour))//recurtion
       return true;
  return false;
 }

 if(vers==5)
 {tour++;
  i++;
  j++;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,4,a,tour))//recurtion
       return true;
     i--;
     j++;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,5,a,tour))//recurtion
       return true;
     i--;
     j--;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,6,a,tour))//recurtion
       return true;
  return false;
 }

 if(vers==6)
 {tour++;
  j=j+2;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,5,a,tour))//recurtion
       return true;
     i--;
     j--;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,6,a,tour))//recurtion
       return true;
     j=j-2;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,1,a,tour))//recurtion
       return true;
     return false;
 }

  if(vers==1)
 {tour++;
  i--;
  j++;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,6,a,tour))//recurtion
       return true;
     j=j+2;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,1,a,tour))//recurtion
       return true;
     i++;
     j--;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))///on n'est pas sorti de la matrice 
    if(tab[i][j]==a&&(!visiter(i,j)||(i*100+j==p)))//si la corespond au joueur a elle n'est pas encore visiter ou ont a fait un tour
     if(testeranneau(i,j,p,2,a,tour))//recurtion
       return true;
     return false;
 }
}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////FOURCHE//////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

bool tablier::fourche(int a)
{
 //pour la fourche je cherche si il y'a un coté qui a ete marqué par le joueur a
  int x=0;
 for(int j=(((taille-1)/4)+2);j<((taille-1)-(taille-1)/4);j=j+2)//chercher sur le coté en haut 
  {if(tab[0][j]==a)
   {if(testerfourche(0,j,j,a,0))
     return true;
     k=-1;n=-1;
   }else if(tab[(taille-1)/2][j]==a) //chercher sur le coté en bas
          if(testerfourche((taille-1)/2,j,(taille-1)/2*100+j,a,0))
           return true;
   n=-1;k=-1;//renetialiser les tableaux
 } 
  //chercher sur les autre coté 
 for(int j=1;j<(taille-1)/4;j++)
  {x=x+1;
  if(tab[(taille-1)/4-x][j]==a)
   if(testerfourche((taille-1)/4-x,j,((taille-1)/4-x)*100+j,a,0))
     return true;
     n=-1;k=-1;
  if(tab[(taille-1)/4+x][j]==a)
   if(testerfourche((taille-1)/4+x,j,((taille-1)/4+x)*100+j,a,0))
     return true;
     n=-1;k=-1;}x=0;//renetialiser les tableaux 
 for(int j=taille-2;j>(taille-1)-(taille-1)/4;j--)
  {x=x+1;
  if(tab[(taille-1)/4-x][j]==a)
   if(testerfourche((taille-1)/4-x,j,((taille-1)/4-x)*100+j,a,0))
     return true;
     k=-1;n=-1;//renetialiser les tableaux
   if(tab[(taille-1)/4+x][j]==a)
     if(testerfourche((taille-1)/4+x,j,((taille-1)/4+x)*100+j,a,0))
           return true;
  n=-1;k=-1;  }n=-1;k=-1;//renetialiser les tableaux 
 return false;
}
//////////////////////////////////////////////////////////////////////////////////////
bool tablier::testerfourche(int i,int j,int p,int a,int y)
{
 //là la fonction elle enregistre un cote pour qu'il soit plus accessible et elle increment le y
 //apres elle cherche un autre point jouer dans un autre coté 
 //et quand elle le trouve elle enregistre le cote et vide le tableau de cases visiter et incremente le y
 //et recommence la recherche jusqu'a ce que en touche 3 coté 
  int x=0;
  if((i==(taille-1)/2 && j<(taille-1)-(taille-1)/4 && j>(taille-1)/4 && !encote(i,j))||(!encote(i,j) && i==0 && j<(taille-1)-(taille-1)/4 && j>(taille-1)/4))
   {enregitrerlecote(i,j);y++;n=-1;}
  else 
  {
    for(int z=1;z<(taille-1)/4;z++)
      {x++;
        if((i==(taille-1)/4-x && j==z && !encote(i,j))||((taille-1)/4+x==i && j==z && !encote(i,j)))
          {enregitrerlecote(i,j);y++;n=-1;z=(taille-1)/4;}
      }x=0;
    for(int z=taille-2;z>((taille-1)-(taille-1)/4);z--)
      {x++;
        if((i==(taille-1)/4-x && j==z && !encote(i,j))||((taille-1)/4+x==i && j==z && !encote(i,j)))
         {enregitrerlecote(i,j);y++;n=-1;z=((taille-1)-(taille-1)/4);}
      }
 }
 if(y==3)
  return true;
  enregitrerlacase(i,j);
  i--;
  j--;
 ///visiter le frere haut gauche
  if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1))  
   if(tab[i][j]==a && !visiter(i,j) && !encote(i,j))
    if(testerfourche(i,j,p,a,y))
      return true;
  j=j+2;
   ///visiter le frere haut droit
  if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1)) 
   if(tab[i][j]==a && !visiter(i,j) && !encote(i,j))
    if(testerfourche(i,j,p,a,y))
      return true;
  i++;
  j++;
   ///visiter le frere droit
  if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1)) 
   if(tab[i][j]==a && !visiter(i,j) && !encote(i,j))
    if(testerfourche(i,j,p,a,y))
      return true;
  j--;
  i++;
   ///visiter le frere bas droit
  if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1)) 
   if(tab[i][j]==a && !visiter(i,j) && !encote(i,j))
    if(testerfourche(i,j,p,a,y))
      return true;
  j=j-2;
   ///visiter le frere bas gauche
  if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1)) 
   if(tab[i][j]==a && !visiter(i,j) && !encote(i,j))
    if(testerfourche(i,j,p,a,y))
      return true;
  i--;
  j--;
   ///visiter le frere gauche
  if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1)) 
   if(tab[i][j]==a && !visiter(i,j) && !encote(i,j))
    if(testerfourche(i,j,p,a,y))
      return true;
 return false;
}
//////////////////////////////////////////////////////////////////////////////////////
void tablier::enregitrerlecote(int i,int j)
{
  if(i==0)
 {for(int v=((taille-1)/4)+2;v<(taille-1)-(taille-1)/4;v=v+2)
   {k++;
    cote[k]=v;   
   }
 }
 if(i==(taille-1)/2)
  {for(int v=((taille-1)/4)+2;v<(taille-1)-(taille-1)/4;v=v+2)
    {k++;
      cote[k]=v+i*100;   
    }
  }
   if(j<(taille-1)/4 && j>0 && i<(taille-1)/4)
    {int x=0;
     for(int j=1;j<(taille-1)/4;j++)
      {x++;k++;
       cote[k]=((taille-1)/4-x)*100+j;
      }
    }
 if(j<(taille-1)/4 && j>0 && i>(taille-1)/4)
   {int x=0;
    for(int j=1;j<(taille-1)/4;j++)
     {x++;k++;
      cote[k]=((taille-1)/4+x)*100+j;
     }
    }
 if(j<(taille-1) && j>((taille-1)-(taille-1)/4) && i<(taille-1)/4)
   {int x=0;
    for(int j=taille-2;j>((taille-1)-(taille-1)/4);j--)
     {x++;k++;
      cote[k]=((taille-1)/4-x)*100+j;
     }
    }
 if(j<(taille-1) && j>((taille-1)-(taille-1)/4) && i>(taille-1)/4)
  {int x=0;
    for(int j=taille-2;j>((taille-1)-(taille-1)/4);j--)
    {x++;k++;
     cote[k]=((taille-1)/4+x)*100+j;
    }
  }
}
//////////////////////////////////////////////////////////////////////////////////////
bool tablier::encote(int i,int j)
{ ///es-ceque la case est enregistrer(coté)
  bool b=false;
 for(int t=0;t<=k;t++)
  if(cote[t]%100==j && cote[t]/100==i)
   b=true;
 return b;
}
//////////////////////////////////////////////////////////////////////////////////////
void tablier::unj()
{
 int i,j,gagne;
 do
 {
 cout<<"le joueur 1 doit choisir une couleur"<<endl;
 cout<<"blanc:7"<<endl;cout<<"gris:40"<<endl;
 cout<<"rouge:41"<<endl;cout<<"vert:42"<<endl;
 cout<<"jaune:43"<<endl;cout<<"bleu:44"<<endl;
 cout<<"violet:45"<<endl;
 cin>>j1;
 if(j1!=7 && j1!=40 && j1!=41 && j1!=42 && j1!=43 && j1!=44 && j1!=45)
 cout<<"vous n'avez pas choisi le bon chiffre"<<endl;
 }while(j1!=7 && j1!=40 && j1!=41 && j1!=42 && j1!=43 && j1!=44 && j1!=45);

  affichage();
 j2=46;//l'ordinateur a toujour cette couleur pour les difirentier lors de la sauvegarde et chargement de la matrice

  while(gagne!=-1 && gagne<=nbcases)//si personne n'a gagner et il reste des cases libre
  {do
   {//le joueur 1 commence toujour
     cout<<"c'est au tour du joueur 1 donner les coordoner de la case(num de la ligne apres le numero de la colonne)"<<endl;
     cin>>i;
     cin>>j;
    }while(tab[i][j]!=-1);
    tab[i][j]=j1;
    gagne++;
    affichage();
    if(gagner(j1)) {cout<<"le joueur 1 a gagner"<<endl;gagne=-1;}
    if(gagne!=-1 && gagne<=nbcases)//si y'a pas de gagnant et il reste des cases vide
    {
     IA(i,j,5,i*100+j,j2);//l'ordinateur joue
     gagne++;
     if(gagner(j2)) {cout<<"l'ordinateur a gagner"<<endl;gagne=-1;}
      affichage();
    }
    if (nbcases==gagne)
    {
      cout<<"match nulle";
    }
  }
} 
//////////////////////////////////////////////////////////////////////////////////////
void tablier::IA(int i,int j,int profondeur,int p,int q)
{
  int w=0;int je=0;///w=la case a joue//je=le score de la case
  minmax(i,j,profondeur,p);//sauvegarder
  for(int r=0;r<=v;r++)//chercher dans le tableau la case qui a le plus grand score et l'affecter a w
  {
    if((joue[r].score>je)&&(tab[joue[r].position/100][joue[r].position%100]==-1))
    {
      je=joue[r].score;
      w=joue[r].position;
    }
  }
  if (w==0)//si y'a pas de case libre par rapport a la derniere case jouer il choisi une au hasard
  {
    for(int e=0;e<(taille+1)/2;e++)
      for (int d=0;d<taille-1;d++)
      {
        if(tab[i][j]==-1)
        {
          w=i*100+j;
          e=(taille+1)/2;
          d=taille-1;
        }
      }
  }
  tab[w/100][w%100]=q;
    n=-1;v=-1;//renetialiser les tableaux
}
//////////////////////////////////////////////////////////////////////////////////////
void tablier::minmax(int i,int j,int profondeur,int p)
{
  int b=0;int x;
   enregitrerlacase(i,j);
 if(profondeur!=0)
 {//scorer les coins a 25 points
   if(((i==0 && j==(taille-1)-(taille-1)/4)||(i==taille/2 && j==(taille-1)/4)||(i==taille/2 && j==taille-1-(taille-1)/4)||(i==taille/4 && j==taille-1)||(i==taille/4 && j==0)||(i==0 && j==(taille-1)/4)) && ((i*100+j)!=p))
    b=25+profondeur;
    //scorer les cote a 15 
    if((i==(taille-1)/2 && j<(taille-1)-(taille-1)/4 && j>(taille-1)/4)||(i==0 && j<(taille-1)-(taille-1)/4 && j>(taille-1)/4))
      {
       b=profondeur+15;
      }
      else 
      {
        for(int z=1;z<(taille-1)/4;z++)
        {
            x++;
            if((i==(taille-1)/4-x && j==z)||((taille-1)/4+x==i && j==z))
             {b=profondeur+15;}
        }x=0;
        for(int z=taille-2;z>((taille-1)-(taille-1)/4);z--)
         {x++;
          if((i==(taille-1)/4-x && j==z)||((taille-1)/4+x==i && j==z))
          {b=profondeur+15;}
         }
      }
         enregitrerlejeu(b,i*100+j);
   i--;
   j--;
   profondeur--;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1)) 
    {if(tab[i][j]==-1 && !visiter(i,j))
      {
       minmax(i,j,profondeur,p);
       n--;//supprimer la case enregistrer a la fin de la recurtion
      }else if(tab[i][j]==j1 && i*100+j!=p)//si le suivant de la case et egale a j1 scorer la case precedent a 20
        {enregitrerlejeu(20+profondeur,(i+1)*100+j+1);}
    }
   j=j+2;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1)) 
    {if(tab[i][j]==-1 && !visiter(i,j))
      {
       minmax(i,j,profondeur,p);
       n--;
      }else if(tab[i][j]==j1 && i*100+j!=p)
        {enregitrerlejeu(20+profondeur,(i)*100+j-2);}
    }
   i++;
   j++;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1)) 
    {if(tab[i][j]==-1 && !visiter(i,j))
      {
       minmax(i,j,profondeur,p);
       n--;
      }else if(tab[i][j]==j1 && i*100+j!=p)
        {enregitrerlejeu(20+profondeur,(i-1)*100+j-1);}
    }
   j--;
   i++;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1)) 
    {if(tab[i][j]==-1 && !visiter(i,j))
      {
       minmax(i,j,profondeur,p);
       n--;
      }else if(tab[i][j]==j1 && i*100+j!=p)
        {enregitrerlejeu(20+profondeur,(i-1)*100+j+1);}
    }
   j=j-2;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1)) 
    {if(tab[i][j]==-1 && !visiter(i,j))
      {
       minmax(i,j,profondeur,p);
       n--;
      }else if(tab[i][j]==j1 && i*100+j!=p)
        {enregitrerlejeu(20+profondeur,(i+1)*100+j+2);}
    }
   i--;
   j--;
   if(0<=i && i<((taille+1)/2) && 0<=j && j<=(taille-1)) 
    {if(tab[i][j]==-1 && !visiter(i,j))
      {
       minmax(i,j,profondeur,p);
       n--;
      }else if(tab[i][j]==j1 && i*100+j!=p)
        {enregitrerlejeu(20+profondeur,(i+1)*100+j+1);}
    }
 }
}
//////////////////////////////////////////////////////////////////////////////////////
void tablier::enregitrerlejeu(int x,int y)
{ ///pour le 
  v++;
  joue[v].score=x;
  joue[v].position=y;
}

////////////////////////////////////////////////////////////////////////////////////////

void tablier::sauvegarder()
{
  FILE * (file);
 file=fopen("sauvegarde/save.txt","w");
  fprintf (file, "%d",j1);
  fprintf (file,"\n");
  fprintf (file, "%d",j2);
  fprintf (file,"\n");
  fprintf (file, "%d",j3);
  fprintf (file,"\n");
  fprintf (file, "%d",(taille+3)/4);
  fprintf (file,"\n");
  for (int i=0;i<(taille+1)/2;i++)
   {
    for (int j=0;j<taille;j++)
     {
      fprintf (file, "%d",tab[i][j]);
      fprintf (file, "%s"," ");
     }
    fprintf (file,"\n");
   }
  fclose (file);
}
/////////////////////////////////////////////////////////////////
void tablier::configuration()
{
  ifstream file("sauvegarde/save.txt",ios::in);
  int tmp;
  int i=0;
  if(file)
  {
        file >> tmp;
        j1=tmp;
        file >> tmp;
        j2=tmp;
        file >> tmp;
        j3=tmp;
        file >> tmp;
        taille=tmp;
    while((!file.eof()) && (i<(taille+1)/2))
     { 
        for(int j=0;j<taille;j++)
        {
         file >> tmp;
         tab[i][j]=tmp;
        }
      i++;
     }
   file.close();
  }
  else 
  {
    cerr<<"file wasn't found"<<endl;
  } 
}