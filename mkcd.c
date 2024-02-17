#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char *shell = getenv("SHELL");

    if (argc != 2)
    {
        printf("Usage: %s <directory name>\n", argv[0]);
        goto spawn;
    }

    if (mkdir(argv[1], 0755) == -1)
    {
        perror("mkdir");
        goto spawn;
    }

    if (chdir(argv[1]) == -1)
    {
        perror("chdir");
        goto spawn;
    }

    spawn:
        execl(shell, shell, NULL);
}
