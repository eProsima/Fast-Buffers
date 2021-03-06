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
    # Get current version of GCC. (Not more needed)
    #. $EPROSIMADIR/scripts/common_pack_functions.sh getGccVersion
    cd ../fastcdr
    # Get the current version of CDR
    . $EPROSIMADIR/scripts/common_pack_functions.sh getVersionFromCPP cdrversion include/fastcdr/FastCdr_version.h

    # Compile and packaging FastCDR library for all archictectures
    cd utils/scripts
    #./package_fastcdr.sh
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    cd ../../../FastBuffers

    # Get the current version of FastBuffers
    . $EPROSIMADIR/scripts/common_pack_functions.sh getVersionFromCPP fastbuffersversion src/version.cpp
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi

    # Try to add platform (No more needed).
    #setPlatform "i86Linux2.6gcc${gccversion}"
    #setPlatform "x64Linux2.6gcc${gccversion}"

    # Update and compile FastBuffers application.
    # Update FastBuffers application
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
    soffice --headless "macro:///eProsima.documentation.changeHyperlinksAndVersionToHTML($PWD/README.odt,$fastbuffersversion,./doc/,./)"
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi

    # Create doxygen information.
    # Generate the examples
    # CDR example
    ./scripts/fastbuffers_local.sh -replace -ser cdr -d utils/doxygen/examples/cdr utils/doxygen/examples/cdr/FooCdr.idl
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    # Fast CDR example
    ./scripts/fastbuffers_local.sh -replace -ser fastcdr -d utils/doxygen/examples/fastcdr utils/doxygen/examples/fastcdr/FooFastCdr.idl
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
    cd ../..
    if [ $errorstatus != 0 ]; then return; fi

    # Remove the doxygen tmp directory
    rm -rf output

    # Generate distribution
    distroName="FastBuffers"
    . $EPROSIMADIR/scripts/common_pack_functions.sh getDistroVersion
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    distro=`cat /etc/rpm/macros.dist  | grep %dist | cut -d. -f2`

    mkdir -p tmpRelease
    cp ~/rpmbuild/RPMS/i686/fastcdr-${cdrversion}-1.${distro}.i686.rpm tmpRelease
    cp ~/rpmbuild/RPMS/noarch/fastbuffers-${fastbuffersversion}-1.${distro}.noarch.rpm tmpRelease
    cp ~/rpmbuild/RPMS/x86_64/fastcdr-${cdrversion}-1.${distro}.x86_64.rpm tmpRelease

    cd tmpRelease
    tar cvzf "../installers/linux/eProsima_${distroName}-${fastbuffersversion}-${distroversion}.tar.gz" *
    errorstatus=$?
    if [ $errorstatus != 0 ]; then return; fi
    cd ..

    # Remove temp directory
    rm -rf tmpRelease
    cd ..
    rm -rf utils/installers/linux/tmp
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
