cmake_minimum_required(VERSION 3.10)
project(PROBLEMSET)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD  99)
# 遍历项目(三级目录)所有的 .cpp 文件
#file (GLOB files *.cpp */*.cpp */*/*.cpp )
file (GLOB_RECURSE files *.cpp *.c)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
#file (GLOB_RECURSE files *.cpp)
