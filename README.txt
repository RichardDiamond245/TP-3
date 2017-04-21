TP-3 -- Graphes, mémoire, fichiers, pointeurs

TP à faire individuellement. Remise via LEA, à la date indiquée.


CONTEXTE

Un de nos développeurs travaillait sur un dictionnaire implémenté à l'aide d'arbres dictionnaires (chaque noeud à 26 enfants possibles). Ce dernier a effacé ses fichiers .cpp par inadvertance. Il a perdu 400 lignes de code et en est tombé malade. Puis il a été congédié.

On vous demande de reprogrammer les fonctions. Il vous reste les fichier hpp, un peu de documentation, des tests, et les fichiers résultat.

Le développeur a laissé les tests (il n'a pas effacé main.cpp). I y a 5 fonctions de test, chacune testant avec 5 fichiers, ce qui fait un total de 25 tests. 

La commande 'diff' sous linux vous permettra de comparer vos fichiers résultat avec ceux du développeur. 

Ex. La commande 'diff sources/words-4.dot votre-solution/words-4.dot' vous permettra de voir s'il y a une différence entre le fichier que son programme avait généré et le votre.

Vous pouvez aussi comparer vos graphes et les siens avec xdot.


REMARQUES

On peut voir que le développeur avait probablement donné un ID à chaque noeud et utilisait le l'étiquetage ([label="...") de manière à rendre son graphe visible.

Vous pouvez modifier les signatures des fonctions qui ne sont pas appelées directement par les tests. Vous pouvez aussi en ajouter ou en enlever. Néanmoins, cela ne devrait pas s'avérer nécessaire.

Vous devez vous assurer que l'affichage et les graphes générés soient EXACTEMENT LES MÊMES. Le client utilisera la commande 'diff', tel que décrit plus haut, pour valider les sorties de votre programme. Toute différence entrainera des points en moins.


CORRECTION

Vous perdrez 4 points par tests échouant.

Vous perdrez aussi : 
    2 point par warning
    10 points si la gestion de la mémoire n'est pas correctement faite
    5 points par fonction dupliquant code d'une autre fonction


QUESTIONS

    Nicolas Gorse via MIO. Réponse dans les 24h.


Bonne chance !

