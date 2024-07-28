add_executable(array_cpp array.cpp)
add_executable(array_c array.c)
add_jar(array_java array.java ENTRY_POINT array)
configure_file(array.py array.py COPYONLY)
