#!/bin/bash

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

source "${script_directory}/../setup.sh"

docker run \
       --name="${container_name}" \
       -it \
       --rm \
       --volume="${project_directory}:/${image_name}:rw" \
       --volume="/${image_name}/build" \
       --volume="${script_directory}/helpers/build.sh:/${image_name}/build/build.sh:ro" \
       --volume="${script_directory}/helpers/test.sh:/${image_name}/build/test.sh:ro" \
       --volume="${script_directory}/helpers/clean.sh:/${image_name}/build/clean.sh:ro" \
       --workdir="/${image_name}/build" \
       "${image_name}" \
       "/bin/bash"