#!/bin/sh

# This scripts creates a tar.gz file with all the linux installation
# @param The version of the project

project="fastbuffers"

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
	sed "s/TARGET_TO_SUBSTITUTE/i86Linux2.6gcc/g" tmp/$project/examples/HelloWorld/makefile_HelloWorldExample > tmp/$project/examples/HelloWorld/makefile_HelloWorldExample_i86Linux2.6gcc
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	sed "s/TARGET_TO_SUBSTITUTE/x64Linux2.6gcc/g" tmp/$project/examples/HelloWorld/makefile_HelloWorldExample > tmp/$project/examples/HelloWorld/makefile_HelloWorldExample_x64Linux2.6gcc
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

	# Copy Java dependent classes.
	mkdir -p tmp/$project/classes
	cp ../../../classes/antlr-2.7.7.jar tmp/$project/classes
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	cp ../../../classes/stringtemplate-3.2.1.jar tmp/$project/classes
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy build ant script
	cp ../../../build.xml tmp/$project
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	cp ../../../manifest tmp/$project
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy grammar
	cp -r ../../../grammar tmp/$project
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy code
	cp -r ../../../src tmp/$project
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy scripts
	mkdir -p tmp/$project/scripts
	cp ../../../scripts/fastbuffers_local.sh tmp/$project/scripts/fastbuffers.sh
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	chmod 755 tmp/$project/scripts/fastbuffers.sh

	cd tmp
	tar cvzf "../${project}_${version}.tar.gz" $project
	errorstatus=$?
	cd ..
	if [ $errorstatus != 0 ]; then return; fi
}

function rpminstaller
{
	# Remove auxiliary Jar files
	rm -r tmp/$project/classes

	# Change the script form local to general script.
	cp ../../../scripts/fastbuffers_rpm.sh tmp/$project/scripts/fastbuffers.sh
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi
	chmod 755 tmp/$project/scripts/fastbuffers.sh

	# Change the build.xml
	cp build_rpm.xml tmp/$project/build.xml
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Copy SPEC file
	sed "s/VERSION/${version}/g" FastBuffers.spec > ~/rpmbuild/SPECS/FastBuffers.spec
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Create new source
	cd tmp
	tar cvzf "../${project}_${version}_rpm.tar.gz" $project
	errorstatus=$?
	cd ..
	if [ $errorstatus != 0 ]; then return; fi

	# Copy source
	mv "${project}_${version}_rpm.tar.gz" ~/rpmbuild/SOURCES
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Go to directory to build.
	cd ~/rpmbuild/SPECS
	errorstatus=$?
	if [ $errorstatus != 0 ]; then return; fi

	# Build command
	rpmbuild -bb FastBuffers.spec
	errorstatus=$?
	# Return
	cd -
	if [ $errorstatus != 0 ]; then return; fi
}

if [ $# -lt 1 ]; then
	echo "Needs as parameter the version of the product $project"
	exit -1
fi

version=$1

# Get distro version
. $EPROSIMADIR/scripts/common_pack_functions.sh getDistroVersion

# Create the temporaly directory.
mkdir tmp
mkdir tmp/$project

installer

# TODO Detect if the distro suport RPM
[ $errorstatus == 0 ] && { rpminstaller; }

# Remove temporaly directory
rm -rf tmp

if [ $errorstatus == 0 ]; then
    echo "INSTALLER SUCCESSFULLY"
else
    echo "INSTALLER FAILED"
fi

exit $errorstatus
