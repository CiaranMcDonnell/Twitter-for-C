#include "u_int.h"

void follow(accountNodePtr startPtr, accountNodePtr curAcPtr){
    /*
    It's a function that allows a user to follow another user.
    */
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
        /* 
        Checking if the current account is following the account in the loop. If it is, it will decrement
        the total accounts.
        */
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
        /*
        Adding the current account to the account that is being followed's following list and adding the
        account that is being followed to the current account's followers list.
        */
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
    /*
    Removes a user from the current user's following list and remove the current user
    from the user's followers list.
    */
    int totAcs, choiceAc;
    accountNodePtr acLoopPtr = startPtr;
    followNodePtr followingPtr = curAcPtr->followingPtr;
    followNodePtr followingUserPtr;
    followNodePtr tempPtr;
    totAcs = profFolTable(followingPtr, "<< Users You Follow >>");
    if(totAcs>0){
        printf("\nEnter: ");
        fflush(stdin);
        while(scanf("%i", &choiceAc)==0 || choiceAc<1 || choiceAc>totAcs){
            printf("Input must be an integer within the range of the table\nPlease try again\n\nEnter: ");
            fflush(stdin);
        }
        totAcs=0;
        /*
        Removing the account from the list of accounts that the current account is following.
        */
        if (choiceAc==1){
            while (strcmp(followingPtr->username, acLoopPtr->username)!=0){
                acLoopPtr=acLoopPtr->nextPtr;
            }
            tempPtr=followingPtr->nextPtr;
            free(curAcPtr->followingPtr);
            curAcPtr->followingPtr=tempPtr;
        }else{
            while(totAcs<(choiceAc-2)){
                followingPtr=followingPtr->nextPtr;
                totAcs++;
            }
            while (strcmp(followingPtr->nextPtr->username, acLoopPtr->username)!=0){
                acLoopPtr=acLoopPtr->nextPtr;
            }
            tempPtr=followingPtr->nextPtr->nextPtr;
            free(followingPtr->nextPtr);
            followingPtr->nextPtr=tempPtr;
        }
        
        /*
        Freeing the memory of the first node in the linked list.
        */
        followingUserPtr = acLoopPtr->followersPtr;
        tempPtr=followingUserPtr->nextPtr;
        free(followingUserPtr);
        acLoopPtr->followersPtr=tempPtr;
        printf("\nYou have unfollowed %s!\n\n", acLoopPtr->username);
    }
}

void viewProfile(accountNodePtr curAcPtr, tweetsNodePtr startTwtPtr){
    /*
    It displays the profile of the current user, and allows them to view their followers, following, and
    tweets
    */
    int followers = 0, following = 0, tweets=0, menChoice, home=0;
    followNodePtr followersPtr = curAcPtr->followersPtr;
    followNodePtr followingPtr = curAcPtr->followingPtr;
    tweetsNodePtr loopTwtPtr = startTwtPtr;
    /*
    Counting the number of followers, following and tweets of the current account.
    */
    while(followersPtr!=NULL){
        followers++;
        followersPtr = followersPtr->nextPtr;
    }
    while(followingPtr!=NULL){
        following++;
        followingPtr = followingPtr->nextPtr;
    }
    while(loopTwtPtr !=NULL){
        if (!strcmp(loopTwtPtr->username, curAcPtr->username)){
            tweets++;
        }
        loopTwtPtr = loopTwtPtr->nextPtr;
    }
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
            int num=0;
            loopTwtPtr = startTwtPtr;
            while(loopTwtPtr != NULL){
                if(!strcmp(loopTwtPtr->username, curAcPtr->username)){
                    num++;
                    printNewsFeed(num, loopTwtPtr);
                }
                loopTwtPtr=loopTwtPtr->nextPtr;
            }
            if(num==0){
                printf("\nYou have no tweets\nTry getting yourself out there and sharing your opinions with the world\n\n");
            }else{
                divLine(62);
                printf("\n");
            }
            pressCont();
            printf("\n");
            profMen();
        }else{
            home=1;
        }
    }
}

int profFolTable(followNodePtr followPtr, char title[]){
    /*
    It prints a table of the followers of a user.
    */
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
    return following;
}

void profMen(void){
    /*
    It prints a menu for the user to choose from.
    */
    divLine(62);
    printf("||  No. ||%6sProfile Menu%32s||\n", "", "");
    divLine(62);
    printf("||  1.  ||%6sView Followers%30s||\n","","");
    divLine(62);
    printf("||  2.  ||%6sView Following%30s||\n","","");
    divLine(62);
    printf("||  3.  ||%6sView Tweets%33s||\n","","");
    divLine(62);
    printf("||  4.  ||%6sReturn to Menu%30s||\n","","");
    divLine(62);
    printf("Enter: ");
}

void followRow(char* text1, char* text2){
    /*
    It prints out the text in the parameters.
    */
    printf("||%8s ||%16s ||\n", text1, text2);
}

int followTable(accountNodePtr acLoopPtr, accountNodePtr curAcPtr){
    /*
    It prints out a table of all the users that the current user is not following.
    */
    int pos=1, posConv[10], tempPos, i, x, match;
    char posStr[10];
    followNodePtr followingPtr = NULL;
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
            if (pos==1){
                divLine(32);
                followRow("No.", "Users     ");
            }
            intToChar(pos, posStr);
            divLine(32);
            followRow(posStr, acLoopPtr->username);
            pos++;
        }
        acLoopPtr=acLoopPtr->nextPtr;
    }
    pos--;
    if (pos!=0){
        divLine(32);     
    }
    return pos;
}

void row(char* text1, char* text2){
    /*
    It prints a row of text with a border
    */
    printf("||%4s ||%16s ||\n", text1, text2);
}

void intToChar(int start, char *posStr){
    /*
    It converts an integer to a string.
    */
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
    /*
    This function prints continue to the screen and waits for the user to press any key before
    continuing.
    */
    printf("<<< Press any key to continue >>> ");
    fflush(stdin);
    getchar();
}


void deleteAccount(accountNodePtr *startPtr, accountNodePtr *curAcPtr, tweetsNodePtr *startTwtPtr){
    /*
    The function deletes the current account, removes the current account from the followers list of all
    the users that the current account is following, removes the current account from the following list
    of all the users that are following the current account, and deletes all the tweets of the current
    account.
    */
    accountNodePtr acLoopPtr;
    accountNodePtr tempCur = *curAcPtr;
    followNodePtr followingPtr = tempCur->followingPtr;
    followNodePtr tempPtr;
    followNodePtr tempPtr2;
    tweetsNodePtr iterTwtPtr;
    iterTwtPtr = *startTwtPtr;
    /*
    Deletes all tweets posted by the current user.
    */
    while (iterTwtPtr!=NULL){
        if (strcmp(iterTwtPtr->username, tempCur->username)==0){
            iterTwtPtr = *startTwtPtr;
            iterTwtPtr=iterTwtPtr->nextPtr;
            free(*startTwtPtr);
            *startTwtPtr = iterTwtPtr;
        }else{
            iterTwtPtr=NULL;
        }
    }
    /*
    Removing the current user from the followers list of all the users that the current user is following. 
    */
    while (followingPtr!=NULL){
        acLoopPtr = *startPtr;
        while (strcmp(acLoopPtr->username, followingPtr->username)!=0){
            acLoopPtr=acLoopPtr->nextPtr;
        }
        tempPtr = acLoopPtr->followersPtr->nextPtr;
        free(acLoopPtr->followersPtr);
        acLoopPtr->followersPtr=tempPtr;

        followingPtr=followingPtr->nextPtr;
        free(tempCur->followingPtr);
        tempCur->followingPtr=followingPtr;
    }
    /*
    Deleting the followers of the account that is being deleted.
    */
    tempCur = *curAcPtr;
    while (tempCur->followersPtr!=NULL){
        acLoopPtr = *startPtr;
        while (strcmp(acLoopPtr->username, tempCur->followersPtr->username)!=0){
            acLoopPtr=acLoopPtr->nextPtr;
        }
        if (strcmp(acLoopPtr->followingPtr->username, tempCur->username)==0){
            tempPtr=acLoopPtr->followingPtr->nextPtr;
            free(acLoopPtr->followingPtr);
            acLoopPtr->followingPtr=tempPtr;
        }else{
            tempPtr=acLoopPtr->followingPtr;
            while(strcmp(tempPtr->nextPtr->username, tempCur->username)!=0){
                tempPtr=tempPtr->nextPtr;
            }
            tempPtr2=tempPtr->nextPtr->nextPtr;
            free(tempPtr->nextPtr);
            tempPtr->nextPtr=tempPtr2;
        }
        tempPtr = tempCur->followersPtr->nextPtr;
        free(tempCur->followersPtr);
        tempCur->followersPtr=tempPtr;
    }
    /*
    Deleting the current account. 
    */
    if (*startPtr==*curAcPtr){
        tempCur = *curAcPtr;
        tempCur=tempCur->nextPtr;
        free(*curAcPtr);
        *startPtr=tempCur;
        *curAcPtr=tempCur;
    }else{
        acLoopPtr = *startPtr;
        tempCur = *curAcPtr;
        while (strcmp(acLoopPtr->nextPtr->username, tempCur->username)!=0){
            acLoopPtr=acLoopPtr->nextPtr;
        }
        tempCur=acLoopPtr->nextPtr->nextPtr;
        free(*curAcPtr);
        *curAcPtr=tempCur;
        acLoopPtr->nextPtr=tempCur;
    }
}