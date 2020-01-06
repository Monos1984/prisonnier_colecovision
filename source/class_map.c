/*****************************************************************
 * Nom ................. : class_map.c                           *
 * Role ................ : gestion de la map                     *
 * Auteur .............. : Monos                                 *
 * Version ............. : 18/11/2019                            *
 *****************************************************************/
// ==================================
// ** Fichier include du programme **
// ==================================
#include "include/main.h"

// =====================
// ** Variable global **
// =====================
unsigned char ram_map_collision[11][11];



// =========================
// ** Affichage de la map **
// =========================
void draw_map()
{
  // -------------------------------------
  // * Declaration des variables locales *
  // -------------------------------------
  unsigned char x,y,i;
  i = 0;
  
  // --------------------------------
  // * Boucle d'affichage de la map *
  // --------------------------------
  for (y=0;y<11;y++)
  {
    for (x=0;x<11;x++)
    {
      switch (map[i])
      {
        // ----------------
        // * Poser le sol *
        // ----------------
        case 1:


         draw_sol(x,y);
         ram_map_collision[x][y]=0;
         if (sys_randbyte (0,99)<20)
         {
          draw_trap(x,y);
          ram_map_collision[x][y]=1;
         }
     
        break;

        // ----------------
        // * Poser le mur *
        // ----------------
        case 2:
          draw_mur(x,y);
          ram_map_collision[x][y]=1;
        break;

        // -----------------
        // * Poser toiture *
        // -----------------
        case 3:
          draw_toiture(x,y);
          ram_map_collision[x][y]=1;
        break;

        // -----------------
        // * Poser depart *
        // -----------------
        case 4:
          draw_sol(x,y);
          ram_map_collision[x][y]=0;
        break;

      } // Fin switch

      i++;
      


    } // Fin boucle X


  } // Fin boucle Y
  


} // Fin procedure draw_map()


// ---------------------------------------------
// * Afficher le sol rouge pour le déplacement *
// ---------------------------------------------
void draw_full_red_sol(unsigned char px,unsigned char py)
{


  // --------
  // * haut *
  // --------
  if (ram_map_collision[px][py-1]==0)
  {
    draw_red_sol(px,py-1);
    vdp_waitvblank(3);
  }
  // ---------------
  // * haut Droite *
  // ---------------
  if (ram_map_collision[px+1][py-1]==0)
  {
    draw_red_sol(px+1,py-1);
     vdp_waitvblank(3);
  }
  // ----------
  // * Droite *
  // ----------
  if (ram_map_collision[px+1][py]==0)
  {
    draw_red_sol(px+1,py);
    vdp_waitvblank(3);
  }
  // --------------
  // * bas Droite *
  // --------------
  if (ram_map_collision[px+1][py+1]==0)
  {
    draw_red_sol(px+1,py+1);
     vdp_waitvblank(3);
  }
  // -------
  // * bas *
  // -------
  if (ram_map_collision[px][py+1]==0)
  {
    draw_red_sol(px,py+1);
     vdp_waitvblank(3);
  }
  // --------------
  // * bas gauche *
  // --------------
  if (ram_map_collision[px-1][py+1]==0)
  {
    draw_red_sol(px-1,py+1);
    vdp_waitvblank(3);
  }
  // ----------
  // * gauche *
  // ----------
  if (ram_map_collision[px-1][py]==0)
  {
    draw_red_sol(px-1,py);
    vdp_waitvblank(3);
  }
  // ---------------
  // * haut gauche *
  // ---------------
  if (ram_map_collision[px-1][py-1]==0)
  {
    draw_red_sol(px-1,py-1);
    vdp_waitvblank(3);
  }
}


// -------------------
// * Retablir le sol *
// -------------------
void draw_full_red_sol_off(unsigned char px,unsigned char py)
{

  // ----------
  // * Droite *
  // ----------
  if (ram_map_collision[px+1][py]==0)
  {
    draw_sol(px+1,py);
  }
  // ----------
  // * gauche *
  // ----------
  if (ram_map_collision[px-1][py]==0)
  {
    draw_sol(px-1,py);
  }

  // --------
  // * haut *
  // --------
  if (ram_map_collision[px][py-1]==0)
  {
    draw_sol(px,py-1);

  }

  // -------
  // * bas *
  // -------
  if (ram_map_collision[px][py+1]==0)
  {
    draw_sol(px,py+1);
  }

  // ---------------
  // * haut Droite *
  // ---------------
  if (ram_map_collision[px+1][py-1]==0)
  {
    draw_sol(px+1,py-1);
  }

  // ---------------
  // * haut gauche *
  // ---------------
  if (ram_map_collision[px-1][py-1]==0)
  {
    draw_sol(px-1,py-1);
  }

  // --------------
  // * bas Droite *
  // --------------
  if (ram_map_collision[px+1][py+1]==0)
  {
    draw_sol(px+1,py+1);
  }
 // --------------
 // * bas gauche *
 // --------------
  if (ram_map_collision[px-1][py+1]==0)
  {
    draw_sol(px-1,py+1);
  }


}

// ==================
// ** poser un sol **
// ==================
void draw_sol(unsigned char x, unsigned char y)
{
  vdp_putchar((x<<1),(y<<1),130);
  vdp_putchar((x<<1)+1,(y<<1),138);
  vdp_putchar((x<<1),(y<<1)+1,131);
  vdp_putchar((x<<1)+1,(y<<1)+1,139);
}

// ==================
// ** poser un sol **
// ==================
void draw_red_sol(unsigned char x, unsigned char y)
{
  vdp_putchar((x<<1),(y<<1),147);
  vdp_putchar((x<<1)+1,(y<<1),155);
  vdp_putchar((x<<1),(y<<1)+1,148);
  vdp_putchar((x<<1)+1,(y<<1)+1,156);
}

// ==================
// ** Poser un mur **
// ==================
void draw_mur(unsigned char x, unsigned char y)
{
  vdp_putchar((x<<1),(y<<1),142);
  vdp_putchar((x<<1)+1,(y<<1),142);
  vdp_putchar((x<<1),(y<<1)+1,134);
  vdp_putchar((x<<1)+1,(y<<1)+1,134);
}

// ======================
// ** Poser la toiture **
// ======================
void draw_toiture(unsigned char x, unsigned char y)
{
  vdp_putchar((x<<1),(y<<1),142);
  vdp_putchar((x<<1)+1,(y<<1),142);
  vdp_putchar((x<<1),(y<<1)+1,142);
  vdp_putchar((x<<1)+1,(y<<1)+1,142);
}


// =======================
// ** Poser un le traps **
// =======================
void draw_trap(unsigned char x, unsigned char y)
{
  vdp_putchar((x<<1),(y<<1),132);
  vdp_putchar((x<<1)+1,(y<<1),140);
  vdp_putchar((x<<1),(y<<1)+1,133);
  vdp_putchar((x<<1)+1,(y<<1)+1,141);
}


// ==========================
// * Draw windows game over *
// ==========================
void draw_windows(unsigned char py)
{
  unsigned char x;


  vdp_putchar(0,py,144); // Coin gauche haut
  vdp_putchar(21,py,160); // Coin Droite haut
  vdp_putchar(0,2+py,146); // Coin gauche bas
  vdp_putchar(21,2+py,162); // Coin Droite bas

  vdp_putchar(0,1+py,145); // Gauche
  vdp_putchar(21,1+py,161); // droite

  for (x=1;x<21;x++)
  {
    vdp_putchar(x,py,152);
    vdp_putchar(x,1+py,153);
    vdp_putchar(x,2+py,154);
  }

}

void draw_right_windows()
{
  unsigned char x;

  for (x=24;x<31;x++)
  {
    vdp_putchar(x,0,152);
    vdp_putchar(x,3,154);
  }  


  vdp_putchar(23,0,144); // Coin gauche haut
  vdp_putchar(31,0,160); // Coin Droite haut

  vdp_putchar(23,1,145); // Gauche
  vdp_putchar(23,2,145); // Gauche

  vdp_putchar(31,1,161); // Droite
  vdp_putchar(31,2,161); // Droite

  vdp_putchar(23,3,146); // Coin gauche bas
  vdp_putchar(31,3,162); // Coin Droite bas

}


