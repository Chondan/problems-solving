fileName=$1
fileNameLen=${#fileName}
lastPos=`expr $fileNameLen - 4`
outputName="${fileName:0:$lastPos}"

g++ -std=c++11 $fileName -o $outputName