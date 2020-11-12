// VAC: Vincent Jiang, Alice Liu, Cullen Ye

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "symbols.h"
#include "songs.h"

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
// before was struct song_node
struct Symbols *addSong(struct Symbols *songlib, struct song_node *newsong) {
  int x = toupper((newsong->artist)[0]-65);
  if ((songlib->library)[x]==NULL) (songlib->library)[x] = newsong;
  else insert_song_sorted((songlib->library)[x], newsong);
  // before was (songlib->library)[x]
  return songlib;
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
  }
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

// print out all the songs of a certain artist 
void print_Artist_Symbols(struct Symbols *lib, char *a) {
  int x = toupper(a[0])-65;
  if ((lib->library)[x] != NULL) {
    while ((lib->library)[x]) {
      if (strcmp( (lib->library)[x]->artist, a ) == 0) {
        printf("Artist: %s\tSong: %s\n", (lib->library)[x]->artist, (lib->library)[x]->name);
      }
      (lib->library)[x] = (lib->library)[x]->next;
    }
  }
}

// clear the library 
void clear_lib(struct Symbols *lib) {
  int i;
  while (i < 27) {
    if ((lib->library)[i]) 
      (lib->library)[i] = free_list((lib->library)[i]);
    i++;
  }
}

// delete a song
struct Symbols *remove_song(struct Symbols *lib, struct song_node *song) {
  int x = toupper((song->artist)[0]-65);
  (lib->library)[x] = remove_node((lib->library)[x], song);
  return lib;
}

// shuffle - print out a series of random chosen songs
struct Symbols *shuffle(struct Symbols *lib) {
  srand(time(NULL));
  int i;
  for (i=0; i<27; i++) {
    if ((lib->library)[i]!=NULL) {
      while ((lib->library)[i]) {
        if (rand() % 100 > 50)
          printf("Artist: %s\tSong: %s\n", (lib->library)[i]->artist, (lib->library)[i]->name);
        (lib->library)[i] = (lib->library)[i]->next; 
      }
    }
  }
}


