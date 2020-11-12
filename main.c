// VAC: Vincent Jiang, Alice Liu, Cullen Ye

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "songs.h"
#include "symbols.h"

int main()
{
    srand(time(NULL));
    printf("LINKED LIST TESTS\n");
    printf("====================================\n");
    printf("\nCreating song with song_node:\n");
    struct song_node *song_list = new_Song("passion pit", "constant conversations");
    print_node(song_list);
    printf("====================================\n");

    printf("\nTesting insert_front:\n");
    song_list = insert_front(song_list, "the scientist", "coldplay");
    printlist_Song(song_list);
    printf("\n====================================\n");

    printf("\nTesting insert_song_sorted:\n");
    song_list = insert_song_sorted(song_list, "yellow", "coldplay");
    song_list = insert_song_sorted(song_list, "centuries", "fall out boy");
    song_list = insert_song_sorted(song_list, "fireflies", "owl city");
    song_list = insert_song_sorted(song_list, "lemon", "kenshi yonezu");
    song_list = insert_song_sorted(song_list, "patience", "hollow coves");
    song_list = insert_song_sorted(song_list, "a-punk", "vampire weekend");
    song_list = insert_song_sorted(song_list, "lisztomania", "phoenix");
    printlist_Song(song_list);
    printf("\n====================================\n");

    printf("\nTesting find_song:\n");
    printf("looking for [fireflies : owl city]\n");
    printlist_Song(find_song(song_list, "fireflies", "owl city"));
    printf("\n\nlooking for [sleepyhead: passion pit]\n");
    printlist_Song(find_song(song_list, "sleepyhead", "passion pit"));
    printf("\n====================================\n");

    printf("\nTesting find_first_artist:\n");
    printf("looking for [coldplay]\n");
    printlist_Song(find_first_artist(song_list, "coldplay"));
    printf("\n====================================\n");

    printf("\nTesting random_element:\n");
    print_node(random_element(song_list));
    print_node(random_element(song_list));
    print_node(random_element(song_list));
    printf("====================================\n");

    printf("\nTesting remove_node:\n");
    printf("removing [centuries: fall out boy]\n");
    remove_node(song_list, "centuries", "fall out boy");
    printlist_Song(song_list);
    printf("\n====================================\n");

    printf("\nTesting free_list:\n");
    printf("before freeing\n");
    printlist_Song(song_list);
    printf("\n");
    song_list = free_list(song_list);
    printf("after freeing\n");
    printlist_Song(song_list);
    printf("\n====================================\n");

    printf("\nMUSIC LIBRARY TESTS\n");
    printf("====================================\n");

    printf("\nCreating new playlist with new_Symbols:\n");
    struct Symbols *playlist = new_Symbols();
    printf("====================================\n");

    printf("\nTesting addSong:\n");
    playlist = addSong(playlist, new_Song("Centuries", "Fall Out Boy"));
    playlist = addSong(playlist, new_Song("Immortals", "Fall Out Boy"));
    playlist = addSong(playlist, new_Song("Chlorine", "Twenty One Pilots"));
    playlist = addSong(playlist, new_Song("The Scientist", "Coldplay"));
    playlist = addSong(playlist, new_Song("Yellow", "Coldplay"));
    playlist = addSong(playlist, new_Song("Lemon", "Kenshi Yonezu"));
    playlist = addSong(playlist, new_Song("Perfect", "Ed Sheeran"));
    playlist = addSong(playlist, new_Song("Counting Stars", "One Republic"));
    playlist = addSong(playlist, new_Song("Patience", "Hollow Coves"));
    playlist = addSong(playlist, new_Song("Fireflies", "Owl City"));
    playlist = addSong(playlist, new_Song("Constant Conversations", "Passion pit"));
    playlist = addSong(playlist, new_Song("A-punk", "Vampire Weekend"));
    playlist = addSong(playlist, new_Song("Lisztomania", "The Phoenix"));
    playlist = addSong(playlist, new_Song("Something Good Can Work", "Two Door Cinema Club"));
    print_Symbols(playlist);
    printf("====================================\n");

    printf("\nTesting search:\n");
    printf("looking for [A-punk, Vampire Weekend]\n");
    printlist_Song(search(playlist, "A-punk", "Vampire Weekend"));
    printf("\n");
    printf("looking for [New Light, John Mayer]\n");
    printlist_Song(search(playlist, "New Light", "John Mayer"));
    printf("\n====================================\n");

    printf("\nTesting search_artist:\n");
    printf("looking for [Hollow Coves]\n");
    printlist_Song(search_artist(playlist, "Hollow Coves"));
    printf("\n");
    printf("looking for [Hannah Montana]\n");
    printlist_Song(search_artist(playlist, "Hannah Montana"));
    printf("\n====================================\n");

    printf("\nTesting print_Letter_Symbols:\n");
    print_Letter_Symbols(playlist, 'T');
    print_Letter_Symbols(playlist, 'K');
    printf("====================================\n");

    printf("\nTesting print_Artist_Symbols:\n");
    print_Artist_Symbols(playlist, "Fall Out Boy");
    print_Artist_Symbols(playlist, "Two Door Cinema Club");
    printf("====================================\n");

    printf("\nTesting remove song:\n");
    printf("removing [A-punk, Vampire Weekend]\n");
    playlist = remove_song(playlist, "A-punk", "Vampire Weekend");
    print_Symbols(playlist);
    printf("\n====================================\n");

    printf("\nTesting clear_library:\n");
    printf("before clearing:\n");
    print_Symbols(playlist);
    clear_lib(playlist);
    printf("\nafter clearing:\n");
    print_Symbols(playlist);    
    printf("====================================\n");

    playlist = addSong(playlist, new_Song("Centuries", "Fall Out Boy"));
    playlist = addSong(playlist, new_Song("Immortals", "Fall Out Boy"));
    playlist = addSong(playlist, new_Song("Chlorine", "Twenty One Pilots"));
    playlist = addSong(playlist, new_Song("The Scientist", "Coldplay"));
    playlist = addSong(playlist, new_Song("Yellow", "Coldplay"));
    playlist = addSong(playlist, new_Song("Lemon", "Kenshi Yonezu"));
    playlist = addSong(playlist, new_Song("Perfect", "Ed Sheeran"));
    playlist = addSong(playlist, new_Song("Counting Stars", "One Republic"));
    playlist = addSong(playlist, new_Song("Patience", "Hollow Coves"));
    playlist = addSong(playlist, new_Song("Fireflies", "Owl City"));
    playlist = addSong(playlist, new_Song("Constant Conversations", "Passion pit"));
    playlist = addSong(playlist, new_Song("A-punk", "Vampire Weekend"));
    playlist = addSong(playlist, new_Song("Lisztomania", "The Phoenix"));
    playlist = addSong(playlist, new_Song("Something Good Can Work", "Two Door Cinema Club"));

    printf("\nTesting shuffle\n");
    shuffle(playlist);
    printf("====================================\n");
}
