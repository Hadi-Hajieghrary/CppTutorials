# Creating a Shared Library

## Creating a Static Library

1. Create a header and corresponding source file.
2. Create the CMakeLists.txt file
3. Create the main.cpp file to use the function in the library.


```
.
├── CMakeLists.txt
|
├── README.md
|
├── include
|   |
│   └── my_static_library.hpp
|
├── main.cpp
|
└── src
    |
    └── my_static_library.cpp
```

(Created by tree -- ```apt install tree```)

## Creating a Shared Library

1. Create a header and corresponding source file
2. Build the shared library 
** There is no need to link the shared library to our main target

```
.
├── CMakeLists.txt
|
├── README.md
|
├── include
|   |
│   └── my_static_library.hpp
|   |
│   └── my_shared_library.hpp
|
├── main.cpp
|
└── src
    |
    └── my_static_library.cpp
    |
    └── my_shared_library.cpp

```

### NOTE:
Providing the absolute path in the code is not recomanded, since, every one compiling the code should adjust the path acording to his/her machine. However, there is a solution for that: using the ```configure_file``` in CMakeLists. To do so, we may create the C++ code with the in which the path to the library is defined as pre-compile derective. This variable will be set once the cmake is invocked and a new source file with be generated.  