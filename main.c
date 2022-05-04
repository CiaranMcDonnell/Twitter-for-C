#include "feed.h"
#include "u_int.h"
#include "account.h"

void menuTable(void);
void nameHead(char username[]);

int main(){
    int endTwitter = 0, menChoice;
    accountNode *startPtr = NULL;
    accountNode *curAcPtr = NULL;
    printf("\nWelcome to...\nTwitter for C!\n");
    makeAccounts(&startPtr);
    curAcPtr = startPtr;
    // printAccounts(curAcPtr);
    nameHead(curAcPtr->username);
    while (endTwitter == 0){
        printf("\nWould you like to: \n");
        menuTable();
        fflush(stdin);
        while (scanf("%i", &menChoice)==0){
            printf("Input must be an integer from 1-6\nPlease try again\n\nEnter: ");
            fflush(stdin);
        }
        if (menChoice==1){
            printf("News feed");
        }else if (menChoice==2){
            follow(startPtr, curAcPtr);
        }else if (menChoice==3){
            unfollow(startPtr, curAcPtr);
        }else if (menChoice==4){
            printf("Delete Account");
        }else if (menChoice==5){
            printf("\nGoodbye %s,\nWe hope to see you again soon :)\n", curAcPtr->username);
            curAcPtr = curAcPtr->nextPtr;
            if (curAcPtr != NULL){
                nameHead(curAcPtr->username);
            }else{
                endTwitter = 1;
            }
        }else{
            endTwitter = 1;
        }
    }
    printf("\nThanks for trying out\nTWITTER FOR C\n\n");
    return 0;
}

void menuTable(void){
    char menuOptions[6][16] = {{"View News Feed\0"}, {"Follow a user\0"}, {"Unfollow a user\0"}, {"Delete Account\0"}, {"End Turn\0"}, {"End Twitter\0"}};
    char menuNums[6][3] = {{"1.\0"}, {"2.\0"}, {"3.\0"}, {"4.\0"}, {"5.\0"}, {"6.\0"}};
    line();
    row("No.", "Menu");
    for (int i=0; i<6;i++){
        line();
        row(menuNums[i], menuOptions[i]);
    }
    line();
    printf("\nEnter: ");
}


void nameHead(char username[]){
    int len=strlen(username);
    divLine(70);
    printf("||");
    for (int i=0;i<33-(len/2);i++){
        printf(" ");
    }
    printf("%s", username);
    for (int i=0;i<33-len+(len/2);i++){
        printf(" ");
    }
    printf("||\n");
    divLine(70);
}