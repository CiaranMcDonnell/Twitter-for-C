#include "u_int.h"

void follow(accountNodePtr startPtr, accountNodePtr curAcPtr){
    int totAcs, choiceAc;
    accountNodePtr acLoopPtr = startPtr;
    totAcs = followTable(acLoopPtr, curAcPtr);
    if (totAcs>0){
        printf("\nEnter: ");
        fflush(stdin);
        while (scanf("%i", &choiceAc)==0 || choiceAc<1 || choiceAc>totAcs){
            printf("Input must be an integer within the range of the table\nPlease try again\n\nEnter: ");
            fflush(stdin);
        }
        totAcs=0;
        followNodePtr followingPtr;
        while (totAcs<choiceAc){
            if (!strcmp(acLoopPtr->username, curAcPtr->username)){
                totAcs--;
            }else{
                followingPtr = curAcPtr->followingPtr;
                while (followingPtr!=NULL){
                    if (!strcmp(followingPtr->username, acLoopPtr->username)){
                        totAcs--;
                        followingPtr=NULL;
                    }else{
                        followingPtr=followingPtr->nextPtr;
                    }
                }
            }
            totAcs++;
            if (totAcs!=choiceAc){
                acLoopPtr = acLoopPtr->nextPtr;
            }
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
        printf("\nYou are now following %s!\n\n", acLoopPtr->username);
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
    //         if(!strcmp(acLoopPtr->username, curAcPtr->username)){
    //             totAcs--;
    //         }
    //     }
    // }
}

int didYouMean(){

}

void viewProfile(accountNodePtr curAcPtr){
    int followers = 0, following = 0, tweets=913, menChoice, home=0;
    followNodePtr followersPtr = curAcPtr->followersPtr;
    followNodePtr followingPtr = curAcPtr->followingPtr;
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
    profMen();
    while (home==0){
        fflush(stdin);
        while (scanf("%i", &menChoice)==0 || menChoice<1 || menChoice>4){
            printf("Input must be an integer within the range 1-4\nPlease try again\n\nEnter: ");
            fflush(stdin);
        }
        if (menChoice==1){
            if (followers!=0){
                followersPtr = curAcPtr->followersPtr;
                profFolTable(followersPtr, "<< Users Who Follow You >>");
                printf("\n");
            }else{
                printf("\nUnfortunately no users currently follow you :(\n\n");
            }
            pressCont();
            printf("\n");
            profMen();
        }else if (menChoice==2){
            if (following!=0){
                followingPtr = curAcPtr->followingPtr;
                profFolTable(followingPtr, "<< Users You Follow >>");
                printf("\n");
            }else{
                printf("\nUnfortunately, you don't currently follow any users :(\nIf you want to see what twitter for C can offer\ngo change that now!\n\n");
            }
            pressCont();
            printf("\n");
            profMen();
        }else if (menChoice==3){

        }else{
            home=1;
        }
    }
}

void profFolTable(followNodePtr followPtr, char title[]){
    int following=0, spcLen, i;
    char posStr[10];
    spcLen = 28-strlen(title);
    printf("\n");
    divLine(32);
    printf("||");
    for (i=0; i<(spcLen/2); i++){
        printf(" ");
    }
    printf(title);
    for (i=0; i<(spcLen/2+spcLen%2); i++){
        printf(" ");
    }
    printf("||\n");
    while(followPtr!=NULL){
        following++;
        divLine(32);
        intToChar(following, posStr);
        followRow(posStr, followPtr->username);
        followPtr = followPtr->nextPtr;
    }
    divLine(32);
    printf("\n");
}

void profMen(void){
    divLine(62);
    printf("||  No. ||%6sProfile Menu%32s||\n", "", "");
    divLine(62);
    printf("||  1.  ||%6sView Followers%30s||\n","","");
    divLine(62);
    printf("||  2.  ||%6sView Following%30s||\n");
    divLine(62);
    printf("||  3.  ||%6sView Tweets%33s||\n","","");
    divLine(62);
    printf("||  4.  ||%6sReturn to Menu%30s||\n","","");
    divLine(62);
    printf("Enter: ");
}

void followRow(char* text1, char* text2){
    printf("||%8s ||%16s ||\n", text1, text2);
}

int followTable(accountNodePtr acLoopPtr, accountNodePtr curAcPtr){
    int pos=1, posConv[10], tempPos, i, x, match;
    char posStr[10];
    if (acLoopPtr!=NULL){
        followNodePtr followingPtr = NULL;
        divLine(32);
        followRow("No.", "Users     ");
        while (acLoopPtr!=NULL){
            match=0;
            followingPtr = curAcPtr->followingPtr;
            if (!strcmp(acLoopPtr->username, curAcPtr->username)){
                match=1;
            }else{
                while (followingPtr!=NULL){
                    if (!strcmp(followingPtr->username, acLoopPtr->username)){
                        match=1;
                        followingPtr=NULL;
                    }else{
                        followingPtr=followingPtr->nextPtr;
                    }
                }
            }
            if (match==0){
                intToChar(pos, posStr);
                divLine(32);
                followRow(posStr, acLoopPtr->username);
                pos++;
            }
            acLoopPtr=acLoopPtr->nextPtr;
        }
        divLine(32);
    }
    return pos-1;
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

void intToChar(int start, char *posStr){
    char stringRet[10];
    int i=0, x, posConv[10];
    while (start>0){
        posConv[i]=start%10;
        start=start/10;
        i++;
    }
    for (x=i-1, i=0; x>=0; x--, i++){
        stringRet[i]=posConv[x]+48;
    }
    stringRet[i]='.';
    stringRet[i+1]='\0';
    strcpy(posStr,stringRet);
}

void pressCont(void){
    printf("<<< Press any key to continue >>> ");
    fflush(stdin);
    getchar();
}