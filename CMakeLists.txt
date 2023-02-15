## Command for compiling:
##      clear; cmake -B build/ -S . -Wno-dev && make -C build/ -j 4 && ./build/RType
## command on mingw
##      cd .. && rm -rf build && cmake -B build/ -S . -G "MinGW Makefiles" -Wno-dev && cd build && mingw32-make -j 4 && cd ..
##

cmake_minimum_required (VERSION 3.11)
project(RType CXX)

if(APPLE)
  message(FATAL_ERROR " :)")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug) 

if (NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -O")
else()
  set(CMAKE_CXX_FLAGS "")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/Modules")

file(GLOB ECS_SRC
"App/ECS/*.cpp"
"App/ECS/Components/*.cpp"
"App/ECS/Systems/*.cpp"
)
file(GLOB ENGINE_SRC
"App/GameEngine/*.cpp"
"App/GameEngine/Managers/*.cpp"
"App/GameEngine/Map/*.cpp"
"App/GameEngine/RType/*.cpp"
"App/GameEngine/RType/Button/*.cpp"
)

file(GLOB LIB_SRC
  "App/Lib/Raylib/rl-cpp/Windows/Window.cpp"
  "App/Lib/Raylib/rl-cpp/Collisions/BoundingBox/BoundingBox.cpp"
  "App/Lib/Raylib/rl-cpp/Collisions/Collision/Collision.cpp"
  "App/Lib/Raylib/rl-cpp/Collisions/Ray/Ray.cpp"
  "App/Lib/Raylib/rl-cpp/Colors/Color.cpp"
  "App/Lib/Raylib/rl-cpp/Image/Image.cpp"
  "App/Lib/Raylib/rl-cpp/Models/Material/Material.cpp"
  "App/Lib/Raylib/rl-cpp/Models/Mesh/Mesh.cpp"
  "App/Lib/Raylib/rl-cpp/Models/Model/Model.cpp"
  "App/Lib/Raylib/rl-cpp/Shaders/Shader.cpp"
  "App/Lib/Raylib/rl-cpp/Shaders/Explosion/Explosion.cpp"
  "App/Lib/Raylib/rl-cpp/Shaders/Skybox/Skybox.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Circle3D/Circle3D.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Cube/Cube.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Cylinder/Cylinder.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Grid/Grid.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Line3D/Line3D.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Plane/Plane.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Point3D/Point3D.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Rectangle/Rectangle.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Sphere/Sphere.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Triangle3D/Triangle3D.cpp"
  "App/Lib/Raylib/rl-cpp/Sounds/Audio/Audio.cpp"
  "App/Lib/Raylib/rl-cpp/Sounds/AudioStream/AudioStream.cpp"
  "App/Lib/Raylib/rl-cpp/Sounds/Music/Music.cpp"
  "App/Lib/Raylib/rl-cpp/Sounds/Sound/Sound.cpp"
  "App/Lib/Raylib/rl-cpp/Sounds/Wave/Wave.cpp"
  "App/Lib/Raylib/rl-cpp/Texts/Text.cpp"
  "App/Lib/Raylib/rl-cpp/Textures/Texture.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/Cursor/Cursor.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/FPS/FPS.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/Gamepad/Gamepad.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/Keyboard/Keyboard.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/Mouse/Mouse.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/View/View.cpp"
)

set(SRCS
  ${LIB_SRC}
  ${ECS_SRC}
  ${ENGINE_SRC}
)



message(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/App ./)
add_executable(RType ${SRCS})

find_package(Boost REQUIRED)
find_package(Raylib REQUIRED)


if(Boost_FOUND)
   message("Boost_VERSION: ${Boost_VERSION}")
   include_directories(${Boost_INCLUDE_DIRS})
   target_include_directories(RType PRIVATE ${Boost_INCLUDE_DIRS})
   target_link_libraries(RType ${Boost_LIBRARIES})
endif()

if (MINGW)


elseif (UNIX)

  target_include_directories(RType PRIVATE ${RAYLIB_INCLUDE_DIRS})
  target_link_libraries(RType raylib)
  add_subdirectory(${raylib_SOURCE_DIR})
  # target_link_libraries(RType dl)
  # target_link_libraries(RType pthread)
  # target_link_libraries(RType GL)




elseif (MSVC)
  target_include_directories(RType PRIVATE ${RAYLIB_INCLUDE_DIRS})
  target_link_libraries(RType raylib)
  add_subdirectory(${raylib_SOURCE_DIR})
  
else()
  message(FATAL_ERROR "You are using an unsupported OS. Only supported OS are UNIX and WINGW. Wait for future releases, we might expand this range. :)")
endif()


# set(CMAKE_COMMAND "ln ")
# set(ARG1 "-s")
# set(ARG2 "build/RType")
# set(ARG3 ".")
# execute_process(COMMAND   ${CMAKE_COMMAND} ${ARG1} ${ARG2} ${ARG3}
#   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#   RESULT_VARIABLE result
#   OUTPUT_VARIABLE var)

# if (result)
#   message(FATAL_ERROR "Failed to create symbolic link")
# endif()

