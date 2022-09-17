#! /bin/sh

echo "sourcing geant4make.sh file"
source ~/Geant/Geant-src/geant4-v11.0.2-install/share/Geant4-11.0.2/geant4make/geant4make.sh
echo "============================================================>"
cd build 
echo "building cmake configs"
cmake .. 
echo "============================================================>"
echo "running make"
make 
echo "============================================================>"
echo "running executable"
./test
echo "============================================================>"
