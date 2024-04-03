#include <stdio.h>
#include <unistd.h>
#include <winsock.h>


int main() {
    char buffer[1024];
    struct timeval tv;
    int fd = fileno(stdout); // get file descriptor of stdout
    FD_ZERO(&tv); // clear the select set for tv
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    FD_SET(fd, &tv); // add stdout to the select set

    if (select(fd+1, NULL, NULL, NULL, &tv) == -1) {
        printf("Timed out!\n");
    } else {
        fgets(buffer, sizeof(buffer), stdin); // read input from user
        printf("You entered: %s\n", buffer);
    }

    return 0;
}
