#include <stdlib.h>
#include <stdio.h.>
#include "songs.h"
#include "symbols.h"

int main() {

  printf("Creating song1...\n");
  struct song_node *song1 = new_Song("name1", "artist1");
  print_Song(song1);

  printf("\nCreating song2...\n");
  struct song_node *song2 = new_Song("name2", "artist2");
  print_Song(song2);

  printf("\nInserting song2 in front of song1, so the linked list is song2->song1\n");
  insert_front(song1, song2);
  printf("song2:\n");
  print_Song(song2);
  printf("song2->next:\n");
  print_Song(song2->next);

  return 0;

}
