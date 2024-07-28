add_executable(aritmetica_buffer_cpp aritmetica.cpp)
add_executable(aritmetica_buffer_c aritmetica.c)
add_jar(aritmetica_buffer_java aritmetica.java ENTRY_POINT aritmetica)
configure_file(aritmetica.py aritmetica_buffer.py COPYONLY)
