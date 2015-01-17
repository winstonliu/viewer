add_executable(utxViewer gcsmain.cpp userio.cpp)
install (TARGETS utxViewer DESTINATION /Users/davidkoo/uav/viewer)

include_directories( ../imgsrc/)

#Linked Libraries
target_link_libraries(utxViewer imagestream)
target_link_libraries(utxViewer ${OpenCV_LIBS})

