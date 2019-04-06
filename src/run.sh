#! /bin/bash
source ~/.bashrc

# 인자로 수행할 파일을 기재하여야 함. 없으면 에러
if [[ -z $1 ]]
then
	echo "수행할 파일을 인자로 전달하여야 함!"
	exit 0 ;
fi


test=$1
echo "test: $test"


