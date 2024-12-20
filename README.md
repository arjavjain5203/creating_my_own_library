
# My C Library

This repository demonstrates how to create and use a static and dynamic library in C on Windows. It includes the following files:
- `mylibrary.c`: The source file for the library.
- `mylibrary.h`: The header file for the library.
- `main.c`: A sample program that uses the library.

## Getting Started

### Prerequisites

- A C compiler like `gcc` from the MinGW or MSYS2 projects, or `cl` from Visual Studio.

### Files

- `mylibrary.c`
- `mylibrary.h`
- `main.c`

### Creating a Static Library

1. **Write Your C Code**: Ensure you have your source files (`mylibrary.c` and `mylibrary.h`).

2. **Compile to Object File**: Use the following command to compile the source file into an object file.

    ```sh
    gcc -c mylibrary.c -o mylibrary.o
    ```

3. **Create the Static Library**: Use the `ar` tool to create a static library archive.

    ```sh
    ar rcs libmylibrary.a mylibrary.o
    ```

    This will create a static library named `libmylibrary.a`.

4. **Use the Static Library**: Compile your program with the library.

    ```sh
    gcc main.c -L. -lmylibrary -o main
    ```

### Creating a Dynamic Library (DLL)

1. **Write Your C Code**: Ensure you have your source files (`mylibrary.c` and `mylibrary.h`).

2. **Compile to Object File**: Use the following command to compile the source file into an object file.

    ```sh
    gcc -c -DMYLIBRARY_EXPORTS mylibrary.c -o mylibrary.o
    ```

3. **Create the Dynamic Library**: Use the compiler to create a DLL.

    ```sh
    gcc -shared -o mylibrary.dll mylibrary.o
    ```

    This will create `mylibrary.dll`.

4. **Use the Dynamic Library**: Compile your program with the import library if generated (`mylibrary.lib`).

    ```sh
    gcc main.c -L. -lmylibrary -o main
    ```

5. **Run the Program**: Ensure `mylibrary.dll` is in your PATH or in the same directory as your executable when you run it.

### Tools and Environment

- **Compiler**: You can use `gcc` from the MinGW or MSYS2 projects, or `cl` from Visual Studio.
- **Makefile (Optional)**: You can create a Makefile to automate the build process.

    Example Makefile:

    ```makefile
    # Makefile
    all: static dynamic

    static:
        gcc -c mylibrary.c -o mylibrary.o
        ar rcs libmylibrary.a mylibrary.o

    dynamic:
        gcc -c -DMYLIBRARY_EXPORTS mylibrary.c -o mylibrary.o
        gcc -shared -o mylibrary.dll mylibrary.o

    clean:
        rm -f *.o *.a *.dll
    ```

    Run the Makefile with `make`.

### Example Usage

The `main.c` file demonstrates how to use the created library:

```c
#include <stdio.h>
#include "mylibrary.h"

int main() {
    int x;
    printf("Enter the number to find its factorial: ");
    scanf("%d", &x);
    int f = factorial(x);
    printf("%d\n", f);
    return 0;
}
```

### Commands Summary

```sh
# Compile to object file
gcc -c mylibrary.c -o mylibrary.o

# Create static library
ar rcs libmylibrary.a mylibrary.o

# Compile with static library
gcc main.c -L. -lmylibrary -o main

# Compile to object file for DLL
gcc -c -DMYLIBRARY_EXPORTS mylibrary.c -o mylibrary.o

# Create dynamic library
gcc -shared -o mylibrary.dll mylibrary.o

# Compile with dynamic library
gcc main.c -L. -lmylibrary -o main
```


