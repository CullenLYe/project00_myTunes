// VAC: Vincent Jiang, Alice Liu, Cullen Ye

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

// print the entire list
void printlist_Song(struct song_node *song) {
  while (song) {
    printf("Song: %s\tArtist: %s\n", song->name, song->artist);
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
    if (strcmp(song->artist, n) && strcmp(song->name, s))
      return song;
    else song = song->next;
  }
}

// find and return a pointer to the first song of an artist based on artist name 
struct song_node *find_first_artist(struct song_node *song, char *n) {
  while (song) {
    if (strcmp(song->artist, n)) 
      return song;
    song = song->next;
  }
}

// insert nodes in order
struct song_node *insert_song_sorted(struct song_node *song, struct song_node *s2) {
  struct song_node *tracker = song;
  struct song_node *before = song;
  while (tracker) {
    /**
    if (strcmp(song->artist, s2->artist)) {
      // case 1 for insertion
      if (strcmp(song->name, s2->name) < 0 && strcmp(song->next->name, s2->name) > 0 && strcmp(song->next->artist, s2->artist)) {
        s2->next = song->next;
        song->next = s2;
      }
      // case 2 for insertion
      else if (strcmp(song->name, s2->name) < 0 && !strcmp(song->next->artist, s2->artist)) {
        s2->next = song->next;
        song->next = s2;
      } 
      else {
        before->next = s2;
        s2->next = song;
      }
    }
**/
// else
    if (strcmp(tracker->artist, s2->artist) > 0) {
      // beginning case
      if (before == tracker) {
        s2->next = tracker;
        return s2;
      }
      else {
        before->next = s2;
        s2->next = tracker;
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