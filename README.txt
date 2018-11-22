/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:38:10 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/22 13:01:06 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef unsigned short t_piece;

#endif

//donc la soit on stocke comme un carre de 4, mais pas top au sens ou distingue les trucs pareils
//sinon on decale toujours a sa forme la plus en haut a gauche --> pas mal
//du coup struct ? ca depend comment on utilise le truc
//Avantage -> on peut stocker direct une lettre dans la struct pendant la crea qui peut representer le carre final
//apres l'ordre est garde, pas forcement utile ...
//du coup ce serait stocke dans une liste de carre de 4 de cote, sans static
//ensuite on compare chaque carre pour voir si valide et unique, et on decale en haut a gauche au max. Comment ?
//pas si simple ... la struct etait bien pour eviter la position.apres c'est pas si compliaue :
//on prend le 1 le plus a gauche, on le decale completement a gauche, et on decales tous d'un decalage equivalent.
//ensuite de meme avec le plus haut. done.
//devrait etre asse rapide, cest dans lalgo que le temps deviendra interessant
//en fait il faut resonner avec seulement deux unsigned char.
//read par 1 ou 17 pour \n plus check validite, on peut juste avoir un compteur pour suivre.
//pour decaler ce sera uniquement par decalage surement. Mais ATTENTION on peut pas juste essayer de remplis en haut a gauche non ?
//si on a 0110 1100 0000 0000 on peut pas plus le decaler. il faut reflechir justement en "en haut" puis "a gauche"//on peut resonner en Hexa je pense ...
//on prend un masque pour verifier que le 1er nest pas a 0
//ca equivaut a un 
//0000 si tu fais OU dessus pas bon, ET ce sera 0 de toute facon XOR donne quoi 
//0 et 1 et 1 et 0 donne 1, 00 et 11 donne 0 du coup si on a que des 0 on peut avoir 1, mais ca merde pour le reste
//on peut inverser betement aussi
//si on fait un OU avec 1111 X.. contre 0000 1... on a forcement 1 sur le fin et on a 1 sur le reste uniauement si cetait que 0 --> PARFAIT
//du coup si on a ca on decale de 4
//test avec 0000 0000 0110 0011
//donne 0000 0110 0011
//0110 0011 0000 0000
//pas fini du coup, maintenant il faut decaler a gauche
//il faut checker le 1er de chaque ? si eg 0100 0100 1100 0000 cest bon
//on check donc si il y a que des 0 en 1er, donc que des OU avec ~ cad
//0111 0111 ... avec OU sur ~ donc sur 1011 1011 0011 1111
//donne 1111 1111 0111 1111 donc pas 1 --> parfait encore
//mieux ? si on met ET sans inverser, on veut que ce soit tout 0 du coup, avec 1000 1000 1000 1000
//donc ca donne 0000 0000 1000 0000 pas tout zero, on le fait pas ---> MIEUX, a prendre aussi pour premier
//donc si marche, on decale aussi
//0100 0100 0100 0100 on decale de 1 jusqua que ca marche.
//PAF
//BIM
//maintenant pour le fun
//le premier probleme est que si la on resonne en short, c'est pas u tout forcement un short a la fin. limite ?
//du coup l'idee d'essayer toutes les positions possibles dans le short est idiot -> potentiellement on va plus loin
//TAILLE DU CARRE FINAl ??? IL VA BIEN FALLOIR ALLOUER UN TRUC
//UN MAX EN STATIQUE ??? EN THEORIE CEST ASSEZ GRAND, jusqua 26 pieces
//du coup si 26 shorts en version simple, ca fait 26 * 16 octet c'est grand quand meme, vu qu,on a pas mal de solutions
//pour la taille de la solution = soit on utilise le taille max qui est short * nb de tetriminos
//soit on essaye de definir la largeur et hauteur max, pour optimiser un peu -> a faire que si ca marche pas
//pour stocker la solution, le mieux c'est d'utiliser une seule a la limite, il faut pouvoir revenir surtout a la position relative de chacun donc bien une array de X short, comme ca on pourra traduire.
//du coup : on regarde la taille du carre. si cest STRICTEMENT MIEUX on remplace. Sinon on ecrase sans pitie.
//ca peut marcher ssi on commence en haut a gauche, ce qui parait naturel. MAIS DEBUT DES EMMERDES. Cest pas des shorts que lon doit stocker, mais bien des carres equivqlents au max de la solution possible, vu aue c'est la dessus quon bosse.
//donc une array de nb_pieces * (nb_pieces * short bytes)
//on peut decaler plus facilement, et travailler dessus
//ensuite il faut aussi un back tracking evidemment
//comme le sudoku du coup, les coditions :
//toujours une piece en haut a gauche
//il faut toujours une piece en haut a gauche et que ca se touche, pas un souci devrait le faire seul. 
//OPTIMISATION -> EVITER de continuer si on ne touche plus.
//pour placer une piece vis a vis des autres, on peut gerer le premier 1 dans la piece, face a un zero. Si c'est bon, on regarde si ca rentre. si ca rentre on place. On va jusquau bout et on stocke notre resultat temporaire si le carre est plus petit. pour definir la taille du carre cest le nb de bytes pris ??  
//EMMERDE -> on peut pas penser un carre 5 de cote si on raisonne avec des 4 ..., ca pourrait casser nos figures bizarre.
//CES BON SI ON TRANSFORME BIEN NOS NOMBRES. APRES PAS SUR ...
//Exemple : 0110 1100 0000 0000 devient 01100 11000 00000 00000, surement possible dans lidee ...
//sauf que si on a deux tetris on veut raisonner sur du 8*8 en vrai ...
//ERRATUM = checker la taille max
//a donnerait 01100000 11000000 8x0 8x0 8x0 ...
//si on decale ca on peut trouver le plus petit facilement ?
//exemple avec un deuxieme 10... 10... 10... 10... 8x0 4fois
//quand on decale c'est soit vers la droite avec >>1
//soit vers le bas avec >>8 du coup
//si on fait que >>1 on aura tendance a tout caler a cote sans faire de carre ...
//et puis c'est gros quand meme
//INTUITION : raisonner uniquement en bytes, et dessiner un carre a partir de la liste apres une fois que le plus petit est trouve
//test de la taille du carre a faire sinon, et juste >>1 on ignore
//sauf qu'une fois au bout, baise possible on casse les murs.
//IDEE : on part du plus haut a gouche, on bouge a droite jusqu'a plus possible. on revient au depart, on descend d'un et rebelotte, jusqua plus possible.
//trop long peut etre si on est oblige de tester toutes les places possibles en permanence.
//le depart peut etre different deja ?
//OPTI UTILE SUREMENT --> ON STOCKE DANS UNE STRUCT HAUTEUR ET LARGEUR DE chaque piece --> donne la taille sur laquelle bosser avec une rapide
//il faudrait eviter de tester les solutions evidemment pourries deja
//exemple : on a une solution de largeur X et de hauteur Y --> on teste pas si on depasse X on Y. dou linteret de stocker la largeur, car bloc de depart est pas representatif de la ou ca s'arrete.
//WAIT : et si on pale pas d'un carre ? on peut etre baise
//genre tout allonge avec une hauteur nulle, qui nous empecherait de la depasser ... dans les faits ca existe ?
//trop fatiguant jarrive plis a reflechor 
//ARG
