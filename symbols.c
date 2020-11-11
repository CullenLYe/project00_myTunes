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

// Prints out the entire playlist alphabetically.
void print_Symbols(struct Symbols *lib) {
  int i;
  for (i=0; i<27; i++) {
    if ((lib->library)[i]!=NULL) {
      printf("%c:\n", 'A'+i);
      printlist_Song((lib->library)[i]);
      printf("\n");
    }
    else {
      if (i!=26) printf("%c:\nEmpty.\n\n", 'A'+i);
      else printf("Other:\nEmpty.\n\n");
    }
  }
}
