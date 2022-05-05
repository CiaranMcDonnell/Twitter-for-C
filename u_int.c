#include "u_int.h"

void follow(accountNodePtr startPtr, accountNodePtr curAcPtr){
    int totAcs, choiceAc;
    accountNodePtr acLoopPtr = startPtr;
    totAcs = followTable(acLoopPtr, curAcPtr);
    if (totAcs>0){
        printf("\nEnter: ");
        while (scanf("%i", &choiceAc)==0 || choiceAc<1 || choiceAc>totAcs){
            printf("Input must be an integer within the range of the table\nPlease try again\n\nEnter: ");
        }
        totAcs=0;
        while (totAcs<choiceAc){
            if (strcmp(acLoopPtr->username, curAcPtr->username)){
                totAcs--;
            }else{
                followNodePtr followingPtr = curAcPtr->followingPtr;
                while (followingPtr!=NULL){
                    if (strcmp(followingPtr->username, curAcPtr->username)){
                        totAcs--;
                        followingPtr=NULL;
                    }else{
                        followingPtr=followingPtr->nextPtr;
                    }
                }
            }
            acLoopPtr = acLoopPtr->nextPtr;
            totAcs++;
        }
        followNodePtr newFollowingPtr;
        followNodePtr tempPtr;
        followNodePtr newFollowersPtr;
        newFollowingPtr = (followNode*)malloc(sizeof(followNode));
        newFollowersPtr = (followNode*)malloc(sizeof(followNode));
        tempPtr = curAcPtr->followingPtr; 
        strcpy(newFollowingPtr->username, acLoopPtr->username);
        newFollowingPtr->nextPtr = tempPtr; 
        curAcPtr->followingPtr = newFollowingPtr;
        tempPtr = acLoopPtr->followersPtr; 
        strcpy(newFollowersPtr->username, curAcPtr->username);
        newFollowersPtr->nextPtr = tempPtr; 
        acLoopPtr->followersPtr = newFollowersPtr;
        printf("\nYou are now following %s!\n", acLoopPtr->username);
    }else{
        printf("\nUnfortunately you're a popular guy.\nIt seems you already follow all other accounts.\nAs the great DJ Khaled once said: \"Suffering from success\"\n\n");
    }
}

void unfollow(accountNodePtr startPtr, accountNodePtr curAcPtr){
    // int totAcs, choiceAc;
    // accountNodePtr acLoopPtr = startPtr;
    // totAcs = followingTable(acLoopPtr, curAcPtr);
    // if(totAcs>0){
    //     printf("\nEnter:");
    //     while(scanf("%i", &choiceAc)==0 || choiceAc<1 || choiceAc>totAcs){
    //         printf("Input must be an integer within the range of the table\nPlease try again\n\nEnter: ");
    //     }
    //     totAcs=0;
    //     while(totAcs<choiceAc){
    //         if(strcmp(acLoopPtr->username, curAcPtr->username)){
    //             totAcs--;
    //         }
    //     }
    // }
}

int didYouMean(){

}

void viewProfile(accountNodePtr curAcPtr){
    int followers = 0, following = 0, tweets=913;
    followNodePtr followersPtr = curAcPtr->followersPtr;
    followNodePtr followingPtr = curAcPtr->followingPtr;
    //here 
    while(followersPtr!=NULL){
        followers++;
        followersPtr = followersPtr->nextPtr;
    }
    while(followingPtr!=NULL){
        following++;
        followingPtr = followingPtr->nextPtr;
    }
/*  while(tweetPtr !=NULL){
        tweets++;
    }*/
    divLine(62);
    printf("||%35s%23s||\n", "USER PROFILE", "");
    divLine(62);
    printf("||..............................||%26s||\n", "");
    printf("||............#######...........|| Username:%15s ||\n", curAcPtr->username);
    printf("||..........###########.........||%26s||\n", "");
    printf("||..........###########.........||==========================||\n");
    printf("||..........###########.........||%26s||\n", "");
    printf("||...........#########..........|| Followers: %10d    ||\n", followers);
    printf("||............#######...........|| Following: %10d    ||\n", following);
    printf("||......###################.....||%26s||\n", "");
    printf("||....#######################...||============================\n");
    printf("||..............................|| Tweets:    %10d    ||\n", tweets);
    divLine(62);
    printf("||  No. ||%6sProfile Menu%32s||\n", "", "");
    divLine(62);
    printf("||  1.  ||%6sView Followers%30s||\n","","");
    divLine(62);
    printf("||  2.  ||%6sView Following%30s||\n");
    divLine(62);
    printf("||  2.  ||%6sView Tweets%33s||\n","","");
    divLine(62);
    printf("||  3.  ||%6sReturn to Menu%30s||\n","","");
    divLine(62);
    printf("Enter: ");
}

void followRow(char* text1, char* text2){
    printf("||%8s ||%16s ||\n", text1, text2);
}

void line(void){
    for (int i=0;i<34;i++){
        printf("=");
    }
    printf("\n");
}

int followTable(accountNodePtr acLoopPtr, accountNodePtr curAcPtr){
    int pos=1, posConv[10], tempPos, i, x, match;
    char posStr[10];
    followNodePtr followingPtr = NULL;
    line();
    row("No.  ", "Users   ");
    while (acLoopPtr!=NULL){
        match=0;
        followingPtr = curAcPtr->followingPtr;
        if (strcmp(acLoopPtr->username, curAcPtr->username)){
            match++;
        }else{
            while (followingPtr!=NULL){
                if (strcmp(followingPtr->username, curAcPtr->username)){
                    match++;
                    followingPtr=NULL;
                }else{
                    followingPtr=followingPtr->nextPtr;
                }
            }
        }
        if (match==0){
            tempPos=pos;
            i=0;
            while (tempPos>0){
                posConv[i]=tempPos%10;
                tempPos=tempPos/10;
                i++;
            }
            for (x=i-1, i=0; x>=0; x--, i++){
                posStr[i]=posConv[x]+48;
            }
            posStr[i]='.';
            posStr[i+1]='\0';
            line();
            row(posStr, acLoopPtr->username);
            acLoopPtr=acLoopPtr->nextPtr;
            pos++;
        }
    }
    line();
    return pos;
}

void divLine(int len){
    for (int i=0;i<len;i++){
        printf("=");
    }
    printf("\n");
}

void row(char* text1, char* text2){
    printf("||%4s ||%16s ||\n", text1, text2);
}