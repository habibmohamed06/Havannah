#include<iostream>
#include<fstream>
#include"fonc.h"
#include<stdlib.h>

using namespace std;
int main()
{
  cout<<"appuyez sur entrer pour continuer"<<endl;
  cin.get();
	int e;
    int q;
    clrscr();
 cout <<"        bbbb  ii eeeee nn  nn vv vv eeeee nn  nn uu uu eeeee"<<endl;
 cout <<"        bbbbb ii eeeee nn  nn vv vv eeeee nn  nn uu uu eeeee"<<endl;
 cout <<"        bb bb ii ee    nnn nn vv vv ee    nnn nn uu uu ee"<<endl;
 cout <<"        bbbbb ii eeee  nnn nn vv vv eeee  nnn nn uu uu eeee"<<endl;
 cout <<"        bbbb  ii eeee  nnnnnn vvvvv eeee  nnnnnn uu uu eeee"<<endl;
 cout <<"        bb bb ii ee    nn nnn  vvv  ee    nn nnn uu uu ee"<<endl;
 cout <<"        bb bb ii ee    nn nnn  vvv  ee    nn nnn uu uu ee"<<endl;
 cout <<"        bbbbb ii eeeee nn  nn  vvv  eeeee nn  nn uuuuu eeeee"<<endl;
 cout <<"        bbbb  ii eeeee nn  nn  vvv  eeeee nn  nn  uuu  eeeee"<<endl;
 cout <<"                        sss  uu uu rrrr"<<endl;
 cout <<"                       sssss uu uu rrrrr"<<endl;
 cout <<"                       ss    uu uu rr rr"<<endl;
 cout <<"                       ssss  uu uu rrrrr"<<endl;
 cout <<"                        ssss uu uu rrrr"<<endl;
 cout <<"                          ss uu uu rr rr"<<endl;
 cout <<"                       ss ss uu uu rr rr"<<endl;
 cout <<"                       sssss uuuuu rr rr"<<endl;
 cout <<"                        sss   uuu  rr rr"<<endl;
 cout <<"      hh hh   aaa   vv vv   aaa   nn  nn nn  nn   aaa   hh hh"<<endl;
 cout <<"      hh hh   aaa   vv vv   aaa   nn  nn nn  nn   aaa   hh hh"<<endl;
 cout <<"      hh hh   aaa   vv vv   aaa   nnn nn nnn nn   aaa   hh hh"<<endl;
 cout <<"      hh hh   aaa   vv vv   aaa   nnn nn nnn nn   aaa   hh hh"<<endl;
 cout <<"      hhhhh  aa aa  vv vv  aa aa  nnnnnn nnnnnn  aa aa  hhhhh"<<endl;
 cout <<"      hh hh  aaaaa   vvv   aaaaa  nn nnn nn nnn  aaaaa  hh hh"<<endl;
 cout <<"      hh hh  aaaaa   vvv   aaaaa  nn nnn nn nnn  aaaaa  hh hh"<<endl;
 cout <<"      hh hh aa   aa  vvv  aa   aa nn  nn nn  nn aa   aa hh hh"<<endl;
 cout <<"      hh hh aa   aa  vvv  aa   aa nn  nn nn  nn aa   aa hh hh"<<endl<<endl<<endl;

 cout<<"appuyez sur entrer pour continuer"<<endl;
  cin.get();
  clrscr();
 cout<<"Le vainqueur est le premier joueur à former un pont ou une fourchette ou une boucle."<<endl;
 cout<<"- Pont: suite de pions de même couleur reliant 2 coins ou;"<<endl;
 cout<<"- Fourchette: chaîne de pions de même couleur reliant 3 côtés."<<endl;
 cout<<"- Boucle: suite de pions de même couleur entourant au moins une intersection vide ou non."<<endl<<endl<<endl; 	
///cout<<"si vous voulez quitter la partie en sauvegardant tapez 100"<<endl;
  cout<<"appuyez sur entrer pour continuer"<<endl;
  cin.get();
  clrscr();
 cout <<"donner la taille du plateau "<<endl;
 /*ifstream file("sauvegarde/save.txt" ,ios::in);
  int tmp;
  int i=0;
  if(file)
   {
         file>>tmp;
         if(tmp!=-3)
         	e++;
         file>>tmp;
         if(tmp!=-3)
         	e++;
         file>>tmp;
         if(tmp!=-3)
         	e++;
         file>>tmp;
         q=tmp;
   file.close();
  }
  else 
  {
 tablier t(4);
 t.affichage();
 do
 {
 cout <<"combien de joueurs(1 OU 2 ou 3) "<<endl;
 cin>>e;
 }while(e!=1 && e!=2 && e!=3);
 if (e==1){t.unj();}
 if (e==2){t.deuxj();}
 if (e==3){t.troisj();}
 return 0;
 }*/
 cin>>q;
 tablier t(q);
 t.affichage();
 do
 {
 cout <<"combien de joueurs(1 OU 2 ou 3) "<<endl;
 cin>>e;
 }while(e!=1 && e!=2 && e!=3);
 if (e==1){t.unj();}
 if (e==2){t.deuxj();}
 if (e==3){t.troisj();}
 return 0;
}