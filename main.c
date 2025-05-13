#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios inital_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &inital_termios);
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &inital_termios);
  atexit(disableRawMode);

  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);

  raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
  raw.c_oflag &= ~(OPOST);
  raw.c_cflag &= ~(CS8);
  raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main(int argc, char *argv[])
{
  enableRawMode();

  while (1) {
  char ch = '\0';

    read(STDIN_FILENO, &ch, 1);
    if (iscntrl(ch)) {
      printf("%d\r\n", ch);
    } else {
      printf("%d ('%c')\r\n", ch, ch);
    }
    if (ch == 'q') break;
  }
  return 0;
}
