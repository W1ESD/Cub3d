#include<unistd.h>

int main()
{
    char *a = "/usr/bin/afplay";
    char *cmd[3];
    cmd[0] = "afplay";
    cmd[1] = "../../audio.mp3";
    cmd[2]  = NULL;
    execve(a, cmd, NULL);
}
