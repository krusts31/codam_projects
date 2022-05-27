FROM alpine:3.15

RUN apk update && apk upgrade && apk add --no-cache \
        mariadb \
        mariadb-client
        
COPY install.sh /tmp/install.sh

CMD sh /tmp/install.sh
