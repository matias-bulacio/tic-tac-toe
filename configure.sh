#!/bin/bash
set -e

if [ ! ${TTT_BUILD} ]; then
	export TTT_BUILD=build/
fi

mkdir -p ${TTT_BUILD}
(
	cd ${TTT_BUILD}
	meson setup ..
)

ln -s ${TTT_BUILD}/compile_commands.json ./compile_commands.json
