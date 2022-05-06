#include "feed.h"
#include "u_int.h"

void menuTable(void);
void nameHead(char username[], int nameHead);

int main(){
    int endTwitter = 0, menChoice;
    accountNode *startPtr = NULL;
    accountNode *curAcPtr = NULL;
    printf("\nWelcome to...\nTwitter for C!\n");
    makeAccounts(&startPtr);
    curAcPtr = startPtr;
    // printAccounts(curAcPtr);
    nameHead(curAcPtr->username, 33);
    while (endTwitter == 0){
        printf("\nWould you like to: \n");
        menuTable();
        fflush(stdin);
        while (scanf("%i", &menChoice)==0 || menChoice<1 || menChoice>7){
            printf("Input must be an integer from 1-7\nPlease try again\n\nEnter: ");
            fflush(stdin);
        }
        if (menChoice==1){
            printf("News feed");
            pressCont();
        }else if (menChoice==2){
            viewProfile(curAcPtr);
            pressCont();
        }else if (menChoice==3){
            follow(startPtr, curAcPtr);
            pressCont();
        }else if (menChoice==4){
            unfollow(startPtr, curAcPtr);
            pressCont();
        }else if (menChoice==5){
            printf("Delete Account");
        }else if (menChoice==6){
            printf("\nGoodbye %s,\nWe hope to see you again soon :)\n", curAcPtr->username);
            curAcPtr = curAcPtr->nextPtr;
            if (curAcPtr != NULL){
                nameHead(curAcPtr->username, 33);
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
    char menuOptions[7][16] = {{"View News Feed\0"}, {"View Profile\0"}, {"Follow a user\0"}, {"Unfollow a user\0"}, {"Delete Account\0"}, {"End Turn\0"}, {"End Twitter\0"}};
    char menuNums[7][3] = {{"1.\0"}, {"2.\0"}, {"3.\0"}, {"4.\0"}, {"5.\0"}, {"6.\0"}, {"7.\0"}};
    divLine(28);
    row("No.", "Menu");
    for (int i=0; i<7;i++){
        divLine(28);
        row(menuNums[i], menuOptions[i]);
    }
    divLine(28);
    printf("\nEnter: ");
}


void nameHead(char username[], int startSpace){
    int len=strlen(username);
    divLine(70);
    printf("||");
    for (int i=0;i<startSpace-(len/2);i++){
        printf(" ");
    }
    printf("%s", username);
    for (int i=0;i<startSpace-len+(len/2);i++){
        printf(" ");
    }
    printf("||\n");
    divLine(70);
}