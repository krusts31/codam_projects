FROM	alpine:latest

RUN	apk update && apk upgrade && apk add --no-cache \
	mariadb-client 

RUN mkdir /test_modules

COPY /test_modules/test_maraidb.sh /test_modules/test_maraidb.sh 

COPY unit_test.sh unit_test.sh

CMD ["/bin/sh", "unit_test.sh"]
