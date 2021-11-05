#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>
using namespace std;

// if i run this program twice, then each run will have a different process id
// so, if a increase the value of pointer in one of them then it will not
// affect the other process pointer value, 

// to execute, run this command -
// - g++ 04Sample01.cpp -Wl,-no_pie -o 04virtual.out
// - ./virtual.out

double GetTime() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double) t.tv_sec + (double) t.tv_usec/1e6;
}

void Spin(int howlong) {
    double t = GetTime();
    while ((GetTime() - t) < (double) howlong);
}

int main(int argc, char *argv[]) {
    // if (argc != 2) {
    //     fprintf(stderr, "usage: mem <value>\n");
    //     exit(1);
    // }
    int *p; // taken a pointer
    // pointed it to a new memory
    p = (int *) malloc(sizeof(int));
    // print the process id and the address pointed by the pointer.
    printf("(%d) addr pointed to by p: %p\n", (int) getpid(), p);
    *p = 1; // atoi(argv[1]);
    while (1) {
        Spin(1);
        *p = *p + 1;
        printf("(%d) value of p: %d\n", getpid(), *p);
    }
    return 0;
}
