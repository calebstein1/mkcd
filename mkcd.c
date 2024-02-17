#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char *shell = getenv("SHELL");

    if (argc != 2)
    {
        printf("Usage: %s <directory name>\n", argv[0]);
        execl(shell, shell, NULL);
    }

    int nd = mkdir(argv[1], 0755);
    if (nd == -1)
    {
        perror("mkdir");
        execl(shell, shell, NULL);
    }

    int ch = chdir(argv[1]);
    if (ch == -1)
    {
        perror("chdir");
        execl(shell, shell, NULL);
    }

    execl(shell, shell, NULL);
}
