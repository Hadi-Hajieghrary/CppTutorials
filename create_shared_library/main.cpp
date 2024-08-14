#define shared_lib_path "/root/cpp_ws/build/create_shared_library"

#include "my_static_library.hpp"

#include <filesystem>

#include <dlfcn.h>

int main(int argc, char** argv){

    // Using the print function which is statically linked to this program
    staticPrint("Hello Static World!\n");


    // Loading the print function from a shared library
    // Not even the related header file is included in this code, Although,
    // The best practice is to include the header file so the intelisense of the code editor could help us with the syntax.
    // The absolute path to the shared library should be provided here.
    std::filesystem::path lib_path = shared_lib_path;
    lib_path = lib_path / "libmy_shared_library.so";
    void* handle = dlopen(lib_path.string().c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error loading library: " << dlerror() << std::endl;
        return 1;
    }
    dlerror();

    // Definning a function type with reflects the signature of the function which will be loaded from the shared library
    typedef void (*print_func)(const std::string&);
    print_func shared_Print = (print_func) dlsym(handle, "sharedPrint");
    
    // Check for errors
    char* error = dlerror();
    if (error != nullptr) {
        std::cerr << "Error loading symbol: " << error << std::endl;
        dlclose(handle);
        return 1;
    }

    shared_Print("Hello Shared World!\n");
    
    dlclose(handle);

    return 0;

}
