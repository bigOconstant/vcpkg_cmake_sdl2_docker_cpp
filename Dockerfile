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
RUN apt install libsdl2-2.0-0 -y
RUN apt install libsdl2-image-dev -y
RUN apt install libsdl2-mixer-dev -y
RUN apt install libsdl2-ttf-dev -y


#install vcpkg package manager
RUN git clone --depth 1 https://github.com/microsoft/vcpkg
RUN ./vcpkg/bootstrap-vcpkg.sh

#install packages for project
RUN /vcpkg/vcpkg install sqlite3
RUN /vcpkg/vcpkg install nlohmann-json
RUN /vcpkg/vcpkg install sdl2
RUN /vcpkg/vcpkg install sdl2pp
RUN /vcpkg/vcpkg install sdl2-mixer
RUN /vcpkg/vcpkg install sdl2-ttf
RUN /vcpkg/vcpkg install sdl2-image


# Create local user to avoid file permission issues
ARG USERNAME=developer 

ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN apt install sudo -y


RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    #
    # add sudo support
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME

RUN sudo chown -R $USERNAME /vcpkg 
# set work directory for project
WORKDIR /Project

RUN sudo chown -R $USERNAME /Project 


