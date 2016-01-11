#  *******************************************************************  #
#  regidx C++ code - 2016                                               #
#                                                                       #
#         ** Registry Index for Bilayer Carbon Based Systems **         #
#                                                                       #
#  Written by Pedro Brandimarte (brandimarte@gmail.com)                 #
#                                                                       #
#  Copyright (c), All Rights Reserved                                   #
#                                                                       #
#  This program is free software. You can redistribute it and/or        #
#  modify it under the terms of the GNU General Public License          #
#  (version 3 or later) as published by the Free Software Foundation    #
#  <http://fsf.org/>.                                                   #
#                                                                       #
#  This program is distributed in the hope that it will be useful, but  #
#  WITHOUT ANY WARRANTY, without even the implied warranty of           #
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU     #
#  General Public License for more details (file 'LICENSE_GPL'          #
#  distributed along with this program or at                            #
#  <http://www.gnu.org/licenses/gpl.html>).                             #
#  *******************************************************************  #
#  File: Makefile                                                       #
#                                                                       #
#  Description: main Makefile for building 'regidx' code.               #
#                                                                       #
#  Written by Pedro Brandimarte, Dec 2016.                              #
#  Centro de Fisica de Materiales - CFM                                 #
#  Donostia - San Sebastian, Spain                                      #
#  e-mail: brandimarte@gmail.com                                        #
#  ***************************** HISTORY *****************************  #
#  Original version:    January 2016                                    #
#  *******************************************************************  #

REGIDX_DIR = .
include $(REGIDX_DIR)/make.inc

# If not set, use default variable names.
EXEC ?= regidx

# Check for MKL directory and give user hint how to set it.
ifeq ($(MKL),)
    ifeq ($(MKLROOT),)
        vars_sh  := $(shell which icc 2>/dev/null | perl -pe            \
         's|/bin.*/icc|/mkl/bin/mklvars.sh|')
        vars_csh := $(shell which icc 2>/dev/null | perl -pe            \
         's|/bin.*/icc|/mkl/bin/mklvars.csh|')
        ifeq ($(vars_sh),)
            vars_sh  := /opt/intel/composerxe/mkl/bin/mklvars.sh
            vars_csh := /opt/intel/composerxe/mkl/bin/mklvars.csh
        endif
        $(error Set $$MKLROOT, preferably in your environment, e.g.,    \
         run "source $(vars_sh) intel64" in ~/.bashrc, or               \
         "source $(vars_csh) intel64" in ~/.cshrc)
    endif

    ifeq ($(wildcard $(MKLROOT)),)
        $(error $$MKLROOT=$(MKLROOT) does not exist. Please set         \
         $$MKLROOT to where MKL is installed.)
    endif
endif

#  *******************************************************************  #

# All libraries.
LDLIBS = $(MKL_LIBS) $(OTHER_LIBS)

# All includes.
INCFLAGS = -I. $(MKL_INCLUDE)

# Preprocessor definitions or flags.
#FPPFLAGS = 

# Remove command.
RM = /bin/rm -f

# All source files.
SRCS = Check.cpp Utils.cpp main.cpp

# All objects.
OBJS = $(SRCS:.cpp=.o)

#  *******************************************************************  #

# Rules to compile object files.
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $(INCFLAGS) $(FPPFLAGS) $*.cpp

.cpp:
	make $*.o
	$(CXX) $(CXXFLAGS) -o $(INCFLAGS) $(FPPFLAGS) $* $*.o $(LDLIBS) 

#  *******************************************************************  #

.PHONY: all clean

.DEFAULT_GOAL := all

default: all

all: what $(EXEC)

#  *******************************************************************  #

what:
	@echo "#  ***************************************************  #"
	@echo "#  REGIDX C++ Code 2016                                 #"
	@echo "#                                                       #"
	@echo "#  Written by:                                          #"
	@echo "#                                                       #"
	@echo "#    Pedro Brandimarte (brandimarte@gmail.com)          #"
	@echo "#                                                       #"
	@echo "#  Copyright (c), All Rights Reserved                   #"
	@echo "#                                                       #"
	@echo "#  This program is free software. You can redistribute  #"
	@echo "#  it and/or modify it under the terms of the GNU       #"
	@echo "#  General Public License (version 3 or later) as       #"
	@echo "#  published by the Free Software Foundation            #"
	@echo "#  <http://fsf.org/>.                                   #"
	@echo "#  ***************************************************  #"
	@echo ""
	@echo	
	@echo "Compilation architecture to be used: ${REGIDX_ARCH}"
	@echo
	@echo "Hit ^C to abort..."
	@echo
	@sleep 2

$(EXEC): $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS) $(LDLIBS)

#  *******************************************************************  #

clean:
	$(RM) *~ \#~ .\#* *.o *.log $(EXEC) core a.out

#  *******************************************************************  #
