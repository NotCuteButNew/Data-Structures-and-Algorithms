cmake_minimum_required ( VERSION 3.0.0 )
project ( chain VERSION 0.1.0 LANGUAGES CXX )

include_directories ( . )

set(src  chainWithIterator.cpp chainWithIterator.h myExceptions.h chainNode.h linearList.h)

add_executable(chainWithIterator ${src})