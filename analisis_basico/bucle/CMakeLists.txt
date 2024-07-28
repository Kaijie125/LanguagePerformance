add_executable(bucle_cpp bucle.cpp)
add_executable(bucle_c bucle.c)
add_jar(bucle_java bucle.java ENTRY_POINT bucle)
configure_file(bucle.py bucle.py COPYONLY)
