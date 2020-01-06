#ifndef _MAIN_
#define _MAIN_

// ====================
// * Fichier includes *
// ====================
#include <coleco.h>
#include "data.h"

// ---------------------
// * - fichier scene - *
// ---------------------
#include "scene_manager.h"
#include "scene_game.h"

// -------------------------
// * - Les fichier class - *
// -------------------------
#include "class_map.h"
#include "class_player.h"
#include "class_input.h"


// * test - *


void title_screen();
void credit();


// =============================
// *  Les Defines du programme *
// =============================

// -----------------
// * Color Palette * 
// -----------------
#define c_invisible     0
#define c_black         1
#define c_medium_green  2
#define c_light_green   3
#define c_dark_blue     4
#define c_light_blue    5
#define c_dark_red      6
#define c_cyan          7
#define c_medium_red    8
#define c_light_red     9
#define c_dark_yellow  10
#define c_light_yellow 11
#define c_dark_green   12
#define c_magenta      13
#define c_grey         14
#define c_white        15


#endif
