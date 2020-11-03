#ifndef SONGS_H
#define SONGS_H

struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct song_node *new_Song(char *name, char *artist);
void print_Song(struct song_node *song);
struct song_node *insert_front(struct song_node *front, struct song_node *newsong);

#endif
