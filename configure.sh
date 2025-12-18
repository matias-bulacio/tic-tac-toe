#!/bin/bash
set -e

. vars.sh

mkdir -p ${TTT_ALL_DIRS}

meson setup ${TTT_RELEASE_D}	--buildtype=release
meson setup ${TTT_DEBUG_D}		--buildtype=debug

ln -s ${TTT_DEBUG_D}/compile_commands.json ./compile_commands.json
