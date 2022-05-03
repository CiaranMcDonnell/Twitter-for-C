#include "account.h"
#include "feed.h"
#include "u_int.h"

void menuTable(void);
void line(void);
void row(char* text1, char* text2);

int main(){
    int endTwitter = 0, menChoice;
    accountNode *startPtr = NULL;
    printf("\nWelcome to...\nTwitter for C!\n");
    makeAccounts(&startPtr);
    accountNode *curAcPtr = startPtr;
    // printAccounts(curAcPtr);
    while (endTwitter = 0 && curAcPtr != NULL){
        printf("\nWould you like to: \n\n");
        menuTable();
        while (scanf("%i", &menChoice)==0){
            printf("Input must be an integer from 1-6\nPlease try again\n\nEnter: ");
        }
        if (menChoice==1){
            printf("News feed");
        }else if (menChoice==2){
            printf("News feed");
        }else if (menChoice==3){
            printf("News feed");
        }else if (menChoice==4){
            printf("News feed");
        }else if (menChoice==5){
            printf("News feed");
        }else{
            endTwitter = 1;
            printf("\nThanks for trying out\nTWITTER FOR C\n\nWe hope to see you again soon :)");
        }
    }
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
    printf("\nEnter: ");
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