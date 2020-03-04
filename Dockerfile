FROM ubuntu:18.04
LABEL maintainer="akhtyamovpavel@gmail.com"

RUN apt-get update && apt-get install -y cmake build-essential vim tmux git wget automake libtool autopoint graphviz

RUN wget https://ftp.gnu.org/gnu/bison/bison-3.5.2.tar.gz && tar -zxvf bison-3.5.2.tar.gz
RUN cd bison-3.5.2 && ./configure && make -j9 && make install && cd ..

RUN apt-get install -y flex

RUN useradd -ms /bin/bash ubuntu
USER ubuntu
WORKDIR /home/ubuntu
