FROM debian:stable

RUN apt-get update && apt-get install -y \
	vsftpd openssl \
	&& rm -rf /var/lib/apt/lists/*

EXPOSE 21

COPY ./vsftpd.conf /etc/vsftpd.conf
COPY ./ftp_setup.sh /usr/bin/ftp_setup.sh

RUN chmod +x /usr/bin/ftp_setup.sh

ENTRYPOINT [ "sh", "/usr/bin/ftp_setup.sh" ]