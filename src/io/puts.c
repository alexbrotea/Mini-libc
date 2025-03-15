#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <internal/syscall.h>
#include <errno.h>

int puts(const char *str)
{
    if (str == NULL){
        errno = EINVAL;
        return -1;
    }
    size_t len = strlen(str);
    ssize_t written = syscall(1, 1, str, len);
    if (written < 0){
        return -1;
    }
    written = syscall(1, 1, "\n", 1);
    if (written < 0){
        return -1;
    }
    return len + 1;
}
