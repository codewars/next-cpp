set KATA=%1
set IMAGE=cw-gtest-cpp
set WORKDIR=/code/
set CREATE_CMD=docker container create --rm -w %WORKDIR% %IMAGE% ./run-kata.sh

FOR /F %%i IN ('%CREATE_CMD%') DO set CONTAINER=%%i
docker cp ./kata_code/%KATA%/. %CONTAINER%:%WORKDIR%
docker start --attach -i %CONTAINER%
