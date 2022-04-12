#include "account.h"
#include "feed.h"
#include "u_int.h"

<<<<<<< Updated upstream
int main(){
    
=======
void menuTable(void);
void line(void);
void row(char* text1, char* text2);

int main(){
    int endTwitter = 0;
    printf("\nWelcome to...\nTwitter in C!\n");
    // makeAccounts();
    menuTable();
    // while (endTwitter = 0){
    //     printf("\nWould you like to: \n\n");
    //     menu_table();
    // }
>>>>>>> Stashed changes
    return 0;
}

void menuTable(void){
    char menuOptions[6][15] = {{"View News Feed"}, {"Follow a user"}, {"Unfollow a user"}, {"Delete Account"}, {"End Turn"}, {"End Twitter"}}, menuNums[6][2] = {{"1."}, {"2."}, {"3."}, {"4."}, {"5."}, {"6."}};
    line();
    row("No.", "Menu");
    for (int i=0; i<2;i++){
        line();
        row(menuNums[i], menuOptions[i]);
    }
    line();
}

void line(void){
    for (int i=0;i<28;i++){
        printf("=");
    }
    printf("\n");
}

void row(char* text1, char* text2){
    printf("||%4s ||%16s ||\n", text1, text2);
}