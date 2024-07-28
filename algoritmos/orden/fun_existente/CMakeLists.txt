add_executable(orden_cpp orden.cpp)
add_executable(orden_c orden.c)
add_jar(orden_java orden.java ENTRY_POINT orden)
configure_file(orden.py orden.py COPYONLY)
