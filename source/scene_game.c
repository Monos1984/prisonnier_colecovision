/*****************************************************************
 * Nom ................. : scene_game.c                          *
 * Role ................ : gestion des scenes du jeu             *
 * Auteur .............. : Monos                                 *
 * Version ............. : 18/11/2019                            *
 *****************************************************************/

// ==================================
// ** Fichier include du programme **
// ==================================
#include "include/main.h"

// ========================================
// ** Déclaration des variables globales **
// ========================================
extern unsigned char ram_map_collision[11][11];
unsigned char id_action;
unsigned char draw_text;
// ============================
// ** Procedure scene_game() **
// ============================
void scene_game()
{

  // =================================
  // ** Initiation de la scene_game **
  // =================================
  
  // --------------------------------------
  // * Chargement des assets colecovision *
  // --------------------------------------
  vdp_rle2vram (rle_data_tile,chrgen);	
  vdp_rle2vram (rle_color_tilset,coltab);
  vdp_rle2vram (rle_game_sprite,sprtab);
  vdp_duplicatevram();
  
  // -----------------------
  // * affichage de la map *
  // -----------------------
  draw_map();
  
  // -----------------------------
  // * Mise en place des sprites *
  // -----------------------------
  set_coul(PLAYER_1,6);
  set_coul(PLAYER_2,11);
  set_player(PLAYER_1,5,1);
  set_player(PLAYER_2,5,9);

  set_curseur(PLAYER_1,5,1);

  spr_enable = 1;

  // -----------------------
  // * allumage de l'ecran *
  // -----------------------
  vdp_waitvblank(1); // Attendre la syncro verticale
  vdp_enablescr();  // Allumage de l'écran  

  // -------------------------------
  // * Collision de la case sprite *
  // -------------------------------
  ram_map_collision[get_player_px(PLAYER_1)][get_player_py(PLAYER_1)] = 1;
  ram_map_collision[get_player_px(PLAYER_2)][get_player_py(PLAYER_2)] = 1;

  // ---------------------------------
  // * Initiation de l'action de jeu *
  // ---------------------------------



  switch (sys_randbyte (0,3))
  { 
    case 0 :
      id_action = 0;
    break;

     case 1 :
      id_action = 1;
    break;

   case 2 :
      id_action = 3;
      set_curseur(PLAYER_2,get_player_px(PLAYER_2),get_player_py(PLAYER_2));
   break;

   case 3 :
      id_action = 4;
      set_curseur(PLAYER_2,get_player_px(PLAYER_2),get_player_py(PLAYER_2));
    break;
  }




  // =================
  // * Draw left hud *
  // =================
  draw_right_windows();
  update_player();

  
  // =============================
  // ** Boucle du la Scene Game **
  // =============================
  while(get_scene() == SCENE_GAME)
  {
    // **********************************
    // * Temps logique du jeu  (update) *
    // **********************************
   
    // -------------------------
    // * Mouvement du joueur 1 *
    // -------------------------
   
    if (id_action == 0)
    {

      if (draw_text==0)
      {
          draw_full_red_sol(get_player_px(PLAYER_1),get_player_py(PLAYER_1));
          vdp_putstring(26, 1, "P1");
          vdp_putstring(24, 2, "       ");
          vdp_putstring(24, 2, "moved");
          draw_text=1;
      }
     
      move_curseur(PLAYER_1);
      moved_player(PLAYER_1);
    }
     
    // ----------------------------------------------
    // * ouvrir une trap sur le sol par le joueur 1 *
    // ----------------------------------------------
    else if (id_action == 1)
    {
      if (draw_text==0)
      {
     
          vdp_putstring(26, 1, "P1");
          vdp_putstring(24, 2, "       ");
          vdp_putstring(24, 2, "traps");
          draw_text=1;
      }
      move_curseur(PLAYER_1);
      draw_trape_game(PLAYER_1);
    }
    
    // -----------------------
    // * Tester le game over *
    // -----------------------
    else if (id_action == 2)
    {
      testing_game_over();
      id_action = id_action+1;
    }

    // -------------------------
    // * Mouvement du joueur 2 *
    // -------------------------
   
    else if (id_action == 3)
    {
      if (draw_text==0)
      {
          draw_full_red_sol(get_player_px(PLAYER_2),get_player_py(PLAYER_2));
          vdp_putstring(26, 1, "P2");
          vdp_putstring(24, 2, "       ");
          vdp_putstring(24, 2, "moved");
          draw_text=1;
      }
      move_curseur(PLAYER_2);
      moved_player(PLAYER_2);
    }
    
    // ----------------------------------------------
    // * ouvrir une trap sur le sol par le joueur 2 *
    // ----------------------------------------------
    else if (id_action == 4)
    {
       if (draw_text==0)
      {
           
          vdp_putstring(26, 1, "P2");
          vdp_putstring(24, 2, "       ");
          vdp_putstring(24, 2, "traps");
          draw_text=1;
      }
      move_curseur(PLAYER_2);
      draw_trape_game(PLAYER_2);
    }
    // -----------------------
    // * Tester le game over *
    // -----------------------
    else if (id_action == 5)
    {
      testing_game_over();
      id_action = 0;
    }


    // ------------
    // * wait vbl *
    // ------------
    vdp_waitvblank(1); // Fonction colecovision
   
    // ****************************
    // * Temps d'affichage (draw) *
    // ****************************
    update_player();
    update_curseur();
  }

}

// =====================================
// * Routine de déplacement du curseur *
// =====================================
void move_curseur(unsigned char id_player)
{
  static unsigned char pad_key_up;

  // ==========================
  // * Gestion du pad curseur *
  // ==========================


   if (get_fire_left(id_player)) 
  {

   if (pad_key_up == 0)
    {

     set_coul(id_player,get_player_id_color(id_player)+1);

    if (get_player_id_color(id_player) >15)
    {
      set_coul(id_player,1);
    }
      
      set_coul_curseur(get_player_id_color(id_player));
       pad_key_up = 1;

    }
  }


  // -----------------
  // * Touche droite *
  // -----------------
  else if (get_right(id_player)) 
  {

    if (pad_key_up == 0)
    {
      set_curseur_px(get_curseur_px() + 1);
      pad_key_up = 1;
    }   

  }
  
  // -----------------
  // * Touche gauche *
  // -----------------
  else if (get_left(id_player))
  {
    if (pad_key_up == 0)
    {
      set_curseur_px(get_curseur_px() - 1);
      pad_key_up = 1;
    }
  }

  // ---------------
  // * Touche Haut *
  // ---------------
  else if (get_up(id_player)) 
  {

    if (pad_key_up == 0)
    {
      set_curseur_py(get_curseur_py() - 1);
      pad_key_up = 1;
     }
  }
 
  // --------------
  // * Touche Bas *
  // --------------
  else if (get_down(id_player))
  {
    if (pad_key_up == 0)
    {
      set_curseur_py(get_curseur_py() + 1);
      pad_key_up = 1;
    }  
  }

  // --------------------------------
  // * Mise à 0 le buffer de touche *
  // --------------------------------
  else
  {
    pad_key_up = 0;
  }

  // ================================
  // * protection de sortie du bord *
  // ================================
  if (get_curseur_px() == 0)
  {
    set_curseur_px(1);
  }

  if (get_curseur_px() == 10)
  {
    set_curseur_px(9);
  }

    if (get_curseur_py() == 0)
  {
    set_curseur_py(1);
  }

  if (get_curseur_py() == 10)
  {
    set_curseur_py(9);
  }

}

// =========================
// * Deplacement du joueur *
// =========================
void moved_player(unsigned char id_player)
{
  if ((get_fire(id_player)) && ram_map_collision[get_curseur_px()][get_curseur_py()] == 0 )
  {
    if(
        // Case de droite
        ((get_curseur_px()== get_player_px(id_player) + 1) && (get_curseur_py() == get_player_py(id_player))) ||

        // Case de gauche
        ((get_curseur_px()== get_player_px(id_player)  - 1) && (get_curseur_py() == get_player_py(id_player))) ||

        // Case Haut
        ((get_curseur_px()== get_player_px(id_player) ) && (get_curseur_py() == get_player_py(id_player) - 1)) ||

        // Case Bas
        ((get_curseur_px()== get_player_px(id_player) ) && (get_curseur_py() == get_player_py(id_player) + 1)) ||

        // Haut/Droite
        ((get_curseur_px()==get_player_px(id_player) + 1) && (get_curseur_py() == get_player_py(id_player) - 1)) ||

        // Haut/Gauche
        ((get_curseur_px()== get_player_px(id_player) - 1) && (get_curseur_py() == get_player_py(id_player) - 1)) ||

        // Bas/Droite
        ((get_curseur_px()==get_player_px(id_player) + 1) && (get_curseur_py() == get_player_py(id_player) + 1)) ||

        // Bas/Gauche
        ((get_curseur_px()== get_player_px(id_player) - 1) && (get_curseur_py() == get_player_py(id_player) + 1)))
    {
        
        // =========
        // * Sound *
        // =========
       snd_startplay(5);

        // ------------------------------
        // * Mise à 0 la case du joueur *
        // ------------------------------
        ram_map_collision[get_player_px(id_player)][get_player_py(id_player)] = 0;
        

        // --------------------------
        // * Virer les cases rouges *
        // --------------------------
        draw_full_red_sol_off(get_player_px(id_player),get_player_py(id_player));        


        // -------------------------------
        // * nouvelle position du joueur *
        // ------------------------------- 
        set_player(id_player,get_curseur_px(),get_curseur_py());
        
        // ------------------------------
        // * Mise à 1 la case du joueur *
        // ------------------------------
        ram_map_collision[get_player_px(id_player)][get_player_py(id_player)] = 1;
        
        // ------------------------------
        // * Passage à l'action suivant *
        // ------------------------------
        draw_text=0;
        id_action = id_action + 1; // poser un obstacle 
        vdp_waitvblank(2);
    }
  }

}

// ===========================
// * Ajouter le sol qui bloc *
// ===========================
void draw_trape_game(unsigned char id_player)
{
  // -------------------------------------
  // * Déclaration des variables locales *
  // -------------------------------------
  unsigned char next_player;
 
  // ------------------------
  // * tester le bouton feu *
  // ------------------------
  if( get_fire(id_player))
  {

    if (ram_map_collision[get_curseur_px()][get_curseur_py()]==0)
    {
      snd_startplay(3);
      draw_trap(get_curseur_px(), get_curseur_py());
      ram_map_collision[get_curseur_px()][get_curseur_py()] = 1;
      vdp_waitvblank(3);
      // ----------------------------------
      // * preparation du nouveau curseur *
      // ----------------------------------
      
      if (id_player == 0)
      {
        next_player = 1;
      }
        else
      {
        next_player = 0;
      }
     
     
      set_curseur(next_player,get_player_px(next_player),get_player_py(next_player));
      
      // ------------------------------
      // * Passage à l'action suivant *
      // ------------------------------
      draw_text=0;
      id_action = id_action + 1; // tester le game overs
    }
   




  }

}

// =======================
// * Tester le Game over *
// =======================
void testing_game_over()
{
  // -------------------------------------
  // * Declaration des variables locales *
  // -------------------------------------
  unsigned char lost_player_1;
  unsigned char lost_player_2;

  // ----------------------
  // * tester les joueurs *
  // ----------------------
  lost_player_1 = test_lost_player(PLAYER_1);
  lost_player_2 = test_lost_player(PLAYER_2);

  // ------------------------------------
  // * tester les conditions de defaite *
  // ------------------------------------
 
  // * Game Over player 1 *
  if ((lost_player_1 == 1) && (lost_player_2 == 0))
  {

     draw_windows(21);
    vdp_putstring(5, 22, "player 2 win");
    return_title_screen();

  }
  
  // * Game Over Player 2 *
  else if ((lost_player_1 == 0) && (lost_player_2 == 1))
  {
   
     draw_windows(21);
     vdp_putstring(5, 22, "player 1 win");
     return_title_screen();
   
  }

  // * Draw *
  else if ((lost_player_1 == 1) && (lost_player_2 == 1))
  {
      draw_windows(21);
      vdp_putstring(5, 22, "draw game");
      return_title_screen();
    
 
  }

}


// ===================================================
// * Afficher le game over et retour à l'écran titre *
// ===================================================
void return_title_screen()
{
  snd_stopall();
  snd_startplay(4);
  vdp_waitvblank(60);
  while(get_fire(0)==0)
  {


      vdp_waitvblank(1);

  }
      vdp_disablescr(); // Ecran off
      vdp_fillvram(chrtab,0,768); // Effacer la tilemap
      set_scene(SCENE_TITLE_SCREEN); // Mode Scene game

}



// ============================
// * Tester le GM d'un joueur *
// ============================
unsigned char test_lost_player(unsigned char id_player)
{
 if ((

 // * Haut * 
 ram_map_collision[get_player_px(id_player)][get_player_py(id_player)+1]  +

 // * Bas *
 ram_map_collision[get_player_px(id_player)][get_player_py(id_player)-1]  +
 
 // * Gauche *
 ram_map_collision[get_player_px(id_player)-1][get_player_py(id_player)]  +
 
 // * Droite *
 ram_map_collision[get_player_px(id_player)+1][get_player_py(id_player)]  +

 // * Hauche Gauche *
 ram_map_collision[get_player_px(id_player)-1][get_player_py(id_player)+1] +

 // * Haut Droite *
 ram_map_collision[get_player_px(id_player)+1][get_player_py(id_player)+1] +

 // * Bas Gauche *
 ram_map_collision[get_player_px(id_player)-1][get_player_py(id_player)-1] +
 
 // * Bas Droite *
 ram_map_collision[get_player_px(id_player)+1][get_player_py(id_player)-1]

   == 8))
  {
    return 1;
  }
  else
  {
    return 0;
  }


}