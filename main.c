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

  raw.c_lflag &= ~(ECHO);

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main(int argc, char *argv[])
{
  enableRawMode();

  char ch;
  while (read(STDIN_FILENO, &ch, 1) == 1 && ch != 'q');
  return 0;
}
