#!/bin/bash

if [ $# -eq 0 ]; then
  echo "No arguments supplied"
  exit 1
fi

if [ "$#" -ne 1 ]; then
  echo "Illegal number of parameters"
  exit 1
fi

if [[ "$1" == "v1-traditional" ]] || [[ "$1" == "v2-traditional" ]] || [[ "$1" == "v3-traditional" ]]; then
  version=v${1:1:1}
  rm -rf main/data/*
  rm -rf main/src/config/*
  rm -rf main/src/agent*
  rm -f main/CMakeLists.txt
  rm -f agent.config
  cp examples/vacuum/$version/traditional/functions.* main/data/
  cp examples/vacuum/$version/traditional/agent_loop.c main/src/
  cp examples/vacuum/$version/traditional/CMakeLists.txt main/
fi

if [[ "$1" == "v1-reactive" ]] || [[ "$1" == "v2-reactive" ]] || [[ "$1" == "v3-reactive" ]]; then
  version=v${1:1:1}
  rm -rf main/data/*
  rm -rf main/src/config/*
  rm -rf main/src/agent*
  rm -rf main/CMakeLists.txt
  cp examples/vacuum/$version/bdi_reactive/agentspeak.asl main/data/
  cp examples/vacuum/$version/bdi_reactive/functions.* main/data/
  cp examples/vacuum/$version/bdi_reactive/agent_loop.cpp main/src/
  cp examples/vacuum/$version/bdi_reactive/CMakeLists.txt main/
  cp examples/vacuum/$version/bdi_reactive/agent.config .
fi

if [[ "$1" == "v1-proactive" ]] || [[ "$1" == "v2-proactive" ]] || [[ "$1" == "v3-proactive" ]]; then
  version=v${1:1:1}
  rm -rf main/data/*
  rm -rf main/src/config/*
  rm -rf main/src/agent*
  rm -rf main/CMakeLists.txt
  cp examples/vacuum/$version/bdi_proactive/agentspeak.asl main/data/
  cp examples/vacuum/$version/bdi_proactive/functions.* main/data/
  cp examples/vacuum/$version/bdi_proactive/agent_loop.cpp main/src/
  cp examples/vacuum/$version/bdi_proactive/CMakeLists.txt main/
  cp examples/vacuum/$version/bdi_proactive/agent.config .
fi


	## 	PARA O AGENTE COMUNICADOR: 	##

if [[ "$1" == "speaking-traditional" ]]; 
then
  rm -rf main/data/*
  rm -rf main/src/config/*
  rm -rf main/src/agent*
  rm -f main/CMakeLists.txt
  rm -f agent.config
  cp examples/speaking/traditional/functions.* main/data/
  cp examples/speaking/wifi_functions/wifi_station.* main/data/
  cp examples/speaking/traditional/agent_loop.c main/src/
  cp examples/speaking/traditional/CMakeLists.txt main/
fi

if [[ "$1" == "speaking-bdi" ]];
then
  rm -rf main/data/*
  rm -rf main/src/config/*
  rm -rf main/src/agent*
  rm -rf main/CMakeLists.txt
  cp examples/speaking/bdi/agentspeak.asl main/data/
  cp examples/speaking/bdi/functions.* main/data/
  cp examples/speaking/wifi_functions/wifi_station.* main/data/
  cp examples/speaking/bdi/agent_loop.cpp main/src/
  cp examples/speaking/bdi/CMakeLists.txt main/
  cp examples/speaking/bdi/agent.config .
fi
