// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    if (!req || req->tv_sec < 0 || req->tv_nsec < 0 || req->tv_nsec >= 1000000000){
        errno = EINVAL;
        return -1;
    }
    long result = syscall(35, req, rem);
    if (result < 0){
        errno = -result;
        return -1;
    }
    return 0;
}
