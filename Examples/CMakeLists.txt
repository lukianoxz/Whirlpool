add_executable(Example Music.cpp)

if (WIN32)
    set_target_properties(Example PROPERTIES WIN32_EXECUTABLE ON)
    target_link_libraries(Example PRIVATE 
        winmm
        imm32
        version
        setupapi
        ole32
        oleaut32
    )
endif()

target_link_libraries(Example PRIVATE 
    Whirlpool
    SDL3
)