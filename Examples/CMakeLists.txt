add_executable(Example FirstWindow.cpp)
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