cmake_minimum_required(VERSION 3.16)

project(fungus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fungus main.cpp)
target_include_directories(fungus PRIVATE /usr/include)
target_link_directories(fungus PRIVATE /usr/lib)
target_link_libraries(fungus PRIVATE raylib pugixml)

include(GNUInstallDirs)
install(TARGETS fungus
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
