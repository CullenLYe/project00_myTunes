// VAC: Vincent Jiang, Alice Liu, Cullen Ye

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "symbols.h"

// Creates a new playlist.
struct Symbols *new_Symbols() {
  struct Symbols *newsymbols = malloc(sizeof(struct Symbols));
  int i;
  for (i=0; i<27; i++) {
    (newsymbols->library)[i]=NULL;
  }
  return newsymbols;
}

// Adds a song to the playlist according to the first letter of the artist's name.
// This adds the song to the front of its respective alphabet list.
struct song_node *addSong(struct Symbols *songlib, struct song_node *newsong) {
  int x = toupper((newsong->artist)[0]-65);
  if ((songlib->library)[x]==NULL) (songlib->library)[x] = newsong;
  else insert_front(newsong, (songlib->library)[x]);
  return (songlib->library)[x];
}

// Prints out the songs in the playlist under a specific letter.
void print_Letter_Symbols(struct Symbols *lib, char c) {
  int x = toupper(c)-65;
  if ((lib->library)[x]!=NULL) {
    printf("%c:\n", 'A'+x);
    printlist_Song((lib->library)[x]);
    printf("\n");
  }
  else {
    if (x!=26) printf("%c:\nEmpty.\n\n", 'A'+x);
    else printf("Other:\nEmpty.\n\n");
  }
}

// Prints out the entire playlist alphabetically.
void print_Symbols(struct Symbols *lib) {
  int i;
  for (i=0; i<27; i++) {
    print_Letter_Symbols(lib, 'A'+i);
  }
}
