
// voir : https://www.geeksforgeeks.org/linux-unix/posix-shared-memory-api/

#include <stdio.h>

int main(int argc, char *argv[]) {
  int fd = shm_open("/on_segment", O_CREAT | O_RDWR, 0666);
  return;
}
