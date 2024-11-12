#!/bin/bash
# run this when init'ing the project
# this is run in msys2-mingw64 shell
# install at https://www.msys2.org/

pacman -Syu
pacman -S mingw-w64-x86_64-gtk4
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-pkg-config
pacman -S mingw-w64-x86_64-make
