// VAC: Vincent Jiang, Alice Liu, Cullen Ye

#ifndef SONGS_H
#define SONGS_H

struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct song_node *new_Song(char *name, char *artist);
void print_node(struct song_node *song);
void printlist_Song(struct song_node *song);
struct song_node *insert_front(struct song_node *front, struct song_node *newsong);
struct song_node *find_song(struct song_node* s, char* name, char* song);
struct song_node *find_first_artist(struct song_node *song, char *n);
struct song_node *insert_song_sorted(struct song_node *song, struct song_node* s2);
struct song_node *free_list(struct song_node *node);
struct song_node *remove_node(struct song_node *source, struct song_node *element);
int num_elements(struct song_node *list);
int random_int(int n);
struct song_node *random_element(struct song_node *list);

#endif
