/*****************************************************************
 * Nom ................. : class_player.c                        *
 * Role ................ : gestion de la map                     *
 * Auteur .............. : Monos                                 *
 * Version ............. : 19/11/2019                            *
 *****************************************************************/

// ==================================
// ** Fichier include du programme **
// ==================================
#include "include/main.h"

// ========================================
// ** Déclaration des variables globales **
// ========================================
 player_t player[2];
 curseur_t curseur;


// ================
// ** Set player **
// ================
void set_player(unsigned char id_player,unsigned char position_x,unsigned char position_y)
{
 player[id_player].px = position_x;
 player[id_player].py = position_y;
}


// ==================
// ** Set couleurs **
// ==================
void set_coul(unsigned char id_player,unsigned char id_coul)
{
  player[id_player].id_coul = id_coul;
}

// =========================================
// ** Récupérer la position x d'un joueur **
// =========================================
unsigned char get_player_px(unsigned char id_player)
{
  return player[id_player].px;
}

// =========================================
// ** Récupérer la position y d'un joueur **
// =========================================
unsigned char get_player_py(unsigned char id_player)
{
  return player[id_player].py;
}



// ===================
// ** update_player **
// ===================
void update_player()
{
    spr_set(1, (player[0].px)<<4,  ((player[0].py)<<4)-1,  player[0].id_coul, 4) ; // Joueur 0
    spr_set(2, (player[1].px)<<4,  ((player[1].py)<<4)-1,  player[1].id_coul, 4) ; // Joueur 1

    spr_set(3, (player[0].px)<<4,  ((player[0].py)<<4)-1,  1, 8) ; // Joueur 0
    spr_set(4, (player[1].px)<<4,  ((player[1].py)<<4)-1,  1, 8) ; // Joueur 1
}


// ==================
// ** Set curseur **
// ==================
void set_curseur(unsigned char id_player,unsigned char position_x,unsigned char position_y)
{
 curseur.id_player = id_player;
 curseur.px = position_x;
 curseur.py = position_y;
 curseur.id_coul = player[id_player].id_coul;
}


// ====================================
// ** Recupérer la couleur du joueur **
// ====================================
unsigned char get_player_id_color(unsigned char id_player)
{
  return player[id_player].id_coul;
}

// ====================
// ** Set curseur_px **
// ====================
void set_curseur_px(unsigned char position_x)
{
  curseur.px = position_x;

}

// ====================
// ** Get curseur px **
// ====================
unsigned char get_curseur_px()
{
return curseur.px;

}
// ====================
// ** Set curseur_py **
// ====================
void set_curseur_py(unsigned char position_y)
{
  curseur.py = position_y;

}

// ====================
// ** Get curseur py **
// ====================
unsigned char get_curseur_py()
{
return curseur.py;

}



// ** **
void set_coul_curseur(unsigned char id_coul)
{
 curseur.id_coul = id_coul;

}


// ====================
// ** update curseur **
// ====================
void update_curseur()
{
  spr_set(0, (curseur.px)<<4, ( (curseur.py)<<4)-1,  curseur.id_coul, 0) ; // curseur

}