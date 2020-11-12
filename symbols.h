// VAC: Vincent Jiang, Alice Liu, Cullen Ye
#include "songs.h"

#ifndef SYMBOLS_H
#define SYMBOLS_H

struct Symbols {
  struct song_node *library[27];
};

struct Symbols *new_Symbols();
struct Symbols *addSong(struct Symbols *songlib, struct song_node *newsong);
void print_Symbols(struct Symbols *lib);
struct song_node *search(struct Symbols *lib, char *name, char *artist); 
struct song_node *search_artist(struct Symbols *lib, char *artist);
void print_Letter_Symbols(struct Symbols *lib, char c);
void print_Artist_Symbols(struct Symbols *lib, char *a);
struct Symbols *remove_song(struct Symbols *lib, char *name, char *artist);
void clear_lib(struct Symbols *lib);
void shuffle(struct Symbols *lib);

#endif
