// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
    if (path == NULL || buf == NULL){
        errno = EFAULT;
        return -1;
    }
    int result = syscall(4, path, buf);
    if (result < 0){
        if (errno == 0 || errno != ENOENT){
            errno = ENOENT;
        }
        return -1;
    }
    return 0;
}
