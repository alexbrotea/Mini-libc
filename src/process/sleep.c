// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    while (nanosleep(&req, &rem) == -1 && errno == EINTR){
        req = rem;
    }
    return req.tv_sec;
}
