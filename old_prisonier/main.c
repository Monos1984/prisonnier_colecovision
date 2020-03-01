// *****************************************
// * Nom ............. : Prisonnier        *
// * Support ......... : Colecovision      *
// * Mise à jour ..... : 10/08/2017        *
// * Programmeur ..... : Loïc Lété         *
// * Auteur .......... : Emmanuel Lorand   *
// * Graphismes ...... : Loïc Lété         *
// * Musique ......... : n/d               *
// * Bruitage ........ : n/d               *
// *****************************************

#include <string.h>

#include "header/coleco.h"
#include "header/getput1.h"
#include "header/font.h"


// -----------------------------------------------------------------
// Define adresse machin chosse qui doit fonctionner bordel de tiles
// -----------------------------------------------------------------
#define chrtab  0x1800 /* écran en linéaire */
#define chrgen  0x0000 /* table des caractères */
#define coltab  0x2000 /* couleur des caractères */
#define sprtab  0x3800
#define sprgen  0x1b00

// --------------------------
// Define de gestion de scene
// --------------------------
#define scene_titre 0 
#define scene_jeu 10
#define scene_game_over 20


// -------------------------------------
// Signature des fonctions et procédures
// -------------------------------------
void draw_player(char id);
void Turn_P1();
void Turn_P2();
void ia_turn();
void Draw_sol(char X,char Y);
void Draw_mur(char X,char Y);
void draw_curseur(char X,char Y);
void draw_map();
void Test_Game_Over();

// ---------------------------------------------------
// Variable global qui ne sont pas propres mais j'osef 
// ---------------------------------------------------
static byte PX;
static byte PY;
static byte Pindex;

static byte P1X;
static byte P1Y;
static byte P2X;
static byte P2Y;
static byte CX;
static byte CY;

static byte GMP1;
static byte GMP2;
static byte id_game_over;

static byte mvt1;
static byte scene;
static byte nb_player;


//extern const byte font_COLOR[];
//extern const  byte font_PATTERN[];

const byte shoot_sound[]=
{ 1,
0xf8,0xe4, 1,0xf2, 1,0xe4, 1,0x63,0x02,0x01,0xe5,
1,0xe4, 1,0xe5, 1,0xe4, 1,0xe5, 1,0xe4, 1,0xe5, 1,0xe4, 5,
0,0,0};


// ---------------------
// Graphismes du Curseur 
// ---------------------
const byte curseur_pattern[]=
{	
	0x1F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,	
	0xF8,0xFE,0xFE,0xFF,0xFF,0xFF,0x7F,0x7F,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,
	0xF8,0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,0xF8
};

const byte curseur_C[8] = { 0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06};

// -----------------
// Graphismes du mur 
// -----------------
const byte M_PATTERN[] = 
{
	
	0x7F,0x80,0xBF,0xBF,0xBF,0xBF,0xBF,0xBF,
	0xFE,0x01,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,
	0xBF,0xBF,0xBF,0xBF,0xBF,0xBF,0x80,0x7F,
	0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0x01,0xFE
};

const byte M_C[8] = { 0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E };

// -----------------
// Graphismes du Sol
// -----------------
const byte S_PATTERN[] = 
{
	0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
	0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF
};

const byte S_C[8] = { 0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12 };

// --------------------
// Graphismes du player
// --------------------
const byte P_PATTERN[] = 
{
	0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
	0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF
};

const byte P1_C[8] = { 0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15 };
const byte P2_C[8] = { 0x1D,0x1D,0x1D,0x1D,0x1D,0x1D,0x1D,0x1D };


const byte SPATTERNRLE[] = {
  0x81, 0xFF, 0x0B, 0xE0, 0xD0, 0xC8, 0xC4, 0xC2, 0xC1, 0xC1, 0xC2, 0xC4, 0xC8, 0xD0, 0xE0,
  0x83, 0xFF, 0x0B, 0x07, 0x0B, 0x13, 0x23, 0x43, 0x83, 0x83, 0x43, 0x23, 0x13, 0x0B, 0x07, 0x81,
  0xFF, 0xFF};
  
  
  
  
  
  
  

// --------------------------
// Gestion du plateau du jeu 
// --------------------------
static byte Level_Ram[11][11];

const byte level[121]=
{
	1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1
};




void nmi(void){
put_vram (0x1b00,sprites,128) ;
// update_sound ();
}


// -------------
// Fonction main
// -------------

void main(void)
{
	screen_mode_2_bitmap();
	screen_off();
	delay(10);
			
	
	
// Font 
	put_vram_pattern (coltab+0*8,font_COLOR,255,8);	
	put_vram_pattern ((coltab+0*8)+2048,font_COLOR,255,8);	
	put_vram_pattern ((coltab+0*8)+2048+2048,font_COLOR,255,8);
	change_pattern(0,font_PATTERN,255);

// ------------------------------
// Mise en mémoire des graphismes
// ------------------------------		
	put_vram_pattern (coltab+200*8,M_C,8,8);	
	put_vram_pattern ((coltab+200*8)+2048,M_C,8,8);	
	put_vram_pattern ((coltab+200*8)+2048+2048,M_C,8,8);	
  
	put_vram_pattern (coltab+204*8,S_C,8,8);	
	put_vram_pattern ((coltab+204*8)+2048,S_C,8,8);	
	put_vram_pattern ((coltab+204*8)+2048+2048,S_C,8,8);	
	
	put_vram_pattern (coltab+208*8,P1_C,8,8);	
	put_vram_pattern ((coltab+208*8)+2048,P1_C,8,8);	
	put_vram_pattern ((coltab+208*8)+2048+2048,P1_C,8,8);	
  
	put_vram_pattern (coltab+212*8,P2_C,8,8);	
	put_vram_pattern ((coltab+212*8)+2048,P2_C,8,8);	
	put_vram_pattern ((coltab+212*8)+2048+2048,P2_C,8,8);	
	
	put_vram_pattern (coltab+216*8,curseur_C,8,8);	
	put_vram_pattern ((coltab+216*8)+2048,curseur_C,8,8);	
	put_vram_pattern ((coltab+216*8)+2048+2048,curseur_C,8,8);	
	
	change_pattern(200,M_PATTERN,4);
	change_pattern(204,S_PATTERN,4);
	change_pattern(208,P_PATTERN,4);
	change_pattern(212,P_PATTERN,4);
	
	change_pattern(216,curseur_pattern,4);
	
	

	// Gestion du sprite test

	sprites[0].pattern = 0 ; 
	sprites[0].colour = 4 ; 
	sprites[0].x = 32 ;
	sprites[0].y =204;

	// put_vram (0x1b00,sprites,128) ;
	rle2vram(SPATTERNRLE,sprtab);
	duplicate_pattern();
	cls();
	delay(10);
	screen_on();
	
// *****************	
// * Boucle du jeu *	
// *****************	
	enable_nmi();
	
	
	scene = scene_titre;

	while(1) {
		if (scene==#scene_titre) {
			cls();
			
			print_at(11,1,"PRISONNIER");
			print_at(10,10,"(1) 1 PLAYER");
			print_at(10,12,"(2) 2 PLAYER");

			print_at(20,22,"VERSION B1");
			print_at(1,22,"OFFGAME 2017");
	
			while(scene==#scene_titre)
			{
			
				if(keypad_1 == 1)
				{
					nb_player=1;
					scene=#scene_jeu;
					cls();
					delay(10);
				}	
			
				if(keypad_1 == 2)
				{
					nb_player=2;
					scene=#scene_jeu;
					cls();
					delay(10);
				}
			
			}
			
			
			
		}
	
	
	
		else if (scene==#scene_jeu)
		{
			
			
			// *****************************	
			// * Afficher la map de départ *
			// *****************************
	 
			draw_map();
 
		// -------------------
		// Initation de départ
		// ------------------- 
			P1X=1;P1Y=1;
			P2X=9;P2Y=9;
			Level_Ram[P1X][P1Y]=1;
			Level_Ram[P2X][P2Y]=1;
			GMP1=0;
			GMP2=0;
			draw_player(1);
			draw_player(2);
			id_game_over=0;
			while(scene==#scene_jeu)
			{		

		
				Turn_P1();
				Test_Game_Over();
				delay(1);

				if ((nb_player==1) && (id_game_over==0))
				{
					ia_turn();
				}
				
				if ((nb_player==2) && (id_game_over==0))
				{
					Turn_P2();
				}	
				
				Test_Game_Over();
				delay(1);	
			}					
		}
		
		else if (scene==#scene_game_over)
		{
			while(scene==#scene_game_over)
			{	
			
			// Code dédié au Game Over
			
			
			
			
			
			}
		}
		
		
		
		
	}
	
	
	
}

// --------------------------------------------------------------------
// Fonction Draw Map qui permet d'affichage le plateau du jeu au départ
// --------------------------------------------------------------------  
void draw_map()
{
	cls();
	delay(10);
	PX=0;PY=0;
		for (Pindex=0;Pindex<121;Pindex++)
		{
			if (level[Pindex]==1)
			{	
				put_char(0+(PX*2),0+(PY*2),200);
				put_char(1+(PX*2),0+(PY*2),201);	
				put_char(0+(PX*2),1+(PY*2),202);	
				put_char(1+(PX*2),1+(PY*2),203);
				Level_Ram[PX][PY]=1;
			}

			if (level[Pindex]==0)
			{
				put_char(0+(PX*2),0+(PY*2),204);
				put_char(1+(PX*2),0+(PY*2),205);	
				put_char(0+(PX*2),1+(PY*2),206);	
				put_char(1+(PX*2),1+(PY*2),207);
				Level_Ram[PX][PY]=0;
			}
			PX++;
			
			if (PX==11)
			{
				PX=0;
				PY++;
			}		
		}
}

// -----------------------------------------------
// Fonction d'affichage du joueur 1 et du joueur 2
// -----------------------------------------------
void draw_player(char id)
{
	if (id==1)
	{
		put_char(P1X*2,P1Y*2,208);
		put_char(P1X*2+1,P1Y*2,209);	
		put_char(P1X*2,P1Y*2+1,210);	
		put_char(P1X*2+1,P1Y*2+1,211);								
	}
	
	if (id==2)
	{
		put_char(P2X*2,P2Y*2,212);
		put_char(P2X*2+1,P2Y*2,213);	
		put_char(P2X*2,P2Y*2+1,214);	
		put_char(P2X*2+1,P2Y*2+1,215);						
	}
	
}

// ----------------
// Affichage du Sol
// ----------------
void Draw_sol(char X,char Y)
{
	put_char(X*2,Y*2,204);
	put_char(X*2+1,Y*2,205);	
	put_char(X*2,Y*2+1,206);	
	put_char(X*2+1,Y*2+1,207);	
	
}

// ----------------
// Affichage du mur
// ----------------
void Draw_mur(char X,char Y)
{
	put_char(X*2,Y*2,200);
	put_char(X*2+1,Y*2,201);	
	put_char(X*2,Y*2+1,202);	
	put_char(X*2+1,Y*2+1,203);
	//play_sound(0);
}

// --------------------
// Affichage du curseur
// --------------------
 void draw_curseur(char X,char Y)
 {	 
	//put_char(X*2,Y*2,216);
	//put_char(X*2+1,Y*2,217);	
	//put_char(X*2,Y*2+1,218);	
	//put_char(X*2+1,Y*2+1,219);	 
	
	
sprites[0].x = X*16;
sprites[0].y =Y*16-1 ;

 }

// ----------------
// Tour du joueur 1
// ----------------
void Turn_P1()
{
// *******************
// * Mouvement du J1 *
// *******************
	mvt1=0;
	while(mvt1==0)
	{		
		// * MVT Droite *
		if((keypad_1 == 6) && (mvt1==0)&& (Level_Ram[P1X+1][P1Y]==0))
		{
			Level_Ram[P1X][P1Y]=0;
			Draw_sol(P1X,P1Y);
			P1X++;
			draw_player(1);
			mvt1=1;				
		}
		
		// * MVT Gauche *
		if((keypad_1 == 4) && (mvt1==0) && (Level_Ram[P1X-1][P1Y]==0))
		{
			Level_Ram[P1X][P1Y]=0;
			Draw_sol(P1X,P1Y);
			P1X--;
			draw_player(1);
			mvt1=1;				
		}
	
		// * MVT BAS *
		if((keypad_1 == 8) && (mvt1==0) && (Level_Ram[P1X][P1Y+1]==0))
		{
			Level_Ram[P1X][P1Y]=0;
			Draw_sol(P1X,P1Y);
			P1Y++;
			draw_player(1);
			mvt1=1;
		}
		
		// * MVT Haut *
		if((keypad_1 == 2) && (mvt1==0) && (Level_Ram[P1X][P1Y-1]==0))
		{
			Level_Ram[P1X][P1Y]=0;
			Draw_sol(P1X,P1Y);
			P1Y--;
			draw_player(1);
			mvt1=1;				
		}
		
		// * MVT Haut-Droite *
		if((keypad_1 == 3) && (mvt1==0) && (Level_Ram[P1X+1][P1Y-1]==0))
		{
			Level_Ram[P1X][P1Y]=0;
			Draw_sol(P1X,P1Y);
			P1Y--;
			P1X++;
			draw_player(1);
			mvt1=1;				
		}
		
		// * MVT Haut-Gauche *
		if((keypad_1 == 1) && (mvt1==0) && (Level_Ram[P1X-1][P1Y-1]==0))
		{
			Level_Ram[P1X][P1Y]=0;
			Draw_sol(P1X,P1Y);	
			P1Y--;
			P1X--;
			draw_player(1);
			mvt1=1;	
		}
		
		// * MVT Bas-Droite *
		if((keypad_1 == 9) && (mvt1==0) && (Level_Ram[P1X+1][P1Y+1]==0))
		{
			Level_Ram[P1X][P1Y]=0;
			Draw_sol(P1X,P1Y);	
			P1Y++;
			P1X++;
			draw_player(1);
			 mvt1=1;				
		}
		
				
		// * MVT Bas-Gauche *
		if((keypad_1 == 7) && (mvt1==0) && (Level_Ram[P1X-1][P1Y+1]==0))
		{
			Level_Ram[P1X][P1Y]=0;
			Draw_sol(P1X,P1Y);	
			P1Y++;
			P1X--;
			draw_player(1);
			mvt1=1;
				
		}		
	}
	
	Level_Ram[P1X][P1Y]=1;
	delay(20);
	mvt1=0;
	CX=P1X;
	CY=P1Y;
	draw_curseur(CX,CY);
	// --------------------
	// Mise en place du Mur
	// --------------------
	while(mvt1==0)
	{		 
		if((keypad_1 == 6) && (CX<9))
		{
				
			if (Level_Ram[CX][CY]==0)
			{
				Draw_sol(CX,CY);
			}
			if (Level_Ram[CX][CY]==1)
			{
				Draw_mur(CX,CY);
			}

			CX++;
			draw_player(1);
			draw_player(2);
			draw_curseur(CX,CY);
			delay(5);			 
		}
		 
		if((keypad_1 == 4) && (CX>1))
		{
			if (Level_Ram[CX][CY]==0)
			{
				Draw_sol(CX,CY);
			}
			if (Level_Ram[CX][CY]==1)
			{
				Draw_mur(CX,CY);
			}
			CX--; 
			draw_player(1);
			draw_player(2);
			draw_curseur(CX,CY);
			delay(5);	 			 
		}
				
		if((keypad_1 == 2) && (CY>1))
		{
			if (Level_Ram[CX][CY]==0)
			{
				Draw_sol(CX,CY);
			}
			
			if (Level_Ram[CX][CY]==1)
			{
				Draw_mur(CX,CY);
			}
			CY--;
			draw_player(1);
			draw_player(2);
			draw_curseur(CX,CY);
			delay(5);				 			 
		}
				
		if((keypad_1 == 8) && (CY<9))
		{
			if (Level_Ram[CX][CY]==0)
			{
				Draw_sol(CX,CY);
			}
				
			if (Level_Ram[CX][CY]==1)
			{
				Draw_mur(CX,CY);
			}
			CY++;
			draw_player(1);
			draw_player(2);
			draw_curseur(CX,CY);
			delay(5);	
			 }
		 
		if((keypad_1 == 0) && (Level_Ram[CX][CY]==0))
		{
			Level_Ram[CX][CY]=1;
			Draw_mur(CX,CY);
			sprites[0].y =204;
			mvt1=1;
			delay(5);			 			 
		}		  	
	}			
}
	
// -------------------------	
// Procedure de l'ordinateur
// -------------------------
void ia_turn()
{
	char r;
	// * Mouvement *		
	Level_Ram[P2X][P2Y]=0;
	r=rnd(0,8);
	delay(rnd(15,60));
	while(r<10)
	{	
		if  ((r==0) &&  (Level_Ram[P2X+1][P2Y]==0))
		{
			Draw_sol(P2X,P2Y);
			P2X++;
			r=10;
		}
		
		if  ((r==1) &&  (Level_Ram[P2X-1][P2Y]==0))
		{
			Draw_sol(P2X,P2Y);
			P2X--;
			r=10;
		}
		
		if  ((r==2) && (Level_Ram[P2X][P2Y-1]==0))
		{
			Draw_sol(P2X,P2Y);
			P2Y--;	
			r=10;
		}
		
		if  ((r==3) && (Level_Ram[P2X][P2Y+1]==0))
		{
			Draw_sol(P2X,P2Y);
			P2Y++;	
			r=10;
		}
		
		if  ((r==4) && (Level_Ram[P2X+1][P2Y-1]==0))
		{
			Draw_sol(P2X,P2Y);
			P2X++;
			P2Y--;	
			r=10;
		}
		
		if  ((r==5) && (Level_Ram[P2X+1][P2Y+1]==0))
		{
			Draw_sol(P2X,P2Y);
			P2X++;
			P2Y++;	
			r=10;
		}
		
		if  ((r==7) && (Level_Ram[P2X-1][P2Y-1]==0))
		{
			Draw_sol(P2X,P2Y);
			P2X--;
			P2Y--;	
			r=10;
		}
		
		if  ((r==8) && (Level_Ram[P2X-1][P2Y+1]==0))
		{
			Draw_sol(P2X,P2Y);
			P2X--;
			P2Y++;	
			r=10;
		}
		
		r++;
		if (r==9)
		{
			r=0;
		}
		
	}
		
	draw_player(2);
		
	Level_Ram[P2X][P2Y]=1;
	
	// ***************
	// * Mur de l'ia *
	// ***************
		
	r=rnd(0,8);	
	delay(rnd(20,60));
	
	while(r<10)
	{	
		if ((r==0) && (Level_Ram[P1X+1][P1Y]==0))
		{
			Level_Ram[P1X+1][P1Y]=1;
			Draw_mur(P1X+1,P1Y);		
			r=10;
		}
		
		if ((r==1) &&  (Level_Ram[P1X-1][P1Y]==0))
		{	
			Level_Ram[P1X-1][P1Y]=1;
			Draw_mur(P1X-1,P1Y);	
			r=10;
		}
		
		if ((r==2) && (Level_Ram[P1X][P1Y-1]==0))
		{
			Level_Ram[P1X][P1Y-1]=1;
			Draw_mur(P1X,P1Y-1);
			r=10;
		}
		
		if ((r==3) && (Level_Ram[P1X][P1Y+1]==0))
		{
			Level_Ram[P1X][P1Y+1]=1;
			Draw_mur(P1X,P1Y+1);
			r=10;
		}
		
		if ((r==4) && (Level_Ram[P1X+1][P1Y-1]==0))
		{
			Level_Ram[P1X+1][P1Y-1]=1;
			Draw_mur(P1X+1,P1Y-1);
			r=10;
		}
		
		if  ((r==5) && (Level_Ram[P1X+1][P1Y+1]==0))
		{
			Level_Ram[P1X+1][P1Y+1]=1;
			Draw_mur(P1X+1,P1Y+1);
			r=10;
		}
		
		if  ((r==7) && (Level_Ram[P1X-1][P1Y-1]==0))
		{
			Level_Ram[P1X-1][P1Y-1]=1;
			Draw_mur(P1X-1,P1Y-1);
			r=10;
		}
		
		if  ((r==8) && (Level_Ram[P1X-1][P1Y+1]==0))
		{
			Level_Ram[P1X-1][P1Y+1]=1;
			Draw_mur(P1X-1,P1Y+1);			
			r=10;
		}
		
		r++;
		if (r==9)
		{
			r=0;
		}
	}
			
}
	
	
	
// -------------------------
// Tour du joueur 2 Humain
// -------------------------
void Turn_P2()
{
// *******************
// * Mouvement dr J2 *
// *******************
	mvt1=0;
	while(mvt1==0)
	{		
		// * MVT Droite *
		if((keypad_2 == 6) && (mvt1==0)&& (Level_Ram[P2X+1][P2Y]==0))
		{
			Level_Ram[P2X][P2Y]=0;
			Draw_sol(P2X,P2Y);
			P2X++;
			draw_player(2);
			mvt1=1;				
		}
		
		// * MVT Gauche *
		if((keypad_2 == 4) && (mvt1==0) && (Level_Ram[P2X-1][P2Y]==0))
		{
			Level_Ram[P2X][P2Y]=0;
			Draw_sol(P2X,P2Y);
			P2X--;
			draw_player(2);
			mvt1=1;				
		}
	
		// * MVT BAS *
		if((keypad_2 == 8) && (mvt1==0) && (Level_Ram[P2X][P2Y+1]==0))
		{
			Level_Ram[P2X][P2Y]=0;
			Draw_sol(P2X,P2Y);
			P2Y++;
			draw_player(2);
			mvt1=1;
		}
		
		// * MVT Haut *
		if((keypad_2 == 2) && (mvt1==0) && (Level_Ram[P2X][P2Y-1]==0))
		{
			Level_Ram[P2X][P2Y]=0;
			Draw_sol(P2X,P2Y);
			P2Y--;
			draw_player(2);
			mvt1=1;				
		}
		
		// * MVT Haut-Droite *
		if((keypad_2 == 3) && (mvt1==0) && (Level_Ram[P2X+1][P2Y-1]==0))
		{
			Level_Ram[P2X][P2Y]=0;
			Draw_sol(P2X,P2Y);
			P2Y--;
			P2X++;
			draw_player(2);
			mvt1=1;				
		}
		
		// * MVT Haut-Gauche *
		if((keypad_2 == 1) && (mvt1==0) && (Level_Ram[P2X-1][P2Y-1]==0))
		{
			Level_Ram[P2X][P2Y]=0;
			Draw_sol(P2X,P2Y);	
			P2Y--;
			P2X--;
			draw_player(2);
			mvt1=1;	
		}
		
		// * MVT Bas-Droite *
		if((keypad_2 == 9) && (mvt1==0) && (Level_Ram[P2X+1][P2Y+1]==0))
		{
			Level_Ram[P2X][P2Y]=0;
			Draw_sol(P2X,P2Y);	
			P2Y++;
			P2X++;
			draw_player(2);
			 mvt1=1;				
		}
		
				
		// * MVT Bas-Gauche *
		if((keypad_2 == 7) && (mvt1==0) && (Level_Ram[P2X-1][P2Y+1]==0))
		{
			Level_Ram[P2X][P2Y]=0;
			Draw_sol(P2X,P2Y);	
			P2Y++;
			P2X--;
			draw_player(2);
			mvt1=1;
				
		}		
	}
	
	Level_Ram[P2X][P2Y]=1;
	delay(20);
	mvt1=0;
	CX=P2X;
	CY=P2Y;
	draw_curseur(CX,CY);
	// --------------------
	// Mise en place du Mur
	// --------------------
	while(mvt1==0)
	{		 
		if((keypad_2 == 6) && (CX<9))
		{
				
			if (Level_Ram[CX][CY]==0)
			{
				Draw_sol(CX,CY);
			}
			if (Level_Ram[CX][CY]==1)
			{
				Draw_mur(CX,CY);
			}

			CX++;
			draw_player(1);
			draw_player(2);
			draw_curseur(CX,CY);
			delay(5);			 
		}
		 
		if((keypad_2 == 4) && (CX>1))
		{
			if (Level_Ram[CX][CY]==0)
			{
				Draw_sol(CX,CY);
			}
			if (Level_Ram[CX][CY]==1)
			{
				Draw_mur(CX,CY);
			}
			CX--; 
			draw_player(1);
			draw_player(2);
			draw_curseur(CX,CY);
			delay(5);	 			 
		}
				
		if((keypad_2 == 2) && (CY>1))
		{
			if (Level_Ram[CX][CY]==0)
			{
				Draw_sol(CX,CY);
			}
			
			if (Level_Ram[CX][CY]==1)
			{
				Draw_mur(CX,CY);
			}
			CY--;
			draw_player(1);
			draw_player(2);
			draw_curseur(CX,CY);
			delay(5);				 			 
		}
				
		if((keypad_2 == 8) && (CY<9))
		{
			if (Level_Ram[CX][CY]==0)
			{
				Draw_sol(CX,CY);
			}
				
			if (Level_Ram[CX][CY]==1)
			{
				Draw_mur(CX,CY);
			}
			CY++;
			draw_player(1);
			draw_player(2);
			draw_curseur(CX,CY);
			delay(5);	
			 }
		 
		if((keypad_2 == 0) && (Level_Ram[CX][CY]==0))
		{
			Level_Ram[CX][CY]=1;
			Draw_mur(CX,CY);
			sprites[0].y =204;
			mvt1=1;
			delay(5);			 			 
		}		  	
	}			
}	
	
	
	
	
	
// -------------	
// - Game Over -
// -------------
	
void Test_Game_Over()
{
	char valeur_bloc;
	//  * Test de blocage du joueur 1 *
	valeur_bloc = 
		Level_Ram[P1X+1][P1Y] +
		Level_Ram[P1X-1][P1Y] +
		Level_Ram[P1X][P1Y+1] +
		Level_Ram[P1X][P1Y-1] +
		Level_Ram[P1X-1][P1Y-1] +
		Level_Ram[P1X-1][P1Y+1] +
		Level_Ram[P1X+1][P1Y+1] +
		Level_Ram[P1X+1][P1Y-1];
					
	if (valeur_bloc==8)
	{
		GMP1=1;
	}
	
	//  * Test de blocage du joueur 2 *
	valeur_bloc = 
		Level_Ram[P2X+1][P2Y]+
		Level_Ram[P2X-1][P2Y]+
		Level_Ram[P2X][P2Y+1]+
		Level_Ram[P2X][P2Y-1]+
		Level_Ram[P2X-1][P2Y-1]+
		Level_Ram[P2X-1][P2Y+1]+
		Level_Ram[P2X+1][P2Y+1]+
		Level_Ram[P2X+1][P2Y-1];
					
	if (valeur_bloc==8)
	{
		GMP2=1;
	}
		
	if ((GMP1==1) && (GMP2==1))
	{
		id_game_over=3;	
		cls();
		print_at(10,10,"DRAW GAMES");
		delay(120);
		scene=#scene_titre;
	}
		
	if ((GMP1==1) && (GMP2==0))
	{
		cls();
		id_game_over=2;
	print_at(10,10,"PLAYER 2 WIN");
		delay(120);		
				
scene=#scene_titre;		
	}
		
	if ((GMP1==0) && (GMP2==1))
	{
		cls();
		id_game_over=1;		
			print_at(10,10,"PLAYER 1 WIN");
		delay(120);	
	scene=#scene_titre;		
	}
		
		
}
	
	
	
	
