#include <unistd.h>

int main(int argc, char *argv[])
{
  char ch;
  while (read(STDIN_FILENO, &ch, 1) == 1 && ch != 'q');
  return 0;
}
