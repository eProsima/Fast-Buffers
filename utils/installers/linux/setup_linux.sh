#!/bin/sh

# This scripts creates a tar.gz file with all the linux installation
# @param The version of the project

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

	# Copy example and create makefiles.
	mkdir -p tmp/$project/examples
	mkdir -p tmp/$project/examples/HelloWorld
	cp ../../../examples/HelloWorld/HelloWorldExample.cpp tmp/$project/examples/HelloWorld
	cp ../../../examples/HelloWorld/HelloWorld.idl tmp/$project/examples/HelloWorld
	cp ../../../examples/HelloWorld/makefile_HelloWorldExample tmp/$project/examples/HelloWorld
	cp ../../../examples/HelloWorld/README.txt tmp/$project/examples/HelloWorld
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	sed "s/TARGET_TO_SUBSTITUTE/i86Linux2.6gcc${gccversion}/g" tmp/$project/examples/HelloWorld/makefile_HelloWorldExample > tmp/$project/examples/HelloWorld/makefile_HelloWorldExample_i86Linux2.6gcc${gccversion}
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	sed "s/TARGET_TO_SUBSTITUTE/x64Linux2.6gcc${gccversion}/g" tmp/$project/examples/HelloWorld/makefile_HelloWorldExample > tmp/$project/examples/HelloWorld/makefile_HelloWorldExample_x64Linux2.6gcc${gccversion}
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	rm tmp/$project/examples/HelloWorld/makefile_HelloWorldExample

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
	cp ../../../classes/*.jar tmp/$project/classes
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy scripts
	mkdir -p tmp/$project/scripts
	cp ../../../scripts/fastbuffers.sh tmp/$project/scripts
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	chmod 755 tmp/$project/scripts/fastbuffers.sh

	# CDR headers
	mkdir -p tmp/$project/include
	cp -r ../../../../CDR/include/cdr tmp/$project/include
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
        if [ -d tmp/$project/include/cdr/.svn ]; then
            find tmp/$project/include/cdr -iname .svn -exec rm -rf {} \;
        fi

	# Copy eProsima header files
	mkdir -p tmp/$project/include/cdr/eProsima_cpp
	cp $EPROSIMADIR/code/eProsima_cpp/eProsima_auto_link.h tmp/$project/include/cdr/eProsima_cpp
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
	tar cvzf "../${project}_${version}_${distroversion}.tar.gz" $project
	errorstatus=$?
	cd ..
	if [ $errorstatus != 0 ]; then return; fi
}

if [ $# -lt 1 ]; then
	echo "Needs as parameter the version of the product $project"
	exit -1
fi

version=$1

# Take GCC version
. $EPROSIMADIR/scripts/common_pack_functions.sh getGccVersion

# Get distro version
. $EPROSIMADIR/scripts/common_pack_functions.sh getDistroVersion

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
