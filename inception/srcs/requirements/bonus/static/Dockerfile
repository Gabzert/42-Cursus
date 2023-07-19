FROM debian:stable

RUN apt-get update && apt-get install -y \
	nginx\
	&& rm -rf /var/lib/apt/lists/*

EXPOSE 8080

COPY static.conf /etc/nginx/conf.d

COPY web-data /tmp/web-data
COPY index.html /usr/share/nginx/html

RUN mv /tmp/web-data /usr/share/nginx/html/web-data


CMD ["nginx", "-g", "daemon off;"]