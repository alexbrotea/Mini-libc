// SPDX-License-Identifier: BSD-3-Clause

#ifndef MINI_LIBC_TIME_H
#define MINI_LIBC_TIME_H

#ifdef __cplusplus
extern "C" {
#endif

typedef long int time_t;

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
