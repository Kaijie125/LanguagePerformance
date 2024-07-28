add_executable(fibo_cpp fibo.cpp)
add_executable(fibo_c fibo.c)
add_jar(fibo_java fibo.java ENTRY_POINT fibo)
configure_file(fibo.py fibo.py COPYONLY)
