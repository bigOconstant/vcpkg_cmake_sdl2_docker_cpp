from ubuntu:latest

RUN apt-get update
RUN apt-get upgrade -y

#install developer dependencies
RUN apt-get install clang -y
RUN apt-get install cmake -y
RUN apt-get install git -y
RUN apt-get install curl -y
RUN apt-get install zip -y

#install vcpkg package manager
RUN git clone https://github.com/microsoft/vcpkg
RUN ./vcpkg/bootstrap-vcpkg.sh

#install packages for project
RUN /vcpkg/vcpkg install sqlite3

# set work directory for project
WORKDIR /Project
