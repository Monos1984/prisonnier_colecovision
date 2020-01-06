/*****************************************************************
 * Jeu ................. : Prisonnier                            *
 * Nom ................. : main.c                                *
 * Role ................ : lanceur du programme                  *
 * Auteur .............. : Monos                                 *
 * Version ............. : 0.0.0                                 *
 * Cible ............... : Colecovision                          *
 * mise à jour ......... : 05/01/20                              *
 *****************************************************************/

// ==================================
// ** Fichier include du programme **
// ==================================
#include "include/main.h"


// ==================
// * Gestion du NMI *
// ==================
void nmi (void)
{
  spr_update();
}

// * Son déclaration *
const sound_t snd_table[]={
	{ musique_ch0,		  				SOUNDAREA1},	// sound entry 1	

	{ menu_selection,			  				SOUNDAREA4},	// sound entry 2	
	{ snd_space_break,			  				SOUNDAREA4},	// sound entry 3	
	{ snd_victory,			  				SOUNDAREA4},	// sound entry 4	
	{ snd_move_invalid,			  				SOUNDAREA4},	// sound entry 5	
	{ snd_return,			  				SOUNDAREA4},	// sound entry 6	
  { musique_ch2,			  				SOUNDAREA2},	// sound entry 7	
  { musique_ch3,			  				SOUNDAREA3},	// sound entry 8	
};


// ==================
// * Fonction Main  *
// ==================
void main (void) 
{

  // ==========================
  // * Initation du programme *
  // ==========================
  set_scene(SCENE_INIT); 

  // =================
  // * Boucle du jeu *
  // =================
	while(1) 
  {

    // -----------------------
    // * Gestion du Workflow *
    // -----------------------
    if (get_scene() == SCENE_INIT)
    {
        vdp_setmode2txt(); // Passage en mode 2 texte
        	// Put sound table and mute all channel
          snd_settable(snd_table);
          snd_stopall();
        set_scene(SCENE_TITLE_SCREEN);

    }
    
    else if (get_scene() == SCENE_TITLE_SCREEN)
    {
      
      title_screen();
    	vdp_waitvblank(1);
    }
     
    else if (get_scene() == SCENE_GAME)
    {
      scene_game();
    	vdp_waitvblank(1);
    }

    else if (get_scene() == SCENE_CREDIT)
    {
      credit();
    	vdp_waitvblank(1);
    }
    
    
	}
	 
}
