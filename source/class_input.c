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

// ==============================
// * Tester la direction droite *
// ==============================
unsigned char get_right(unsigned char id_pad)
{

  if (id_pad==0)
  {
    return joypad_1 & PAD_RIGHT;

  }

  else if (id_pad==1)
  {
    return joypad_2 & PAD_RIGHT;
  }

  return 1;
}

// ==============================
// * Tester la direction gauche *
// ==============================
unsigned char get_left(unsigned char id_pad)
{
    if (id_pad==0)
  {
    return joypad_1 & PAD_LEFT;

  }

 else if (id_pad==1)
  {
    return joypad_2 & PAD_LEFT;
  }
 return 1;
}

// ============================
// * Tester la direction haut *
// ============================
unsigned char get_up(unsigned char id_pad)
{
    if (id_pad==0)
  {
    return joypad_1 & PAD_UP;

  }

  else if (id_pad==1)
  {
    return joypad_2 & PAD_UP;
  }
 return 1;
}

// ===========================
// * Tester la direction bas *
// ===========================
unsigned char get_down(unsigned char id_pad)
{
   if (id_pad==0)
  {
    return joypad_1 & PAD_DOWN;

  }

  else if (id_pad==1)
  {
    return joypad_2 & PAD_DOWN;
  }
 return 1;
}

// ===========================
// * Tester la direction feu *
// ===========================
unsigned char get_fire(unsigned char id_pad)
{
   if (id_pad==0)
  {
    return joypad_1 & PAD_FIRE2;

  }

  else if (id_pad==1)
  {
    return joypad_2 & PAD_FIRE2;
  }
 return 1;
}

// ================================
// * Tester la direction feu left *
// ================================
unsigned char get_fire_left(unsigned char id_pad)
{
   if (id_pad==0)
  {
    return joypad_1 & PAD_FIRE1;

  }

  else if (id_pad==1)
  {
    return joypad_2 & PAD_FIRE1;
  }
 return 1;
}