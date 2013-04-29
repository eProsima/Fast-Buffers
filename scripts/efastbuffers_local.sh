#!/bin/sh

dir="`dirname \"$0\"`"

if [ x$JAVA_HOME = x ]; then
	echo "JAVA_HOME environment variable was not set"
	exit 1
fi

exec "${JAVA_HOME}/bin/java" -Djava.ext.dirs="$dir/../lib" com.eprosima.ebuffers.eBuffers "$@"

