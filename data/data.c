/********************************************/
/*                                          */
/*   GRAPHICS TABLES  -  WIN ICVGM v3.00    */
/*                                          */
/*        WARNING : RLE COMPRESSION         */
/*                                          */
/********************************************/

#include <coleco.h>

byte NAMERLE[] = {
  0xFE, 0x20, 0x8B, 0x20, 0x03, 0x99, 0x20, 0x99, 0x99, 0x9A, 0x20, 0x81, 0x99, 0x02, 0x20,
  0x99, 0x99, 0x90, 0x20, 0x84, 0x99, 0x83, 0x20, 0x8F, 0x99, 0x86, 0x20, 0x00, 0x90, 0x94, 0x98,
  0x00, 0xA0, 0x88, 0x99, 0x0D, 0x91, 0x99, 0x50, 0x4C, 0x41, 0x59, 0x45, 0x52, 0x20, 0x31, 0x99,
  0x57, 0x49, 0x4E, 0x85, 0x99, 0x81, 0x20, 0x00, 0xA1, 0x87, 0x20, 0x01, 0x99, 0x92, 0x94, 0x9A,
  0x00, 0xA2, 0x87, 0x20, 0xA1, 0x99, 0x87, 0x20, 0x8A, 0x99, 0x94, 0x20, 0x89, 0x99, 0x94, 0x20,
  0x8B, 0x99, 0x9A, 0x20, 0x81, 0x99, 0x94, 0x20, 0x81, 0x8E, 0x86, 0x20, 0x81, 0x99, 0x03, 0x82,
  0x8A, 0x93, 0x9B, 0x90, 0x20, 0x81, 0x8E, 0x86, 0x20, 0x05, 0x99, 0x20, 0x83, 0x8B, 0x94, 0x9C,
  0x83, 0x20, 0x00, 0x00, 0x8B, 0x20, 0x81, 0x8E, 0x83, 0x20, 0x03, 0x9A, 0x20, 0x20, 0x99, 0x95,
  0x20, 0x81, 0x8E, 0x9D, 0x20, 0x81, 0x8E, 0x9D, 0x20, 0x81, 0x8E, 0x9D, 0x20, 0x81, 0x8E, 0x9D,
  0x20, 0x8E, 0x8E, 0x90, 0x20, 0x8E, 0x86, 0x8A, 0x20, 0xFF};

byte PATTERNRLE[] = {
  0xA7, 0x00, 0x09, 0x3F, 0x7F, 0xFF, 0xFF, 0xF3, 0xF3, 0xF0, 0xF0, 0x00, 0x80, 0x83, 0xC0,
  0x81, 0x00, 0x03, 0x3F, 0x7F, 0xFF, 0xFF, 0x83, 0xF3, 0x01, 0x00, 0x80, 0x85, 0xC0, 0x87, 0xF0,
  0x82, 0xFF, 0x81, 0xF0, 0x82, 0xFF, 0x82, 0xC0, 0x84, 0x00, 0x82, 0xF1, 0x82, 0x7B, 0x81, 0x3F,
  0x82, 0xE0, 0x82, 0xC0, 0x81, 0x80, 0x11, 0x1F, 0x3F, 0x7F, 0x79, 0x78, 0x7F, 0x7F, 0x3F, 0x80,
  0xC0, 0xE0, 0xE0, 0x00, 0x80, 0xC0, 0xE0, 0xF3, 0xF3, 0x82, 0xFB, 0x82, 0xFF, 0x87, 0xC0, 0x81,
  0xF3, 0x81, 0xFF, 0x03, 0x7F, 0x3F, 0x00, 0x00, 0x83, 0xC0, 0x00, 0x80, 0x82, 0x00, 0x81, 0xF0,
  0x83, 0xFF, 0x83, 0x00, 0x83, 0xC0, 0x81, 0x00, 0x00, 0x3F, 0x82, 0x1F, 0x81, 0x0E, 0x81, 0x00,
  0x00, 0x80, 0x86, 0x00, 0x85, 0xF0, 0x81, 0x00, 0x07, 0x1F, 0x01, 0x79, 0x7F, 0x3F, 0x1F, 0x00,
  0x00, 0x83, 0xE0, 0x04, 0xC0, 0x80, 0x00, 0x00, 0xFF, 0x82, 0xF7, 0x81, 0xF3, 0x81, 0x00, 0x85,
  0xC0, 0x81, 0x00, 0x08, 0x7E, 0x81, 0xBD, 0xA1, 0xA1, 0xBD, 0x81, 0x7E, 0x1F, 0x82, 0x04, 0x83,
  0x00, 0x03, 0x44, 0x6C, 0x54, 0x54, 0x8B, 0x00, 0x84, 0x20, 0x02, 0x00, 0x20, 0x00, 0x82, 0x50,
  0x84, 0x00, 0x81, 0x50, 0x1D, 0xF8, 0x50, 0xF8, 0x50, 0x50, 0x00, 0x20, 0x78, 0xA0, 0x70, 0x28,
  0xF0, 0x20, 0x00, 0xC0, 0xC8, 0x10, 0x20, 0x40, 0x98, 0x18, 0x00, 0x40, 0xA0, 0xA0, 0x40, 0xA8,
  0x90, 0x68, 0x00, 0x82, 0x20, 0x84, 0x00, 0x01, 0x20, 0x40, 0x82, 0x80, 0x04, 0x40, 0x20, 0x00,
  0x20, 0x10, 0x82, 0x08, 0x10, 0x10, 0x20, 0x00, 0x20, 0xA8, 0x70, 0x20, 0x70, 0xA8, 0x20, 0x00,
  0x00, 0x20, 0x20, 0xF8, 0x20, 0x20, 0x85, 0x00, 0x81, 0x20, 0x00, 0x40, 0x83, 0x00, 0x00, 0xF8,
  0x89, 0x00, 0x13, 0x20, 0x00, 0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x70, 0x88, 0x98,
  0xA8, 0xC8, 0x88, 0x70, 0x00, 0x20, 0x60, 0x83, 0x20, 0x2D, 0x70, 0x00, 0x70, 0x88, 0x08, 0x30,
  0x40, 0x80, 0xF8, 0x00, 0xF8, 0x08, 0x10, 0x30, 0x08, 0x88, 0x70, 0x00, 0x10, 0x30, 0x50, 0x90,
  0xF8, 0x10, 0x10, 0x00, 0xF8, 0x80, 0xF0, 0x08, 0x08, 0x88, 0x70, 0x00, 0x38, 0x40, 0x80, 0xF0,
  0x88, 0x88, 0x70, 0x00, 0xF8, 0x08, 0x10, 0x20, 0x82, 0x40, 0x0F, 0x00, 0x70, 0x88, 0x88, 0x70,
  0x88, 0x88, 0x70, 0x00, 0x70, 0x88, 0x88, 0x78, 0x08, 0x10, 0xE0, 0x82, 0x00, 0x02, 0x20, 0x00,
  0x20, 0x84, 0x00, 0x0C, 0x20, 0x00, 0x20, 0x20, 0x40, 0x00, 0x10, 0x20, 0x40, 0x80, 0x40, 0x20,
  0x10, 0x82, 0x00, 0x02, 0xF8, 0x00, 0xF8, 0x82, 0x00, 0x29, 0x40, 0x20, 0x10, 0x08, 0x10, 0x20,
  0x40, 0x00, 0x70, 0x88, 0x10, 0x20, 0x20, 0x00, 0x20, 0x00, 0x70, 0x88, 0xA8, 0xB8, 0xB0, 0x80,
  0x78, 0x00, 0x20, 0x50, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x00, 0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88,
  0xF0, 0x00, 0x70, 0x88, 0x82, 0x80, 0x03, 0x88, 0x70, 0x00, 0xF0, 0x84, 0x88, 0x0D, 0xF0, 0x00,
  0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0xF8, 0x00, 0xF8, 0x80, 0x80, 0xF0, 0x82, 0x80, 0x01, 0x00,
  0x78, 0x82, 0x80, 0x03, 0x98, 0x88, 0x78, 0x00, 0x82, 0x88, 0x00, 0xF8, 0x82, 0x88, 0x01, 0x00,
  0x70, 0x84, 0x20, 0x01, 0x70, 0x00, 0x84, 0x08, 0x0A, 0x88, 0x70, 0x00, 0x88, 0x90, 0xA0, 0xC0,
  0xA0, 0x90, 0x88, 0x00, 0x85, 0x80, 0x05, 0xF8, 0x00, 0x88, 0xD8, 0xA8, 0xA8, 0x82, 0x88, 0x09,
  0x00, 0x88, 0x88, 0xC8, 0xA8, 0x98, 0x88, 0x88, 0x00, 0x70, 0x84, 0x88, 0x05, 0x70, 0x00, 0xF0,
  0x88, 0x88, 0xF0, 0x82, 0x80, 0x01, 0x00, 0x70, 0x82, 0x88, 0x14, 0xA8, 0x90, 0x68, 0x00, 0xF0,
  0x88, 0x88, 0xF0, 0xA0, 0x90, 0x88, 0x00, 0x70, 0x88, 0x80, 0x70, 0x08, 0x88, 0x70, 0x00, 0xF8,
  0x85, 0x20, 0x00, 0x00, 0x85, 0x88, 0x01, 0x70, 0x00, 0x84, 0x88, 0x02, 0x50, 0x20, 0x00, 0x82,
  0x88, 0x81, 0xA8, 0x0D, 0xD8, 0x88, 0x00, 0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x00, 0x88,
  0x88, 0x50, 0x83, 0x20, 0x09, 0x00, 0xF8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8, 0x00, 0xF8, 0x84,
  0xC0, 0x0A, 0xF8, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00, 0xF8, 0x84, 0x18, 0x00,
  0xF8, 0x82, 0x00, 0x02, 0x20, 0x50, 0x88, 0x89, 0x00, 0x03, 0xF8, 0x40, 0x20, 0x10, 0x86, 0x00,
  0x04, 0x70, 0x88, 0xF8, 0x88, 0x88, 0x82, 0x00, 0x04, 0xF0, 0x48, 0x70, 0x48, 0xF0, 0x82, 0x00,
  0x00, 0x78, 0x82, 0x80, 0x00, 0x78, 0x82, 0x00, 0x00, 0xF0, 0x82, 0x48, 0x00, 0xF0, 0x82, 0x00,
  0x04, 0xF0, 0x80, 0xE0, 0x80, 0xF0, 0x82, 0x00, 0x04, 0xF0, 0x80, 0xE0, 0x80, 0x80, 0x82, 0x00,
  0x04, 0x78, 0x80, 0xB8, 0x88, 0x70, 0x82, 0x00, 0x81, 0x88, 0x02, 0xF8, 0x88, 0x88, 0x82, 0x00,
  0x00, 0xF8, 0x82, 0x20, 0x00, 0xF8, 0x82, 0x00, 0x04, 0x70, 0x20, 0x20, 0xA0, 0xE0, 0x82, 0x00,
  0x04, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x82, 0x00, 0x83, 0x80, 0x00, 0xF8, 0x82, 0x00, 0x04, 0x88,
  0xD8, 0xA8, 0x88, 0x88, 0x82, 0x00, 0x04, 0x88, 0xC8, 0xA8, 0x98, 0x88, 0x82, 0x00, 0x00, 0xF8,
  0x82, 0x88, 0x00, 0xF8, 0x82, 0x00, 0x04, 0xF0, 0x88, 0xF0, 0x80, 0x80, 0x82, 0x00, 0x04, 0xF8,
  0x88, 0xA8, 0x90, 0xE0, 0x82, 0x00, 0x04, 0xF8, 0x88, 0xF8, 0xA0, 0x90, 0x82, 0x00, 0x04, 0x78,
  0x80, 0x70, 0x08, 0xF0, 0x82, 0x00, 0x00, 0xF8, 0x83, 0x20, 0x82, 0x00, 0x83, 0x88, 0x00, 0x70,
  0x82, 0x00, 0x81, 0x88, 0x02, 0x90, 0xA0, 0x40, 0x82, 0x00, 0x81, 0x88, 0x02, 0xA8, 0xD8, 0x88,
  0x82, 0x00, 0x04, 0x88, 0x60, 0x20, 0x60, 0x88, 0x82, 0x00, 0x01, 0x88, 0x50, 0x82, 0x20, 0x82,
  0x00, 0x20, 0xF8, 0x10, 0x20, 0x40, 0xF8, 0x00, 0x38, 0x40, 0x20, 0xC0, 0x20, 0x40, 0x38, 0x00,
  0x40, 0x20, 0x10, 0x08, 0x10, 0x20, 0x40, 0x00, 0xE0, 0x10, 0x20, 0x18, 0x20, 0x10, 0xE0, 0x00,
  0x40, 0xA8, 0x10, 0x84, 0x00, 0x06, 0xA8, 0x50, 0xA8, 0x50, 0xA8, 0x50, 0xA8, 0x91, 0x00, 0x01,
  0x05, 0x2D, 0x89, 0x6D, 0x05, 0x2D, 0x0D, 0x00, 0x00, 0x1F, 0x3F, 0x89, 0x7F, 0x03, 0x3F, 0x1F,
  0x00, 0xFF, 0x82, 0x80, 0x00, 0xFF, 0x82, 0x01, 0x98, 0x00, 0x01, 0xB0, 0xB4, 0x89, 0xB6, 0x05,
  0xB4, 0xB0, 0x00, 0x00, 0xF8, 0xFC, 0x89, 0xFE, 0x0A, 0xFC, 0xF8, 0x00, 0xAA, 0x55, 0xAA, 0x55,
  0xAA, 0x55, 0xAA, 0x55, 0x87, 0x00, 0x02, 0xFF, 0x80, 0xBF, 0x91, 0xA0, 0x05, 0xBF, 0x80, 0xFF,
  0x02, 0x05, 0x2D, 0x89, 0x6D, 0x01, 0x2D, 0x0D, 0x98, 0x00, 0x02, 0xFF, 0x00, 0xFF, 0x91, 0x00,
  0x05, 0xFF, 0x00, 0xFF, 0x00, 0xB0, 0xB4, 0x89, 0xB6, 0x01, 0xB4, 0xB0, 0x98, 0x00, 0x02, 0xFF,
  0x01, 0xFD, 0x91, 0x05, 0x02, 0xFD, 0x01, 0xFF, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00,
  0xFE, 0x00, 0xEC, 0x00, 0xFF};

byte COLORRLE[] = {
  0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE,
  0x41, 0x97, 0x41, 0x9F, 0x1E, 0x87, 0x74, 0x97, 0x41, 0x9F, 0x1E, 0x87, 0x24, 0x87, 0x41, 0x97,
  0x61, 0x8F, 0x15, 0x97, 0x41, 0x87, 0x61, 0x87, 0xB1, 0x87, 0x61, 0x8F, 0x15, 0x97, 0x41, 0x97,
  0x61, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xEC, 0x41, 0xFF};

byte SPATTERNRLE[] = {
  0x05, 0xFC, 0xF0, 0xC0, 0xC0, 0x80, 0x80, 0x83, 0x00, 0x81, 0x80, 0x81, 0xC0, 0x07, 0xF0,
  0xFC, 0x3F, 0x0F, 0x03, 0x03, 0x01, 0x01, 0x83, 0x00, 0x81, 0x01, 0x81, 0x03, 0x41, 0x0F, 0x3F,
  0x00, 0x01, 0x01, 0x0D, 0x3B, 0x3F, 0x1F, 0x07, 0x32, 0x78, 0x7C, 0x73, 0x70, 0x77, 0x77, 0x20,
  0x00, 0x80, 0x80, 0xB0, 0xDC, 0xFC, 0xF8, 0xE0, 0x4C, 0x1C, 0x26, 0xC6, 0x5E, 0xDC, 0x08, 0xE0,
  0x01, 0x02, 0x0E, 0x32, 0x44, 0x40, 0x20, 0x38, 0x4D, 0x87, 0x83, 0x8C, 0x8F, 0x88, 0x88, 0x5F,
  0x80, 0x40, 0x70, 0x4C, 0x22, 0x02, 0x04, 0x1C, 0xB2, 0xE2, 0xD9, 0x39, 0xA1, 0x22, 0xF4, 0x1C,
  0xFF};

int SPRITESINITSIZE = 12;

byte SPRITESINIT[] = {
  204, 0, 0, 8,
  204, 0, 4, 6,
  204, 0, 8, 7};
