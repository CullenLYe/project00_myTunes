#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songs.h"

// Create a new song.
struct song_node *new_Song(char *name, char *artist) {
  struct song_node *ns = malloc(sizeof(struct song_node));
  strncpy(ns->name, name, sizeof(ns->name)-1);
  strncpy(ns->artist, artist, sizeof(ns->artist)-1);
  ns->next = NULL;
  return ns;
}

// Prints a song's name and artist.
void print_Song(struct song_node *song) {
  printf("Song: %s\tArtist: %s\n", song->name, song->artist);
}

// Add a pre-existing song to the front of another song.
struct song_node *insert_front(struct song_node *front, struct song_node *newsong) {
  newsong->next = front;
  return newsong;
}
