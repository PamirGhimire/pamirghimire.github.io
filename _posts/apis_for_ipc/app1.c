#include "iface.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main(void)
{
    int fd = shm_open(IFACE_SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open");
        return EXIT_FAILURE;
    }

    if (ftruncate(fd, sizeof(struct iface)) == -1) {
        perror("ftruncate");
        close(fd);
        shm_unlink(IFACE_SHM_NAME);
        return EXIT_FAILURE;
    }

    struct iface *shared = mmap(NULL, sizeof(*shared), PROT_READ | PROT_WRITE,
                                MAP_SHARED, fd, 0);
    if (shared == MAP_FAILED) {
        perror("mmap");
        close(fd);
        shm_unlink(IFACE_SHM_NAME);
        return EXIT_FAILURE;
    }

    shared->x = 12.5f;
    shared->y = 42.0f;

    printf("app1 provided iface: x=%f, y=%f\n", shared->x, shared->y);
    printf("press Enter to stop providing the interface...");
    getchar();

    munmap(shared, sizeof(*shared));
    close(fd);
    shm_unlink(IFACE_SHM_NAME);

    return EXIT_SUCCESS;
}
