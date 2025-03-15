// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	if (st == NULL){
		errno = EFAULT;
		return -1;
	}
	if (fd < 0){
		errno = EBADF;
		return -1;
	}
	int result = syscall(5, fd, st);
	if (result == -1){
		errno = EBADF; 
		return -1;
	}
	return 0;
}
