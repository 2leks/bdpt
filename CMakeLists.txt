cmake_minimum_required(VERSION 3.16)
project(trace)

add_executable(${PROJECT_NAME} 
    ${PROJECT_SOURCE_DIR}/src/main.cpp 
    ${PROJECT_SOURCE_DIR}/src/utils/vec3.cpp 
    ${PROJECT_SOURCE_DIR}/src/utils/rng.cpp 
    ${PROJECT_SOURCE_DIR}/src/utils/scene.cpp 
    ${PROJECT_SOURCE_DIR}/src/mats/diffuse.cpp 
    ${PROJECT_SOURCE_DIR}/src/integrator/path.cpp 
    ${PROJECT_SOURCE_DIR}/src/integrator/interaction.cpp 
    ${PROJECT_SOURCE_DIR}/src/geometry/triangle.cpp 
    ${PROJECT_SOURCE_DIR}/src/geometry/sphere.cpp 
    ${PROJECT_SOURCE_DIR}/src/geometry/ray.cpp 
)

include_directories(include)
find_package(OpenMP REQUIRED)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenMP::OpenMP_CXX)
add_compile_options(-Wall -Wextra -pedantic -Werror)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
