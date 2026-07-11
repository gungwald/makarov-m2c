#!/bin/sh
# This is just documentation for the freaky commands that must be run to build
# rpm package. It is not necessarily meant to be run as a script.

# Download the upstream source archive specified in the spec file to the 
# SOURCES directory.
spectool -g -R ~/rpmbuild/SPECS/m2c.spec

# Build the source rpm.
rpmbuild -bs ~/rpmbuild/SPECS/m2c.spec

# Build the package from the original source.
rpmbuild --rebuild ~/rpmbuild/SRPMS/m2c-*.src.rpm

