#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif

MYLIBRARY_API int factorial(int num);

#endif 

