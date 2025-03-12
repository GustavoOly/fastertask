cmake_minimum_required(VERSION 3.16)

project(datas LANGUAGES C)

# Encontra a biblioteca ncurses
find_package(Curses REQUIRED)

# Adiciona o executável
add_executable(datas main.c src/navegation.c src/tasks.c)

# Linka ncurses ao executável
target_link_libraries(datas PRIVATE ${CURSES_LIBRARIES})

include(GNUInstallDirs)
install(TARGETS datas
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
