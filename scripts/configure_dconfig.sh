#!/bin/bash
# My first script

DCONFIG_OVERRIDES=(
                    "PROJECT_NAME           = \"DMath-Engine\""
                    "PROJECT_NUMBER         = \"1.0\""
                    "PROJECT_BRIEF          = \"DMath Engine provides a API for performing math operations.\""
                    "OUTPUT_DIRECTORY       = \"../docs\""
                  )

cd ../src
(   
    cat $HOME"/dconfig;" # Assume default configuration

    for i in "${DCONFIG_OVERRIDES[@]}"; do
    {
        if [[ ${DCONFIG_OVERRIDES[-1]} -ne "$i" ]]; then
        {
        echo "$i;"
        }
        else
        {
        echo "$i"
        }
        fi
    }
        done
) | doxygen -