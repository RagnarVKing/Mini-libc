// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    return syscall(35, req, rem);
}
