#include "iface.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main(void)
{
    int fd = shm_open(IFACE_SHM_NAME, O_RDONLY, 0666);
    if (fd == -1) {
        perror("shm_open");
        fprintf(stderr, "start app1 before app2\n");
        return EXIT_FAILURE;
    }

    const struct iface *shared = mmap(NULL, sizeof(*shared), PROT_READ,
                                      MAP_SHARED, fd, 0);
    if (shared == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("app2 consumed iface: x=%f, y=%f\n", shared->x, shared->y);

    munmap((void *)shared, sizeof(*shared));
    close(fd);

    return EXIT_SUCCESS;
}
