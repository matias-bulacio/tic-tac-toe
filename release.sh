#!/bin/bash

. vars.sh

(
	cd ${TTT_RELEASE_D}
	meson compile
)
