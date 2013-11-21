#!/bin/sh
#
# fastbuffers script
# based on work of theJPackage Project <http://www.jpackage.org/>

# Configuration
BASE_FLAGS=""
BASE_JARS="antlr-2.7.7 stringtemplate-3.2.1 fastbuffers"
BASE_OPTIONS=""
MAIN_CLASS=com.eprosima.fastbuffers.FastBuffers

# Source functions library
. /usr/share/java-utils/java-functions

# Set parameters
set_jvm
set_classpath $BASE_JARS
set_flags $BASE_FLAGS
set_options $BASE_OPTIONS
# Let's start
run "$@"
