#include <string.h>
#include <conio.h>
#include <stdio.h>
#include "../header/ui.h"
#include "../header/prgvar.h"

void loadToText(char *);
void input(char*);
int  runCmd(char*);
char plaintext[2048], cmdOpt[2048];

int main()
{
    CLRSCR;
    
    initUI();
    initPrgVar();

    // enableText(&optBox, TRUE, logText.text);
    			
    do 
    {
        show(&logBox);
        clearBlock(3, 3, MAXX - 2, 4);
        MOVEXY(3, 3); 			
        printf("\x1b[38;5;10m $ \x1b[39m");
        
        input(instr);
    } while(runCmd(instr));
    return 0;
}

int runCmd(char* cmd)
{
    char cmdArr[16][64], *cur = *cmdArr;
    int count = 0;
    for (char *c = cmd; *c != 0; ++c){
        if (*c == ' '){
            *cur = 0;
            ++count;
            cur = *(cmdArr + count);
            continue;
        }
        
        *cur = *c;
        ++cur;
    }
    *cur = 0;

    if (strcmp(cmd, "exit") == 0)
        return FALSE;
    
    if (strcmp(cmdArr[0], "load") == 0)
        loadToText(cmdArr[1]);

    if (strcmp(cmd, "cls") == 0){
        clearBox(&optBox);
    }
    if (strcmp(cmdArr[0], "disable") == 0){
        if (strcmp(cmdArr[1], "plt") == 0){
            cptBox.sx = FULL;
            enableBox(&pltBox, FALSE);
        }
        if (strcmp(cmdArr[1], "cpt") == 0) enableBox(&cptBox, FALSE);
        if (strcmp(cmdArr[1], "log") == 0) enableBox(&logBox, FALSE);
        clearBox(&optBox);
        show(&optBox);
    }
    if (strcmp(cmdArr[0], "enable") == 0){
        if (strcmp(cmdArr[1], "plt") == 0){
            cptBox.sx = OVER;
            enableBox(&pltBox, TRUE);
        } 
        if (strcmp(cmdArr[1], "cpt") == 0) enableBox(&cptBox, TRUE);
        if (strcmp(cmdArr[1], "log") == 0) enableBox(&logBox, TRUE);
        clearBox(&optBox);
        show(&optBox);
    }
    return TRUE;
}

void loadToText(char * fileName)
{
    setTextFile(&plainText, fileName);
    readText(&plainText, 0);
    enableText(&pltBox, TRUE, plainText.text);
    showText(&pltBox);
}