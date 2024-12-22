set(target ${MP4_LIBRARY})

file(GLOB hdrs "*.h*" "${MP4_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

add_library(${target} STATIC ${srcs} ${hdrs})
target_link_libraries(${target} ${LIBRARY_DEPS})
