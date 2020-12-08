#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "processus.h"

/* reads from keypress, doesn't echo */
int getchmoi(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void init_termios(void)
{
    struct termios mode_buffer,mode_direct;
    tcgetattr(STDOUT_FILENO,&mode_buffer);
    mode_direct=mode_buffer;
    mode_direct.c_oflag |= (ONLCR);
    tcsetattr(STDOUT_FILENO,TCSANOW,&mode_direct);
}