########################################################################################################################################################
###
### Copyright (C) 2017 by Lucas Brémond
###
### This file is part of the Spacer project.
###
########################################################################################################################################################

### @file                       Spacer/Core/Makefile
### @author                     Lucas Brémond <lucas.bremond@gmail.com>
### @date                       2 Dec 2017

########################################################################################################################################################

SHELL := /bin/bash
RM    := rm -rf

all: ./build/Makefile
	@ $(MAKE) -C build

./build/Makefile:
	@ (mkdir -p build && cd build >/dev/null 2>&1 && cmake ..)

distclean:
	@- (mkdir -p build && cd build >/dev/null 2>&1 && cmake .. >/dev/null 2>&1)
	@- $(MAKE) --silent -C build clean || true
	@- $(RM) ./build/*
	@- $(RM) ./build
	@- $(RM) ./docs/*.html
	@- $(RM) ./docs/*.css
	@- $(RM) ./docs/*.png
	@- $(RM) ./docs/*.jpg
	@- $(RM) ./docs/*.gif
	@- $(RM) ./docs/*.tiff
	@- $(RM) ./docs/*.php
	@- $(RM) ./docs/search
	@- $(RM) ./docs/installdox


ifeq ($(findstring distclean,$(MAKECMDGOALS)),)

    $(MAKECMDGOALS): ./build/Makefile
	@ $(MAKE) -C build $(MAKECMDGOALS)

endif

########################################################################################################################################################