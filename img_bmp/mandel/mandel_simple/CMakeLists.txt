
add_executable(mandel_cpp mandel.cpp)
add_executable(mandel_c mandel.c)
add_jar(mandel_java mandel.java ENTRY_POINT mandel)
configure_file(mandel.py mandel.py COPYONLY)
