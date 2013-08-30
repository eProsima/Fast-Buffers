#!/bin/sh

#: This script pack FastBuffers product for any platform in Linux.
#
# This script needs the next programs to be run.
# - subversion
# - libreoffice
# - ant
# - doxygen
# Also this script needs the eProsima.documentation.changeVersion macro installed in the system.
#
# Fedora 17: This script has to be run in a Fedora 17 x64.
#            The system has to have installed: libgcc.i686 and libstdc++.i686

errorstatus=0

function setPlatform
{
    platforms=`cat src/platforms`
    if [[ $platforms != *$1* ]]; then
        echo $1 >> src/platforms
    fi
}

function package
{
    # Get current version of GCC.
    . $EPROSIMADIR/scripts/common_pack_functions.sh getGccVersion

    # Update and compile CDR library.
    cd ../CDR
    # Update CDR library.
    svn update
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    # Compile CDR library for i86.
    rm -rf output
    EPROSIMA_TARGET="i86Linux2.6gcc${gccversion}"
    rm -r lib/$EPROSIMA_TARGET
    make
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    # Compile CDR library for x64.
    rm -rf output
    EPROSIMA_TARGET="x64Linux2.6gcc${gccversion}"
    rm -r lib/$EPROSIMA_TARGET
    make
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    cd ../FastBuffers

    # Get the current version of FastBuffers
    . $EPROSIMADIR/scripts/common_pack_functions.sh getVersionFromCPP fastbuffersversion src/version.cpp
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi

    # Try to add platform
    setPlatform "i86Linux2.6gcc${gccversion}"
    setPlatform "x64Linux2.6gcc${gccversion}"

    # Update and compile FastBuffers application.
    # Update FastBuffers application
    svn update
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    # Compile FastBuffers for target.
    rm -rf build
    ant jar
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi

    # Execute FastBuffers tests
    export FAST_BUFFERS_OLD=$FAST_BUFFERS
    export FAST_BUFFERS=$PWD
    cd utils/pcTests
    ./exec_tests.sh $package_targets
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    cd ../..
    export FAST_BUFFERS=$FAST_BUFFERS_OLD

    # Create PDFS from documentation.
    cd doc
    # Installation manual
    soffice --headless "macro:///eProsima.documentation.changeVersion($PWD/Installation Manual.odt,$fastbuffersversion)"
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    # User manual
    soffice --headless "macro:///eProsima.documentation.changeVersion($PWD/User Manual.odt,$fastbuffersversion)"
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    cd ..

    # Create README
    soffice --headless "macro:///eProsima.documentation.changeVersionToHTML($PWD/README.odt,$fastbuffersversion)"
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi

    # Create doxygen information.
    # Generate the examples
    # CDR example
    ./scripts/efastbuffers.sh -replace -ser cdr -o utils/doxygen/examples/cdr utils/doxygen/examples/cdr/FooCdr.idl
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    # Fast CDR example
    ./scripts/efastbuffers.sh -replace -ser fastcdr -o utils/doxygen/examples/fastcdr utils/doxygen/examples/fastcdr/FooFastCdr.idl
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    #Export version
    export VERSION_DOX=$fastbuffersversion
    mkdir -p output
    mkdir -p output/doxygen
    doxygen utils/doxygen/doxyfile
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    # Compile the latex document
    cd output/doxygen/latex
    make
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    cd ../../../

    # Create installers
    cd utils/installers/linux
    ./setup_linux.sh $fastbuffersversion
    errorstatus=$?
    cd ../../..
    if [ $errorstatus != 0 ]; then return; fi

    # Remove the doxygen tmp directory
    rm -rf output
}

# Check that the environment.sh script was run.
if [ "$EPROSIMADIR" == "" ]; then
    echo "environment.sh must to be run."
    exit -1
fi

# Go to root
cd ../..

package

if [ $errorstatus == 0 ]; then
    echo "PACKAGING SUCCESSFULLY"
else
    echo "PACKAGING FAILED"
fi

exit $errorstatus
