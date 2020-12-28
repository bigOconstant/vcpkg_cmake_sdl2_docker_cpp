from ubuntu:latest

RUN apt-get update
RUN apt-get upgrade -y

#install developer dependencies
RUN apt-get install clang -y
RUN apt-get install cmake -y
RUN apt-get install git -y
RUN apt-get install curl -y
RUN apt-get install zip -y
RUN apt-get install gdb -y
RUN apt-get install pkg-config -y

RUN apt-get install libsdl2-dev -y
RUN apt-get install libsdl2-ttf-dev -y
RUN apt-get install libsdl2-image-dev -y
#install vcpkg package manager
RUN git clone https://github.com/microsoft/vcpkg
RUN ./vcpkg/bootstrap-vcpkg.sh

#install packages for project
RUN /vcpkg/vcpkg install sqlite3
RUN /vcpkg/vcpkg install nlohmann-json
RUN /vcpkg/vcpkg install sdl2
RUN /vcpkg/vcpkg install sdl2pp
RUN /vcpkg/vcpkg install sdl2-mixer
RUN /vcpkg/vcpkg install sdl2-ttf
RUN /vcpkg/vcpkg install sdl2-image

# set work directory for project
WORKDIR /Project
