// VAC: Vincent Jiang, Alice Liu, Cullen Ye

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "symbols.h"
#include "songs.h"

// Creates a new playlist.
struct Symbols *new_Symbols()
{
  struct Symbols *newsymbols = malloc(sizeof(struct Symbols));
  int i;
  for (i = 0; i < 27; i++)
  {
    (newsymbols->library)[i] = NULL;
  }
  return newsymbols;
}

// Adds a song to the playlist according to the first letter of the artist's name.
// This adds the song to the front of its respective alphabet list.
struct Symbols *addSong(struct Symbols *songlib, struct song_node *newsong)
{
  int x = toupper((newsong->artist)[0] - 65);
  if ((songlib->library)[x] == NULL)
    //insert_song_sorted((songlib->library)[x], newsong->name, newsong->artist);
    (songlib->library)[x] = newsong;
  else
    insert_song_sorted((songlib->library)[x], newsong->name, newsong->artist);
    //printlist_Song(songlib->library[x]);
  return songlib;
}

// Prints out the entire playlist alphabetically.
void print_Symbols(struct Symbols *lib)
{
  int i;
  for (i = 0; i < 27; i++)
  {
    if ((lib->library)[i] != NULL)
    {
      printf("%c:\n", 'A' + i);
      printlist_Song((lib->library)[i]);
      printf("\n");
    }
  }
}

// Search for a song given song and artist name (as a pointer)
struct song_node *search (struct Symbols *lib, char *name, char *artist) {
  int x = toupper(artist[0] - 65);
  return find_song((lib->library)[x], name, artist);
}

struct song_node *search_artist (struct Symbols *lib, char *artist) {
  int x = toupper(artist[0] - 65);
  return find_first_artist((lib->library)[x], artist);
}

// Prints out the songs in the playlist under a specific letter.
void print_Letter_Symbols(struct Symbols *lib, char c)
{
  int x = toupper(c) - 65;
  if ((lib->library)[x] != NULL)
  {
    printf("%c:\n", 'A' + x);
    printlist_Song((lib->library)[x]);
    printf("\n");
  }
  else
  {
    if (x != 26)
      printf("%c:\nEmpty.\n\n", 'A' + x);
    else
      printf("Other:\nEmpty.\n\n");
  }
}

// print out all the songs of a certain artist
void print_Artist_Symbols(struct Symbols *lib, char *a)
{
  int x = toupper(a[0]) - 65;
  if ((lib->library)[x] != NULL)
  {
    while ((lib->library)[x])
    {
      if (strcmp((lib->library)[x]->artist, a) == 0)
      {
        printf("Artist: %s\tSong: %s\n", (lib->library)[x]->artist, (lib->library)[x]->name);
      }
      (lib->library)[x] = (lib->library)[x]->next;
    }
  }
}

// shuffle - print out a series of random chosen songs
void shuffle(struct Symbols *lib)
{
  srand(time(NULL));
  struct Symbols *lib2 = lib;
  int i;
  for (i = 0; i < 27; i++)
  {
    if ((lib2->library)[i] != NULL)
    {
      while ((lib2->library)[i])
      {
        if (rand() % 100 > 50)
          printf("Artist: %s\tSong: %s\n", (lib2->library)[i]->artist, (lib2->library)[i]->name);
        (lib2->library)[i] = (lib2->library)[i]->next;
      }
    }
  }
}

// delete a song
struct Symbols *remove_song(struct Symbols *lib, char *name, char *artist)
{
  //struct song_node *song = new_Song(name, artist);
  int x = toupper((artist)[0] - 65);
  (lib->library)[x] = remove_node((lib->library)[x], name, artist);
  return lib;
}

// clear the library
void clear_lib(struct Symbols *lib)
{
  int i;
  for (i = 0; i < 27; i++)
  {
    if ((lib->library)[i])
      (lib->library)[i] = free_list((lib->library)[i]);
  }
}
