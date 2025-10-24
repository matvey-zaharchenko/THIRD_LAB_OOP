FROM gcc:14.2.0

RUN apt-get update && apt-get install -y \
    cmake python3 python3-dev python3-pip wrk clangd bear \
    && rm -rf /var/lib/apt/lists/*

RUN pip install numpy --break-system-packages


RUN ln -sf /usr/local/include/c++/14.2.0 /usr/include/c++/14

WORKDIR /workspace


ENV CXX=/usr/local/bin/g++
ENV CC=/usr/local/bin/gcc