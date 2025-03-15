// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

#ifndef SYS_close
#define SYS_close 3
#endif

int close(int fd)
{
	/* TODO: Implement close(). */
	int result = syscall(SYS_close, fd);
    if (result == -1) {
        return -1;
    }
    return 0;
}
