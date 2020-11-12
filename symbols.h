// VAC: Vincent Jiang, Alice Liu, Cullen Ye
#include "songs.h"

#ifndef SYMBOLS_H
#define SYMBOLS_H

struct Symbols {
  struct song_node *library[27];
};

struct Symbols *new_Symbols();

struct Symbols *addSong(struct Symbols *songlib, struct song_node *newsong);

void print_Letter_Symbols(struct Symbols *lib, char c);

void print_Symbols(struct Symbols *lib);

void clear_lib(struct Symbols *lib);

void print_Artist_Symbols(struct Symbols *lib, char *a);

struct Symbols *remove_song(struct Symbols *lib, struct song_node *song);

struct Symbols *shuffle(struct Symbols *lib);

#endif
