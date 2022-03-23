FROM alpine:3.15
RUN apk update
RUN apk add openrc
RUN rc-status
RUN touch /run/openrc/softlevel
RUN apk add mariadb mariadb-common mariadb-client
RUN /etc/init.d/mariadb setup
