// VAC: Vincent Jiang, Alice Liu, Cullen Ye

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "songs.h"
#include "symbols.h"

int main() {
  srand(time(NULL));
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
  struct song_node *song7 = new_Song("Viva La Vida", "Coldplay");


  printf("\nprinting song list\n");
  struct song_node *songlist = insert_song_sorted(song2, song3);
  printlist_Song(songlist);

  printf("\nprinting song list\n");
  songlist = insert_song_sorted(songlist, song4);
  printlist_Song(songlist);

  printf("\nprinting song list\n");
  songlist = insert_song_sorted(songlist, song5);
  printlist_Song(songlist);
  
  printf("\nprinting song list\n");
  songlist = insert_song_sorted(songlist, song6);
  printlist_Song(songlist);

  printf("\nprinting song list\n");
  songlist = insert_song_sorted(songlist, song7);
  printlist_Song(songlist);

  printf("\ntesting find_song...\n");
  printf("finding Artist: Coldplay\t Song: Yellow\n");
  printf("printing list...\n");
  struct song_node *find = find_song(songlist, song6->artist, song6->name);
  printlist_Song(find);


  printf("\ntesting find_first_song...\n");
  printf("finding Artist: Coldplay\n");
  printf("printing list...\n");
  find = find_first_artist(songlist, song6->artist);
  printlist_Song(find);


  printf("\ntesting random_element...\n");
  int i;
  struct song_node *s;
  for (i = 0; i < 4; i++) {
    s = random_element(songlist); 
    print_node(s);
  }


  printf("\ntesting remove_node...\n");
  printf("removing ");
  print_node(song3);
  songlist = remove_node(songlist, song3);
  printf("printing songlist after removal...\n");
  printlist_Song(songlist);

  printf("\nremoving ");
  print_node(song4);
  songlist = remove_node(songlist, song4);
  printf("printing songlist after removal...\n");
  printlist_Song(songlist);

  printf("\nremoving ");
  print_node(song5);
  songlist = remove_node(songlist, song5);
  printf("printing songlist after removal...\n");
  printlist_Song(songlist);


  printf("\nFreeing Song List...\n");
  free_list(songlist);
  printf("\nFinished Freeing...\n");
  
  printf("\n-----\nTESTING SYMBOLS.C / SYMBOLS.H:\n------\n\n");
  printf("testing print_Symbols\n");

  struct song_node *s1 = new_Song("Centuries", "Fall Out Boy");
  struct song_node *s2 = new_Song("Immortals", "Fall Out Boy");
  struct song_node *s3 = new_Song("Chlorine", "Twenty One Pilots");
  struct song_node *s4 = new_Song("Yellow", "Coldplay");
  struct song_node *s5 = new_Song("Lemon", "Kenshi Yonezu");
  struct song_node *s6 = new_Song("Perfect", "Ed Sheeran");
  struct song_node *s7 = new_Song("Counting Stars", "One Republic");
  struct song_node *s8 = new_Song("Patience", "Hollow Coves");
  struct song_node *s9 = new_Song("Fireflies", "Owl City");


  struct Symbols *library1 = new_Symbols();
  library1 = addSong(library1, s1);
  library1 = addSong(library1, s2);
  library1 = addSong(library1, s3);
  library1 = addSong(library1, s4);
  library1 = addSong(library1, s5);
  library1 = addSong(library1, s6);
  library1 = addSong(library1, s7);
  library1 = addSong(library1, s8);
  library1 = addSong(library1, s9);

  // testing print_Symbols
  print_Symbols(library1);

  printf("\n");

  // testing remove_song
  printf("removing Artist: Twenty One Pilots   Song: Chlorine\n");
  library1 = remove_song(library1, s3);
  
  printf("testing after removal: \n\n");
  print_Symbols(library1);

  printf("\n");

  printf("testing print_Artist_Symbols \n");
  print_Artist_Symbols(library1, s2->artist);

  printf("testing clear_lib \n\n");
  printf("library before clear_lib: \n");
  print_Symbols(library1);

  clear_lib(library1);

  printf("library after clear_lib: \n");
  print_Symbols(library1);

  printf("\n");

  printf("Adding songs to empty library \n");
  struct Symbols *library2 = new_Symbols();
  struct song_node *s11 = new_Song("Chlorine", "Twenty One Pilots");
  struct song_node *s12 = new_Song("The Scientist", "Coldplay");
  struct song_node *s13 = new_Song("Lemon", "Kenshi Yonezu");
  struct song_node *s14 = new_Song("Perfect", "Ed Sheeran");
  struct song_node *s15 = new_Song("Apologize", "One Republic");
  struct song_node *s16 = new_Song("Counting Stars", "One Republic");
  struct song_node *s17 = new_Song("Love Runs Out", "One Republic");
  struct song_node *s18 = new_Song("Stop And Stare", "One Republic");
  library2 = addSong(library2, s11);
  library2 = addSong(library2, s12);
  library2 = addSong(library2, s13);
  library2 = addSong(library2, s14);
  library2 = addSong(library2, s15);
  library2 = addSong(library2, s16);
  library2 = addSong(library2, s17);
  library2 = addSong(library2, s18);

  printf("\n");

  printf("testing print_Letter_Symbols \n");
  print_Letter_Symbols(library2, 'O');
  
  printf("\n");

  printf("testing shuffle\n");
  shuffle(library1);

  return 0;
}
