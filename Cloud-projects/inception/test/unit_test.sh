
if [[ -z $@ ]]
then
	echo "testing from HOST"
	for file in test/test_modules_host/*
	do
		bash $file
	done
	echo "testing from GUEST"
	docker-compose -f test/test_modules_guest/docker-compose.yml up --build && docker-compose rm -fsv
else
	if [[ $1 = "GUEST" ]]
	then
		echo "testing from GUEST"
		docker-compose -f test/test_modules_guest/docker-compose.yml up --build && docker-compose rm -fsv
	else
		echo "testing from HOST"
		for file in test/test_modules_host/*
		do
			bash $file
		done
	fi
fi
