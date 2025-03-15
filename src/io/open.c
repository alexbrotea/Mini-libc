// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <internal/syscall.h>

int open(const char *filename, int flags, ...)
{
	  /* TODO: Implement open system call. */
    mode_t mode = 0;
    if (flags & O_CREAT){
        va_list args;
        va_start(args, flags);
        va_end(args);
    }
    int fd = syscall(257, AT_FDCWD, filename, flags, mode);
    if (fd < 0){
        errno = -fd;
        return -1;
    }
    return fd;
}
