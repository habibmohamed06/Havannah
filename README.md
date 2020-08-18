# Havannah
Projet L2 informatique
I. Introduction
--------------------------------------------------------------------------------
L'objet de ce document est de vous aider à comprendre comment j’ai procéder pour réaliser ce jeu

- PRISE EN MAIN RAPIDE
        -Démarrer l’application
        -Charger la partie précédente ou commencer un nouvel partie
        -Choisir taille du tablier
        -Choisir le nombre de joueur
        -Débuter la partie
        -La partie se termine lorsque l’un des joueur arrive a faire l’une des trois forme(fourchette ou pont ou anneau)
        -Sauvegarder la partie utilisateur dans un fichier



CASSES UTILISÉES :

   Pour ce jeu j’ai choisi de faire une seul classe qui s’appelle tablier.
Les principales foncions de cette classe sont:
le constructeur:
qui prends comme paramètre la taille du tablier et crée une matrice d’entier.
La fonction testerpont:
qui vérifie si un pont a été crée 
pour que celle ci se déclenche il faut au minimum avoir un coin jouer par le meme joueur.
dés qu’un coin a été détecter on lance la recherche 
la recherche ce fait par récursion  elle regarde si il y’a un chemin entre deux coins.

la fonction testeranneau :
a chaque fois qu’un joueur joue il parcoure la matrice a la recherche d’un éventuel anneau
a début on commence la recherche avec quatre frères l’un a coté de l’autre après on continue la recherche avec trois frères pour avoir un vide milieu
chaque frère continue soit tout droit soit le frère gauche ou droit pour faire un vide au mileu.



la fonction testercourche :
la recherche se fait dés que un coté est jouer .Le coté ou le il a été jouer est directement enregistré après la recherche continue vers un autre coté et dés que un autre coté est détecté  on incrémente le conteur de coté à 2 et on réinitialise le tableau de case enregistré et on part a la recherche d’un autre coté.


La fonction minmax :
la fonction enregistre tout les coût possible et leurs scores à partir de la case jouer par le joueur 1.
j'ai mis une profondeur de 5.
j'ai scoré les coins a 25+profondeur  les cotés à 15+profondeur et si on se rapproche d'une case deja jouer par le joueur 1 je l'ai scoré à 20+profondeur.

