#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <fenv.h>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main(void) {
    printf("lgamma(10) = %f, log(9!)=%f\n", lgamma(10), log(2 * 3 * 4 * 5 * 6 * 7 * 8 * 9));
    double pi = acos(-1);
    printf("lgamma(0.5) = %f, log(sqrt(pi)) = %f\n", log(sqrt(pi)), lgamma(0.5));
    printf("lgamma(1) = %f\n", lgamma(1));
    printf("lgamma(+Inf) = %f\n", lgamma(INFINITY));
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("lgamma(0) = %f\n", lgamma(0));

    if (errno == ERANGE) {
        perror("    errno == ERANGE");
    }
    
    if (fetestexcept(FE_DIVBYZERO)) {
        puts("    FE_DIVBYZERO raised");
    }

    _getch();
    return 0;
}