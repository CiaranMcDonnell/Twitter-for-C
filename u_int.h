#ifndef SE1TWITTERPROJ_U_INT_H
#define SE1TWITTERPROJ_U_INT_H

#include "feed.h"

// Prototypes
void row(char* text1, char* text2);
void follow(accountNodePtr startPtr, accountNodePtr curAcPtr);
void unfollow(accountNodePtr startPtr, accountNodePtr curAcPtr);
void viewProfile(accountNodePtr curAcPtr, tweetsNodePtr startTwtPtr);
int profFolTable(followNodePtr followersPtr, char title[]);
void profMen(void);
void followRow(char* text1, char* text2);
int followTable(accountNodePtr acLoopPtr, accountNodePtr curAcPtr);
void intToChar(int start, char *posStr);
void pressCont(void);
void deleteAccount(accountNodePtr *startPtr, accountNodePtr *curAcPtr, tweetsNodePtr *startTwtPtr);

#endif /* !SE1TWITTERPROJ_U_INT_H */