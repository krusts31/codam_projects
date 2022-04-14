FROM alpine:3.15

RUN apk update && apk upgrade

RUN apk add --no-cache \
  mariadb \
  mariadb-client

COPY install_start_mariadb.sh /home/.

# set's up mariaDB. Does a secure install
# Adds a Wordpress database and users

CMD sh /home/install_start_mariadb.sh
