
add_executable(bfs_cpp bfs.cpp)

set(SOURCES bfs.c deque.c)
add_executable(bfs_c ${SOURCES})

add_jar(bfs_java bfs.java ENTRY_POINT bfs)

configure_file(bfs.py bfs.py COPYONLY)
