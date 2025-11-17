#!/bin/bash

MAP_DIR="maps/bad"
EXEC="./bin/cub3D"

for mapfile in "$MAP_DIR"/*.cub; do
    echo "Running map: $mapfile"
    $EXEC "$mapfile"
    status=$?
    if [ $status -ne 0 ]; then
        echo "Error detected while running $mapfile (exit code $status). Stopping execution."
        exit $status
    fi
    echo "Map $mapfile ran successfully."
    echo "--------------------------------"
done

echo "All maps ran successfully."

