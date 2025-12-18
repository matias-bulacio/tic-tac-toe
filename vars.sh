#!/bin/bash

if [ ! ${TTT_BUILD} ]; then
	export TTT_BUILD=.
fi
if [ ! ${TTT_RELEASE_D} ]; then
	export TTT_RELEASE_D=${TTT_BUILD}/release
fi
if [ ! ${TTT_DEBUG_D} ]; then
	export TTT_DEBUG_D=${TTT_BUILD}/debug
fi

# All dirs

if [ ! ${TTT_ALL_COMPILE_DIRS} ]; then
	export TTT_ALL_COMPILE_DIRS="${TTT_RELEASE_D} ${TTT_DEBUG_D}"
fi

if [ ! ${TTT_ALL_DIRS} ]; then
	export TTT_ALL_DIRS="${TTT_ALL_COMPILE_DIRS} ${TTT_BUILD}"
fi
