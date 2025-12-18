#!/bin/bash

. vars.sh

(
	cd ${TTT_DEBUG_D}
	meson compile
)
