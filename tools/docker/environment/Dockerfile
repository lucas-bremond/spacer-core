FROM fedora:27

LABEL maintainer="lucas.bremond@gmail.com"

# Arguments

ARG version
ARG cpu_count=1

# Environment

ENV LD_LIBRARY_PATH /usr/local/lib:${LD_LIBRARY_PATH}

RUN alias ls='ls --color=auto' \
    && alias ll='ls -halF'

# Common tools

RUN dnf update -y \
    && dnf install -y 'dnf-command(config-manager)' \
    && dnf install -y \
    wget \
    nano \
    htop \
    tree \
    && dnf clean all

# Development Tools

## Compilers

RUN dnf install -y \
    rpm-build \
    ncurses ncurses-devel \
    python python-devel \
    && dnf group install -y "Development Tools" \
    && dnf install -y gcc-c++ gdb lcov \
    && dnf clean all

## CMake [3.10.3]

RUN mkdir /tmp/cmake \
    && cd /tmp/cmake \
    && wget --quiet https://cmake.org/files/v3.10/cmake-3.10.3.tar.gz \
    && tar -xvf cmake-3.10.3.tar.gz \
    && cd cmake-3.10.3 \
    && ./bootstrap \
    && make -j ${cpu_count} \
    && make install \
    && rm -rf /tmp/cmake

# Dependencies

## Boost [1.66.0]

RUN mkdir /tmp/boost \
    && cd /tmp/boost \
    && wget --quiet http://sourceforge.net/projects/boost/files/boost/1.66.0/boost_1_66_0.tar.gz \
    && tar -xvf boost_1_66_0.tar.gz \
    && cd boost_1_66_0 \
    && ./bootstrap.sh \
    && ./b2 -j ${cpu_count} link=static cxxflags=-fPIC install \
    && rm -rf /tmp/boost

## Boost.NumPy

RUN pip install --upgrade pip \
    && pip install numpy

RUN mkdir /tmp/boost.numpy \
    && cd /tmp/boost.numpy \
    && git clone https://github.com/ndarray/Boost.NumPy.git \
    && cd Boost.NumPy \
    && mkdir build \
    && cd build \
    && cmake -DBOOST_ROOT=/usr/local/ -DBoost_USE_STATIC_LIBS=YES -DLIBRARY_TYPE=STATIC -DCMAKE_INSTALL_PREFIX=/usr/local .. \
    && make -j ${cpu_count} \
    && make install \
    && rm -rf /tmp/boost.numpy

## Eigen [3.3.4]

RUN mkdir /tmp/eigen \
    && cd /tmp/eigen \
    && wget --quiet http://bitbucket.org/eigen/eigen/get/3.3.4.tar.gz \
    && tar -xvf 3.3.4.tar.gz \
    && cd eigen-eigen-5a0156e40feb \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make install \
    && rm -rf /tmp/eigen

# Labels

ENV version ${version}

LABEL version="${version}"

# Execution

CMD ["/bin/bash"]