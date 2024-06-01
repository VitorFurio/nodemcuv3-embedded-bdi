cmake_minimum_required(VERSION 3.5)

FILE(GLOB EMB_BDI_AGENT_SOURCES ../embedded-bdi/lib/agent/*.cpp)
FILE(GLOB EMB_BDI_BDI_SOURCES ../embedded-bdi/lib/bdi/*.cpp)
FILE(GLOB EMB_BDI_LIB_SOURCES ../embedded-bdi/lib/lib/*.cpp)
FILE(GLOB EMB_BDI_SYNTAX_SOURCES ../embedded-bdi/lib/syntax/*.cpp)
FILE(GLOB EMB_BDI_COMMUNICATION_SOURCES ../embedded-bdi/lib/communication/*.cpp)

set(COMPONENT_SRCS src/agent_loop.cpp data/functions.cpp data/wifi_station.c ${EMB_BDI_AGENT_SOURCES} ${EMB_BDI_BDI_SOURCES} ${EMB_BDI_LIB_SOURCES} ${EMB_BDI_SYNTAX_SOURCES} ${EMB_BDI_COMMUNICATION_SOURCES})
set(COMPONENT_ADD_INCLUDEDIRS "src ../embedded-bdi/lib data")

register_component()

