#include "u_int.h"

void follow(accountNodePtr startPtr, accountNodePtr curAcPtr){
    int totAcs;
    accountNodePtr acLoopPtr = startPtr;
    totAcs = followTable(acLoopPtr, curAcPtr);
    while (scanf()){
        
    }
}

void unfollow(accountNodePtr startPtr, accountNodePtr curAcPtr){
    accountNodePtr acLoopPtr = startPtr;
    followTable(acLoopPtr, curAcPtr);
}

int didYouMean(){

}

int viewProfile(){
    divLine(70);
    
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
    printf("\nEnter: ");
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



/*
=================================================================
||                                 USER PROFILE                ||
=================================================================
||  ..............................||                           ||
||  ............#######...........|| Username: Lopsem √        ||
||  ..........###########.........||                           ||
||  ..........###########.........||=============================
||  ..........###########.........||                           ||
||  ............#######...........|| Followers: 44             ||
||  ..........###########.........|| Following: 77             ||
||  ......###################.....||                           ||
||  ....#######################...||=============================
||  ..............................|| Tweets: 52                ||
=================================================================
||  No. ||      Profile Menu                                   ||
================================================================= 
||  1.  ||      choicec                                        ||
=================================================================
||  2.  ||      choicec                                        ||
=================================================================
||  3.  ||      choicec                                        ||
=================================================================
||  4.  ||      choicec                                        || 
=================================================================
Enter:  



*/


