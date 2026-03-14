add_executable(Example FirstWindow.cpp)
set_target_properties(Example PROPERTIES WIN32_EXECUTABLE ON)
target_link_libraries(Example PRIVATE 
    Whirlpool
    SDL3
    winmm
    imm32
    version
    setupapi
    ole32
    oleaut32
)