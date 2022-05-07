#include "feed.h"

int postTweet(tweetsNodePtr *startPtr, accountNodePtr curAcPtr){
    /*
    A function that allows the user to post a tweet. It takes in the pointer to the start of the linked
    list of tweets and the pointer to the current account. It then asks the user to enter a tweet and
    stores it in a temporary variable. It then creates a new node and stores the tweet in the new node.
    It then checks if the linked list is empty or not, it assigns the id of the new node to be
    the id of the last node plus one. It then assigns the next pointer of the new node to the start of
    the linked list. It then assigns the start of the linked list to the new node. It then asks the user
    if they want to post another tweet. If they do, it repeats the process. If they don't, it exits the
    function. 
    */
    tweetsNodePtr tweetPtr;
    tweetsNodePtr newPtr;
    char attempt[281], cont='y';
    int len, dq =1;

    while (cont == 'y' || cont == 'Y'){
        printf("\nWhat do you want to Tweet?\nEnter: ");
        fflush(stdin);
        while(scanf("%[^\n]", &attempt)==0 || strlen(attempt)>280){
            printf("You can only tweet 280 Characters.\nPlease try again.\n\nWhat do you want to Tweet?\nEnter: ");
            fflush(stdin);
        }
        tweetPtr = *startPtr;
        newPtr = (tweetNode *)malloc(sizeof(tweetNode));
        if (newPtr != NULL){
            strcpy(newPtr->tweet, attempt);
            strcpy(newPtr->username, curAcPtr->username);
            if (tweetPtr != NULL){
                newPtr->id=(tweetPtr->id)+1;
                newPtr->nextPtr= tweetPtr;
            }else{
                newPtr->id=1;
                newPtr->nextPtr= NULL;
            }
            *startPtr = newPtr;
        }else{
            printf("No memory available.\n");
        }
        printf("\nTweet Posted!");
        printf("\nWould you like to make another tweet? y/n: ");
        fflush(stdin);
        scanf("%c", &cont);
        while (cont != 'n' && cont != 'N' && cont != 'y' && cont != 'Y'){
            printf("Invalid input\nPlease try again\n\nWould you like to make another account? y/n: ");
            fflush(stdin);
            scanf("%c", &cont);
        }
    }
}

int getNewsFeed(tweetsNodePtr startPtr, accountNodePtr curAcPtr){
    /*
    It gets the most recent ten tweets of the users that the current user is following
    */
    followNodePtr followingPtr;
    int match, num=0;
    while(startPtr != NULL&&num!=10){
        followingPtr=curAcPtr->followingPtr;
        match=0;
        while(followingPtr!=NULL&&match==0){
            if(!strcmp(startPtr->username, followingPtr->username)){
                match=1;
                num++;
                printNewsFeed(num, startPtr);
            }
            followingPtr=followingPtr->nextPtr;
        }
        startPtr=startPtr->nextPtr;
    }
    if(num==0){
        printf("\nOhh no. The news feed is empty\nTry following some users\nIf that doesn't work then call yourself Adam cause you're the first man here\n\n");
    }else{
        divLine(62);
        printf("\n");
    }
}

void printNewsFeed(int y, tweetsNodePtr startPtr){
    /*
    It pairs with the getNewsFeed function to print out the selected tweet with user, id and tweet data. 
    */
    int len=strlen(startPtr->tweet), i, x, num;
    num=len/56;
    divLine(62);
    printf("|| No: %2d || ID: %10d || User: %22s ||\n", y, startPtr->id, startPtr->username);
    divLine(62);
    printf("|| Tweet:%50s ||\n","");
    for(i=0;i<num;i++){
        printf("|| ");
        for(x=0;x<56;x++){
            printf("%c", startPtr->tweet[(i*56)+x]);
        }
        printf(" ||\n");
    }
    i=num;
    num=len%56;
    if (num>0){
        printf("|| ");
        for(x=0;x<num;x++){
            printf("%c", startPtr->tweet[(i*56)+x]);
        }
        for(x=0;x<(56-num);x++){
            printf(" ");
        }
        printf(" ||\n");
    }
}

void divLine(int len){
    /*
    It prints a line of equal signs
    */
    for (int i=0;i<len;i++){
        printf("=");
    }
    printf("\n");
}