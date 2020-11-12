// VAC: Vincent Jiang, Alice Liu, Cullen Ye

#ifndef SONGS_H
#define SONGS_H

struct song_node
{
    char name[256];
    char artist[256];
    struct song_node *next;
};

void print_node(struct song_node *song);
int num_elements(struct song_node *list);

struct song_node *new_Song(char *name, char *artist);
struct song_node *insert_front(struct song_node *front, char *name, char *artist);
struct song_node *insert_song_sorted(struct song_node *song, char *name, char *artist);
void printlist_Song(struct song_node *song);
struct song_node *find_song(struct song_node *s, char *name, char *song);
struct song_node *find_first_artist(struct song_node *song, char *n);
struct song_node *random_element(struct song_node *list);
struct song_node *remove_node(struct song_node *source, char *name, char *artist);
struct song_node *free_list(struct song_node *node);

#endif
