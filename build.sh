#!/bin/bash

if [ ! ${TTT_BUILD} ]; then
	export TTT_BUILD=build/
fi

(
	cd ${TTT_BUILD}
	meson compile
)
