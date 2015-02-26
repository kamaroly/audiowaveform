# We inherit from the same Docker image as official repo
FROM buildpack-deps:jessie

MAINTAINER Thomas Parisot <thomas.parisot@bbc.co.uk>

ENV GMOCK_VERSION 1.7.0
ENV BUILD_TYPE Release

RUN apt-get update
RUN apt-get install -y  unzip \
			make \
			cmake \
			gcc \
			g++ \
			libmad0-dev \
			libsndfile1-dev \
			libgd2-xpm-dev \
			libboost-filesystem-dev \
			libboost-program-options-dev \
			libboost-regex-dev \
			git-core

RUN mkdir -p /audiowaveform/build
WORKDIR /audiowaveform

ADD https://googlemock.googlecode.com/files/gmock-${GMOCK_VERSION}.zip /audiowaveform/gmock-${GMOCK_VERSION}.zip
RUN unzip gmock-${GMOCK_VERSION}.zip
RUN mv gmock-${GMOCK_VERSION} gmock

ADD CMakeLists.txt /audiowaveform/CMakeLists.txt
ADD COPYING /audiowaveform/COPYING
ADD README.md /audiowaveform/README.md
ADD VERSION /audiowaveform/VERSION
ADD debian /audiowaveform/debian
ADD doc /audiowaveform/doc
ADD cmake /audiowaveform/cmake
ADD src /audiowaveform/src
ADD test /audiowaveform/test

WORKDIR build
RUN cmake -D CMAKE_BUILD_TYPE=${BUILD_TYPE} .. && make
RUN make test && cat ./audiowaveform_tests
RUN make install

ENTRYPOINT /usr/local/bin/audiowaveform


