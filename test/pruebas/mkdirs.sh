#!/bin/sh
set -x

PATOS="pato13 pato23 pato33 pato43 pato53 pato63 pato73 pato83"

for PATO in $PATOS; do
	
	ssh $PATO mkdir -p /export/temp/$PATO/PNFS
	ssh $PATO chmod -R 777 /export/temp/$PATO/PNFS
	
done

