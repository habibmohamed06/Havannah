#ifndef PLATEAU_H 
#define PLATEAU_H
#define clrscr() printf("\033[H\033[2J")

struct posescore
{
  int position;
  int score;
};

class tablier
{
 int **tab;///la matrice
 int taille;///la taile de matrice
 int j1=-3;
 int j2=-3;
 int j3=-3;
 int visite[169];///pour enregistrer les cases déjà visiter
 int cote[50];///pour enregistrer les côtés enregistrer
 int n=-1;///initialiser le tableau de cases visité
 int k=-1;///initialisé le tableau de côtés visité
 int v=-1;//initialisé le tableau de cases jeu enregistrer
 int nbcases=0;///ninitialisé le nombre de cases de jeu à zero
 posescore joue[1000];///enregistrer les cases et leurs score
     public: 
	tablier(int);///constructeur
	void affichage();///affichage du tablier 
	void deuxj();///jouer a deux
	void troisj();//trois joueurs
	bool gagner(int);///appel des fontion pont fourche anneau
	bool pont(int);/// es cequ'il y'a une possibilité de pont??
	bool testerpont(int,int,int,int);///
	bool anneau(int);/// es cequ'il y'a une possibilité d'anneau??
	bool testeranneau(int,int,int,int,int,int);///
	bool visiter(int i,int j);/// tester si la case a été visité 
	void enregitrerlacase(int i,int j);/// enregirter la cases visiter
	bool fourche(int a);/// es cequ'il y'a une possibilité de fourche??
	bool testerfourche(int,int,int,int,int);///
	void enregitrerlecote(int,int);/// enregistrer le côte ou il y'a une case jouer
	bool encote(int,int);///tester si le côt" a été enregistrer
	void unj();/// jouer seul
    	void IA(int,int,int,int,int);///
    	void minmax(int ,int ,int,int);///
   	void enregitrerlejeu(int,int);
    	void sauvegarder();
    	void configuration();
};
#endif
