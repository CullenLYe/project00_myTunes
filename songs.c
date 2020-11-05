// VAC: Vincent Jiang, Alice Liu, Cullen Ye

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"

// Create a new song.
struct song_node *new_Song(char *name, char *artist) {
  struct song_node *ns = malloc(sizeof(struct song_node));
  strncpy(ns->name, name, sizeof(ns->name)-1);
  strncpy(ns->artist, artist, sizeof(ns->artist)-1);
  ns->next = NULL;
  return ns;
}

// print a song_node 
void print_node(struct song_node *song) {
  printf("Artist: %s\tSong: %s\n", song->artist, song->name);
}

// print the entire list
void printlist_Song(struct song_node *song) {
  while (song) {
    printf("Artist: %s\tSong: %s\n", song->artist, song->name);
    song = song->next;
  }
}

// Add a pre-existing song to the front of another song.
struct song_node *insert_front(struct song_node *front, struct song_node *newsong) {
  newsong->next = front;
  return newsong;
}

// find and return a pointer to a node based on the artist and song name
struct song_node *find_song(struct song_node *song, char *n, char *s) {
  while (song) {
    if (strcmp(song->artist, n) == 0 && strcmp(song->name, s) == 0)
      return song;
    song = song->next;
  }
}

// find and return a pointer to the first song of an artist based on artist name 
struct song_node *find_first_artist(struct song_node *song, char *n) {
  while (song) {
    if (strcmp(song->artist, n) == 0) 
      return song;
    song = song->next;
  }
}

// insert nodes in order
struct song_node *insert_song_sorted(struct song_node *song, struct song_node *s2) {
  struct song_node *tracker = song;
  struct song_node *before = song;
  while (tracker) {
    
    if (strcmp(tracker->artist, s2->artist) == 0) {

      // case 1
      if (strcmp(tracker->name, s2->name) > 0) {
        s2->next = tracker;
        before->next = s2;
        break;
      } 
      // case 2
      if (strcmp(tracker->next->artist, s2->artist) && strcmp(tracker->artist, s2->artist) < 0) {
        s2->next = tracker->next;
        tracker->next = s2;
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

// free a list
struct song_node *free_list(struct song_node *node) {
  struct song_node *currentsong, *nextsong;
  currentsong = node;
  while (currentsong!=NULL) {
    nextsong = currentsong->next;
    free(currentsong);
    currentsong = nextsong;
  }
  node = NULL;
  return node;
}

// returns number of elements in linked list
int num_elements(struct song_node *list) {
  int i = 0;
  while (list) {
    i++;
    list = list->next;
  }
  return i;
}

// return a pointer to random element in the list
struct song_node *random_element(struct song_node *list) {
  int i;
  int k = rand() % num_elements(list);
  for (i = 0; i < k; i++) {
    list = list->next;
  }
  return list;
}

// remove a single specified node from the list
struct song_node *remove_node(struct song_node *front, struct song_node *element) {
  struct song_node *first = front;
  struct song_node *before = front;
  if (strcmp(front->artist, element->artist) == strcmp(front->name, element->name)) {
    free(front);
    return front->next;
  }

  while (front) {
    if (strcmp(front->artist, element->artist) == strcmp(front->name, element->name)) {
      before->next = front->next;
      free(front);
      return first;
    }
    before = front;
    front = front->next;
  }
  return first; 
}

