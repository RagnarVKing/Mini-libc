// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <unistd.h>

int puts(const char *s) {
    size_t len = strlen(s);

    if (write(1, s, len) != (ssize_t)len) {
        return -1;
    }

    if (write(1, "\n", 1) != 1) {
        return -1;
    }

    return 1;
}
