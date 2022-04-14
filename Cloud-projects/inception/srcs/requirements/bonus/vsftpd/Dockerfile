FROM	alpine:3.15

RUN	apk add --no-cache vsftpd

EXPOSE 20 21

COPY	vsftpd.conf	/etc/vsftpd
COPY	setup_vsftpd.sh	.

CMD sh setup_vsftpd.sh

#VOLUME	["/sys/fs/cgroup"]
