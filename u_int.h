#ifndef SE1TWITTERPROJ_U_INT_H
#define SE1TWITTERPROJ_U_INT_H
#endif //SE1TWITTERPROJ_U_INT_H

#include "account.h"

// Prototypes
void row(char* text1, char* text2);
void divLine(int len);
void follow(accountNodePtr startPtr, accountNodePtr curAcPtr);
void unfollow(accountNodePtr startPtr, accountNodePtr curAcPtr);
int didYouMean(void);
void viewProfile(accountNodePtr curAcPtr);
void line(void);
void followRow(char* text1, char* text2);
int followTable(accountNodePtr acLoopPtr, accountNodePtr curAcPtr);