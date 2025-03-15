// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <fcntl.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	if (length < 0){
		errno = EINVAL;
		return -1;
	}
	long flags = syscall(72, fd, F_GETFL);
	if (flags < 0){
		errno = EBADF;
		return -1;
	}
	if ((flags & O_ACCMODE) == O_RDONLY){
		errno = EINVAL;
		return -1;
	}
	long result = syscall(80, fd, 0, 0);
	if (result > 0){
		errno = EISDIR;
		return -1;
	}
	result = syscall(77, fd, length);
	if (result < 0){
		errno = -result;
		return -1;
	}
	return 0;
}
