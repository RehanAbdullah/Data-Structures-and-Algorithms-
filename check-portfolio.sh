#!/bin/bash
# Script: check-portfolio.sh
# Author: drs

# Script to check portfolio coursework files and build tape archive
# Run this script to check that the portfolio directory contains the correct files
#     before bundling it up.  The script will create the tar file for you.
# Put this in the directory ABOVE your portfolio directory

INFO="...."
OK="yes "
BAD="NO  "
FILES="portfolio/pfstack.c      \
         portfolio/pfqueue.c    \
         portfolio/pfpq.c       \
         portfolio/pfclist.c    \
         ds/clist/clist.c       \
         portfolio/pfbst.c      \
         portfolio/pfbst_char.h \
         portfolio/pfbst_char.c"

echo "$INFO Checking if portfolio dir exists at this level"
if [ -d portfolio ]; then
    echo "$OK portfolio exists"
else
    echo "$BAD portfolio does not exist"
    exit
fi
echo "$INFO Checking if ds dir exists at this level"
if [ -d ds ]; then
    echo "$OK ds exists"
else
    echo "$BAD ds does not exist"
    exit
fi

for f in $FILES; do
    echo "$INFO Checking if $f exists"
    if [ -f $f ]; then
        echo "$OK $f exists"
    else
        echo "$BAD $f does not exist"
        exit
    fi
done

if [ -f portfolio.tar ]; then
    echo "$INFO removing old tarfile"
    /bin/rm -rf portfolio.tar
fi
echo "$INFO building portfolio.tar ..."
if [ -d /tmp/portfolio ]; then
    /bin/rm -rf /tmp/portfolio
fi
mkdir /tmp/portfolio
cp $FILES /tmp/portfolio
cd /tmp
tar cvf portfolio.tar portfolio
cd -
mv /tmp/portfolio.tar .

# End of Script: check-portfolio.sh