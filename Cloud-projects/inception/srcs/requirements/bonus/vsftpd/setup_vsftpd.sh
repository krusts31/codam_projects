#!/bin/sh
# add a vsftpd user 
# chage the password since there is no way to pass the password for adduser
# use passwd -d
adduser $VSFPTD_USER --disabled-password
passwd $VSFPTD_USER -d $VSFPTD_PASSWORD

#create the home dir for ftp
#creat chjail for ftp so that opther dirs are not accsessible from 
#ftp server
mkdir /home/$VSFPTD_USER/ftp
chown nobody:nogroup /home/$VSFPTD_USER/ftp
chmod a-w /home/$VSFPTD_USER/ftp
mkdir /home/$VSFPTD_USER/ftp/files
chown $VSFPTD_USER:$VSFPTD_USER /home/$VSFPTD_USER/ftp/files

#add a user to ftp server
echo "$VSFPTD_USER" >> /etc/vsftpd.userlist

exec /usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf
