#include "account.h"
#include "feed.h"
#include "u_int.h"

void menuTable(void);
void line(void);
void row(char* text1, char* text2);

int main(){
    int endTwitter = 0;
    printf("\nWelcome to...\nTwitter in C!\n");
    makeAccounts();
    menuTable();
    // while (endTwitter = 0){
    //     printf("\nWould you like to: \n\n");
    //     menu_table();
    // }
    return 0;
}

void menuTable(void){
    char menuOptions[6][16] = {{"View News Feed\0"}, {"Follow a user\0"}, {"Unfollow a user\0"}, {"Delete Account\0"}, {"End Turn\0"}, {"End Twitter\0"}};
    char menuNums[6][3] = {{"1.\0"}, {"2.\0"}, {"3.\0"}, {"4.\0"}, {"5.\0"}, {"6.\0"}};
    line();
    row("No.", "Menu");
    for (int i=0; i<5;i++){
        line();
        int k=1;
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