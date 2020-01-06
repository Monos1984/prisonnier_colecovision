/*****************************************************************
 * Nom ................. : scene_title_screen.c                  *
  * Role ................: gestion de l'écran titre              *
 * Auteur .............. : Monos                                 *
 * Version ............. : 18/11/2019                            *
 *****************************************************************/

// ==================================
// ** Fichier include du programme **
// ==================================
#include "include/main.h"

// ==========================
// * Procedure title_screen *
// ==========================
void title_screen()
{

  vdp_disablescr();	
	vdp_setmode2txt();
	
	// Put image in vram  and duplicate to the 2nd & 3rd zone
	vdp_dan2vram (TILtitle_screen, chrgen); // characters
	vdp_dan2vram (COLtitle_screen, coltab); // colors
	vdp_dan2vram (MAPtitle_screen, chrtab); // map

	vdp_duplicatevram();

  snd_startplay(1);
  snd_startplay(7);
  snd_startplay(8);
	vdp_enablescr();
  // ===============================
  // ** Boucle du du title_screen **
  // ===============================
  while(get_scene() == SCENE_TITLE_SCREEN)
  {

    // -----------------
    // * Lancer le jeu *
    // -----------------
    if  (get_fire(0))
    {
      snd_startplay(2);
      vdp_waitvblank(20);  
      snd_stopall();
    	vdp_disablescr(); // Ecran off
      vdp_fillvram(chrtab,0,768); // Effacer la tilemap
      set_scene(SCENE_GAME); // Mode Scene game
      
    }

    else if (get_fire_left(0))
    {
      snd_startplay(6);
      vdp_waitvblank(20);
    	vdp_disablescr(); // Ecran off
      vdp_fillvram(chrtab,0,768); // Effacer la tilemap
      set_scene(SCENE_CREDIT); // Mode Scene game
      
    }

   vdp_waitvblank(1);

  }


}


void credit()
{
// --------------------------------------
  // * Chargement des assets colecovision *
  // --------------------------------------
  vdp_rle2vram (rle_data_tile,chrgen);	
  vdp_rle2vram (rle_color_tilset,coltab);

  vdp_duplicatevram();
  vdp_enablescr();

  vdp_putstring(11, 2,  "Prisonnier");
  vdp_putstring(1, 4,  "Auteur....... : Bernd Kienitz");
  vdp_putstring(1, 5,  "Programmation : Jean Monos");
  
  vdp_putstring(1, 6,  "Graphismes... : Jean Monos");
  vdp_putstring(1, 7,  "Musiques..... : Amy Purple");
  vdp_putstring(1, 8,  "Sound FX..... : Amy Purple");
  vdp_putstring(1, 10, "Lib.......... : pvcollib");

  vdp_putstring(1, 11, "............. : alekmaul");



  vdp_putstring(1, 14, "Divers....... : Amy Purple");
  vdp_putstring(1, 15, "............. : Emmanuel Lorand");
  vdp_putstring(26,23 , "1,0,0");

  // ===============================
  // ** Boucle du du title_screen **
  // ===============================
  while(get_scene() == SCENE_CREDIT)
  {

  

    // -----------------------
    // * Retour title screen *
    // -----------------------
    if  (get_fire(0))
    {
    	vdp_disablescr(); // Ecran off
      vdp_fillvram(chrtab,0,768); // Effacer la tilemap
      set_scene(SCENE_TITLE_SCREEN); // Mode Scene game
      
    }

   vdp_waitvblank(1);

  }










}