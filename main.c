#include "u_int.h"

// Prototypes
void menuTable(void);
void nameHead(char username[], int nameHead);

int main(){
    int endTwitter = 0, menChoice;
    accountNode *startPtr = NULL;
    accountNode *curAcPtr = NULL;
    tweetNode *startTwtPtr = NULL;
    
    divLine(96);
    printf("||%30s<<< Welcome to Twitter for C >>>%30s||\n", "","");
    divLine(96);
    printf("||%40sMake Accounts%39s||\n", "","");
    divLine(96);
    /*
    Calling the function `makeAccounts` and passing the address of the pointer `startPtr` to it.
    */
    makeAccounts(&startPtr);
    curAcPtr = startPtr;
    nameHead(curAcPtr->username, 46);
    while (endTwitter == 0){
        printf("\nWould you like to: \n");
        /* 
        Printing a table with the menu options.
        */
        menuTable();
        fflush(stdin);
        /* 
        A while loop that checks if the input is an integer from 1-8. If it is, it will run the code in the
        if statement. If it isn't, it will print an error message and ask for the input again. 
        */
        while (scanf("%i", &menChoice)==0 || menChoice<1 || menChoice>8){
            printf("Input must be an integer from 1-8\nPlease try again\n\nEnter: ");
            fflush(stdin);
        }
        if (menChoice==1){
            getNewsFeed(startTwtPtr, curAcPtr);
            pressCont();
        }else if(menChoice==2){
            postTweet(&startTwtPtr, curAcPtr);
        }else if(menChoice==3){
            viewProfile(curAcPtr, startTwtPtr);
        }else if (menChoice==4){
            follow(startPtr, curAcPtr);  
            pressCont();            
        }else if (menChoice==5){
            unfollow(startPtr, curAcPtr);
            pressCont();
        }else if (menChoice==6){
            char tempU[15];
            strcpy(tempU, curAcPtr->username);
            deleteAccount(&startPtr, &curAcPtr, &startTwtPtr);
            printf("\nGoodbye %s,\nYou have deleted your account\nWe are sorry to see you leave us :(\n", tempU);
            if (curAcPtr != NULL){
                nameHead(curAcPtr->username, 46);
            }else{
                endTwitter = 1;
            }
        }else if (menChoice==7){
            printf("\nGoodbye %s,\nWe hope to see you again soon :)\n", curAcPtr->username);
            curAcPtr = curAcPtr->nextPtr;
            if (curAcPtr != NULL){
                nameHead(curAcPtr->username, 46);
            }else{
                endTwitter = 1;
            }
        }else{
            endTwitter = 1;
        }
    }
    printf("\n");
    divLine(44);
    printf("||%9sTerminating program...%9s||\n", "", "");
    printf("||%2sThanks for trying out TWITTER FOR C%3s||\n", "", "");
    divLine(44);
    printf("<<< Press any key to exit >>> ");
    fflush(stdin);
    getchar();
    return 0;
}


void menuTable(void){
    /*
    It prints a table with the menu options.
    */
    char menuOptions[8][16] = {{"View News Feed\0"}, {"Make A Tweet\0"}, {"View Profile\0"}, {"Follow a user\0"}, {"Unfollow a user\0"}, {"Delete Account\0"}, {"End Turn\0"}, {"End Twitter\0"}};
    char menuNums[8][3] = {{"1.\0"}, {"2.\0"}, {"3.\0"}, {"4.\0"}, {"5.\0"}, {"6.\0"}, {"7.\0"}, {"8.\0"}};
    divLine(28);
    row("No.", "Menu");
    for (int i=0; i<8;i++){
        divLine(28);
        row(menuNums[i], menuOptions[i]);
    }
    divLine(28);
    printf("\nEnter: ");
}

void nameHead(char username[], int startSpace){
    /*
    It prints a line of dashes, then a line with the username in the middle, then another line of
    dashes.
    */
    int len=strlen(username);
    divLine(96);
    printf("||");
    for (int i=0;i<startSpace-(len/2);i++){
        printf(" ");
    }
    printf("%s", username);
    for (int i=0;i<startSpace-len+(len/2);i++){
        printf(" ");
    }
    printf("||\n");
    divLine(96);
}