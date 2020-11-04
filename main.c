// VAC: Vincent Jiang, Alice Liu, Cullen Ye

#include <stdlib.h>
#include <stdio.h>
#include "songs.h"
//#include "symbols.h"

int main() {
  printf("Creating song1...\n");
  struct song_node *song1 = new_Song("Happy", "Pharrell Williams");
  printf("testing print_Song\n");
  printlist_Song(song1);

  printf("\nCreating song2...\n");
  struct song_node *song2 = new_Song("Can't Stop the Feeling", "Justin Timberlake");
  printlist_Song(song2);

  printf("\nInserting song2 in front of song1, so the linked list is song2->song1\n");
  insert_front(song1, song2);
  printf("song2:\n");
  printlist_Song(song2);
  printf("song2->next:\n");
  printlist_Song(song2->next);

  printf("\ninserting more songs...\n");
  printf("testing insert_song_sorted\n");
  struct song_node *song3 = new_Song("A Head Full of Dreams", "Coldplay");
  struct song_node *song4 = new_Song("Chlorine", "Twenty One Pilots");
  struct song_node *song5 = new_Song("Shallow", "Lady Gaga, Bradley Cooper");
  struct song_node *song6 = new_Song("Yellow", "Coldplay");
  struct song_node *song7 = new_Song("Viva La Vida", "Lady Gaga, Bradley Cooper");

  printf("\nprinting song list\n");
  struct song_node *songlist = insert_song_sorted(song2, song3);
  printlist_Song(songlist);

  printf("\nprinting song list\n");
  songlist = insert_song_sorted(songlist, song4);
  printlist_Song(songlist);

  printf("\nprinting song list\n");
  songlist = insert_song_sorted(songlist, song5);
  printlist_Song(songlist);
  
  printf("\ntesting find_song...\n");
  printf("\ntesting find_first_song...\n");
  
  return 0;
}