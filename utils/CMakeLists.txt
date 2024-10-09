target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
        src/ArgumentParser.cpp
)