#!/bin/bash

MAP_DIR="maps/bad"
EXEC="./bin/cub3D"

for mapfile in "$MAP_DIR"/*.cub; do
    echo "Trying map: $mapfile"
    $EXEC "$mapfile"
    status=$?
    if [ $status -eq 0 ]; then
        echo "Map $mapfile ran successfully. Stopping."
        exit 0
    else
        echo "Map $mapfile failed with exit code $status. Trying next map."
    fi
    echo "--------------------------------"
done

echo "No map in $MAP_DIR ran successfully."
exit 1

