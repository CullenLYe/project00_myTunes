// VAC: Vincent Jiang, Alice Liu, Cullen Ye

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"

// Create a new song.
struct song_node *new_Song(char *name, char *artist)
{
    struct song_node *ns = malloc(sizeof(struct song_node));
    strncpy(ns->name, name, sizeof(ns->name) - 1);
    strncpy(ns->artist, artist, sizeof(ns->artist) - 1);
    ns->next = NULL;
    return ns;
}

// print a song_node
void print_node(struct song_node *song)
{
    printf("%s: %s\n", song->artist, song->name);
}

// insert a new song to the front
struct song_node *insert_front(struct song_node *front, char *name, char *artist)
{
    struct song_node *newsong = new_Song(name, artist);
    newsong->next = front;
    return newsong;
}

// insert a pre-existing song in order
struct song_node *insert_song_sorted(struct song_node *song, char *name, char *artist)
{
    struct song_node *s2 = new_Song(name, artist);
    struct song_node *tracker = song;
  struct song_node *before = song;
  while (tracker) {
    
    if (strcmp(tracker->artist, s2->artist) == 0) {
      if (strcmp(tracker->name, s2->name) > 0) {
        s2->next = tracker;
        before->next = s2;
        break;
      } 
    }

    if (strcmp(tracker->artist, s2->artist) > 0) {
      // starting case
      if (before == tracker) {
        s2->next = tracker;
        return s2;
      }
      // intermediate
      else {
        before->next = s2;
        s2->next = tracker;
        break;
      } 
    } 
    // ending case
    else if (tracker->next == NULL) {
      tracker->next = s2;
      s2->next = NULL;
      break;
    }

    before = tracker;
    tracker = tracker->next;
  }
  return song;
}

// print the entire list
void printlist_Song(struct song_node *song)
{
    while (song)
    {
        printf("%s: %s | ", song->artist, song->name);
        song = song->next;
    }
}

// find and return a pointer to a node based on the artist and song name
struct song_node *find_song(struct song_node *song, char *n, char *s)
{
    while (song)
    {
        if (strcmp(song->artist, s) == 0 && strcmp(song->name, n) == 0)
            return song;
        song = song->next;
    }
    return NULL;
}

// find and return a pointer to the first song of an artist based on artist name
struct song_node *find_first_artist(struct song_node *song, char *n)
{
    while (song)
    {
        if (strcmp(song->artist, n) == 0)
            return song;
        song = song->next;
    }
    return NULL;
}

// returns number of elements in linked list
int num_elements(struct song_node *list)
{
    int i = 0;
    while (list)
    {
        i++;
        list = list->next;
    }
    return i;
}

// return a pointer to random element in the list
struct song_node *random_element(struct song_node *list)
{
    int i;
    int k = rand() % num_elements(list);
    for (i = 0; i < k; i++)
    {
        list = list->next;
    }
    return list;
}

// remove a single specified node from the list
struct song_node *remove_node(struct song_node *front, char *name, char *artist)
{
    struct song_node *element = new_Song(name, artist);
    struct song_node *first = front;
    struct song_node *before = front;
    if (strcmp(front->artist, element->artist) == strcmp(front->name, element->name))
    {
        free(front);
        return before->next;
    }

    while (front)
    {
        if (strcmp(front->artist, element->artist) == strcmp(front->name, element->name))
        {
            before->next = front->next;
            free(front);
            return first;
        }
        before = front;
        front = front->next;
    }
    return first;
}

// free a list
struct song_node *free_list(struct song_node *node)
{
    struct song_node *currentsong, *nextsong;
    currentsong = node;
    while (currentsong != NULL)
    {
        nextsong = currentsong->next;
        free(currentsong);
        currentsong = nextsong;
    }
    node = NULL;
    return node;
}
