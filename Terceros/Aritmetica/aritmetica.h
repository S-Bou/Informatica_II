#ifndef __ARITMETICA_H__
#define __ARITMETICA_H__

#include <stdint.h>

#ifndef LIBARCH
#error el simbolo LIBARCH no está definido
#endif

#if     LIBARCH == 32
typedef uint32_t numero_t;
#elif LIBARCH == 16
typedef uint16_t numero_t;
#else
#error ARCH desconocida. Debes definir el tamaño de la palabra en la macro ARCH.
#endif

numero_t suma (numero_t a,numero_t b);
numero_t resta (numero_t a,numero_t b);
numero_t multiplicacion (numero_t a,numero_t b);
numero_t division (numero_t a,numero_t b);


#endif
