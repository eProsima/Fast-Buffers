#!/bin/sh

# This scripts creates a tar.gz file with all the linux installation

project="FastBuffers"

function installer
{
	# Copy documentation.
	mkdir -p tmp/$project/doc
	mkdir -p tmp/$project/doc/pdf
	cp "../../../doc/Installation Manual.pdf" tmp/$project/doc/pdf
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	cp "../../../doc/User Manual.pdf" tmp/$project/doc/pdf
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	cp -r "../../../output/doxygen/html" tmp/$project/doc
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	cp "../../../output/doxygen/latex/refman.pdf" "tmp/$project/doc/pdf/API C++ Manual.pdf"
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy example.
	mkdir -p tmp/$project/examples
	cp -r ../../../examples/HelloWorld tmp/$project/examples
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy licenses.
	cp ../../../doc/licencias/FAST_BUFFERS_LICENSE.txt tmp/$project
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	cp ../../../doc/licencias/LGPLv3_LICENSE.txt tmp/$project
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy README
	cp ../../../README.html tmp/$project
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy Java classes.
	mkdir -p tmp/$project/classes
	cp ../../../lib/*.jar tmp/$project/classes
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy scripts
	mkdir -p tmp/$project/scripts
	cp ../../../scripts/efastbuffers.sh tmp/$project/scripts
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	chmod 755 tmp/$project/scripts/efastbuffers.sh

	# CDR headers
	mkdir -p tmp/$project/include
	cp -r ../../../../CDR/include/cpp tmp/$project/include
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy eProsima header files
	mkdir -p tmp/$project/include/eProsima_cpp
	cp $EPROSIMADIR/code/eProsima_cpp/eProsimaMacros.h tmp/$project/include/eProsima_cpp
    errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	cp $EPROSIMADIR/code/eProsima_cpp/eProsima_auto_link.h tmp/$project/include/eProsima_cpp
    errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy CDR libraries
	mkdir -p tmp/$project/lib

	# Copy i86 CDR libraries. Preserve links.
	mkdir -p tmp/$project/lib/i86Linux2.6gcc${gccversion}
	cp -d ../../../../CDR/lib/i86Linux2.6gcc${gccversion}/* tmp/$project/lib/i86Linux2.6gcc${gccversion}
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy x64 CDR libraries. Preserve links.
	mkdir -p tmp/$project/lib/x64Linux2.6gcc${gccversion}
	cp -d ../../../../CDR/lib/x64Linux2.6gcc${gccversion}/* tmp/$project/lib/x64Linux2.6gcc${gccversion}
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	cd tmp
	tar cvzf "../${project}_${version}_Fedora17.tar.gz" $project
	errorstatus=$?
	cd ..
	if [ $errorstatus != 0 ]; then return; fi
}

if [ -z $1 ]; then
	echo "Needs as parameter the version of the product $project"
	exit -1
fi

version=$1

# Take GCC version
. $EPROSIMADIR/scripts/common_pack_functions.sh getGccVersion

# Create the temporaly directory.
mkdir tmp
mkdir tmp/$project

installer

# Remove temporaly directory
rm -rf tmp

if [ $errorstatus == 0 ]; then
    echo "INSTALLER SUCCESSFULLY"
else
    echo "INSTALLER FAILED"
fi

exit $errorstatus
